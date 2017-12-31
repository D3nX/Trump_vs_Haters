#include "Trump.h"
#include "Game.h"

Trump::Trump()
{
    texTrump.loadFromFile("res/trump.png");
    texMetalTrump.loadFromFile("res/metal_trump.png");

    spr.setTexture(texTrump);

    life = 5;

    speed = 4.0f;

    invicibility = false;

}

Trump::~Trump()
{
    //dtor
}

void Trump::update(sf::Event &event)
{
    // Right or Left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && spr.getPosition().x > 0)
        spr.setPosition(spr.getPosition().x - speed, spr.getPosition().y);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && spr.getPosition().x + (int)texTrump.getSize().x < Game::WIDTH)
        spr.setPosition(spr.getPosition().x + speed, spr.getPosition().y);

    // Up or Down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && spr.getPosition().y > 0)
        spr.setPosition(spr.getPosition().x, spr.getPosition().y - speed);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && spr.getPosition().y + (int)texTrump.getSize().y < Game::HEIGHT)
        spr.setPosition(spr.getPosition().x, spr.getPosition().y + speed);

    // Synchronize rectangle position with Trump
    rect = (sf::IntRect)spr.getGlobalBounds();

    // Set Metal Trump to normal Trump when time finished
    if (invicibility)
    {
        time = clock.getElapsedTime();

        if (time.asSeconds() >= 5.0f)
        {
            time = time.Zero;
            clock.restart();
            invicibility = false;
            spr.setTexture(texTrump);
            spr.setColor(sf::Color::White);
        }
    }
}

void Trump::draw()
{
    Game::window->draw(spr);
}

bool Trump::isInvincible() const
{
    return invicibility;
}

void Trump::setInvisibility(bool enableMetalTrump)
{
    invicibility = true;

    clock.restart();

    time = time.Zero;

    if (enableMetalTrump)
        spr.setTexture(texMetalTrump);
    else
        spr.setColor(sf::Color(255, 255, 255, 128));
}

void Trump::setLife(int life)
{
    this->life = life;
}

void Trump::addSpeed(float speed)
{
    this->speed += speed;
}

void Trump::reset()
{
    speed = 4.0f;
    spr.setPosition(0, 0);
    life = 5;
    invicibility = false;
    spr.setTexture(texTrump);
    spr.setColor(sf::Color::White);
}

bool Trump::collides(sf::IntRect rect)
{
    sf::IntRect result;
    return this->rect.intersects(rect, result);
}

int Trump::getLife() const
{
    return life;
}
