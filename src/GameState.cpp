#include "GameState.h"
#include "Game.h"

GameState::GameState()
{
    text.setFont(Game::font);
    text.setPosition(12, -5);
    text.setScale(1.1f, 1.1f);
    text.setColor(sf::Color::Black);

    gameOverText.setFont(Game::font);
    gameOverText.setPosition(120, 180);
    gameOverText.setScale(3.0f, 3.0f);
    gameOverText.setColor(sf::Color::Red);
    gameOverText.setString("Game Over");

    button.setText("Replay");
    button.setTextCenter();
    button.setPosition((Game::WIDTH - button.getWidth()) / 2, Game::HEIGHT - button.getHeight() - 50);

    hatersNmb = 3;

    speed = 0.0f;

    distance = 0;

    music.openFromFile("res/Kizunami - Kill All The Memes [HQ].ogg");

    punchSoundBuffer.loadFromFile("res/punch.ogg");
    punchSound.setBuffer(punchSoundBuffer);
}

GameState::~GameState()
{

}

void GameState::update(sf::Event &event)
{
    time = clock.getElapsedTime();
    if (trump.getLife() > 0)
    {
        distance += 1;

        if (time.asSeconds() >= 2.0f && speed <= 1.2f)
        {
            speed += 0.01f;

            trump.addSpeed(speed);

            for (int i = 0; i < hatersNmb; i++)
            {
                hater[i].addSpeed(speed);
            }

            box.addSpeed(speed);

            infBg.addSpeed(speed);

            time = time.Zero;
            clock.restart();
        }

        if (music.getStatus() == sf::SoundStream::Stopped)
        {
            music.play();
            music.setLoop(true);
        }

        trump.update(event);

        if (trump.collides(box.getIntRect()) && !trump.isInvincible())
        {
            trump.setInvisibility(true);
            box.reset();
        }

        for (int i = 0; i < hatersNmb; i++)
        {
            if (trump.collides(hater[i].getIntRect()) && !trump.isInvincible())
            {
                trump.setInvisibility(false);
                if (trump.getLife() > 0)
                    trump.setLife(trump.getLife() - 1);

                punchSound.play();
            }
        }

        text.setString("Life: " + Game::toStr(trump.getLife()) + "\n\n\n\n\n\n\n\n\n\n\nDistance: " + Game::toStr(distance) + " meters");
    }
    else
    {
        if (button.isPressed())
            reset();
    }
}

void GameState::draw()
{
    infBg.draw();
    trump.draw();
    box.draw();

    for (int i = 0; i < hatersNmb; i++)
        hater[i].draw();

    Game::window->draw(text);

    if (trump.getLife() < 1)
    {
        Game::window->draw(gameOverText);
        button.draw();
    }
}

void GameState::reset()
{
    time = time.Zero;
    clock.restart();

    music.stop();

    box.reset();

    for (int i = 0; i < hatersNmb; i++)
        hater[i].reset();

    trump.reset();

    infBg.resetSpeed();

    distance = 0;
}
