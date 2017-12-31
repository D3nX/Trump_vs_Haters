#include "MenuState.h"
#include "Game.h"

MenuState::MenuState()
{
    button[0].setText("start");
    button[1].setText("exit");

    int y = 150;

    for (int i = 0; i < 2; i++)
    {
        button[i].setTextCenter();
        button[i].setPosition((Game::WIDTH - button[i].getWidth()) / 2, button[i].getY() + y);

        y += 100;
    }

    // Set text
    text.setFont(Game::font);
    text.setString("Trump vs Haters");
    text.setColor(sf::Color::Black);
    text.setScale(2.0f, 2.0f);
    text.setPosition(100, 10);
}

MenuState::~MenuState()
{

}

void MenuState::update(sf::Event &event)
{
    if (button[0].isPressed())
        Game::current_state = 1;

    if (button[1].isPressed())
        Game::window->close();
}

void MenuState::draw()
{
    infBg.draw();

    for (int i = 0; i < 2; i++)
    {
        button[i].draw();
    }

    Game::window->draw(text);

}

void MenuState::reset()
{

}
