#include "Button.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace std;
using namespace sf;

Texture Button::texPressed = Texture();
Texture Button::texReleased = Texture();
Font Button::font = Font();
bool Button::isInit = false;

Button::Button()
{
    if (!isInit)
    {
        texReleased.loadFromFile("res/button_normal.png");
        texPressed.loadFromFile("res/button_selected.png");
        font.loadFromFile("res/Starjhol.ttf");

        isInit = true;
    }


    nowSprite = 0;

    x = 0;
    y = 0;

    textX = 0;
    textY = 0;

    spr = Sprite();
    spr.setTexture(texReleased);

    textObj = Text();
    textObj.setFont(font);
    textObj.setString("No TEXT");
}

bool Button::isPressed()
{
    if (sf::Mouse::getPosition(*Game::window).x >= spr.getPosition().x &&
        sf::Mouse::getPosition(*Game::window).x <= spr.getPosition().x + spr.getGlobalBounds().width &&
        sf::Mouse::getPosition(*Game::window).y >= spr.getPosition().y &&
        sf::Mouse::getPosition(*Game::window).y <= spr.getPosition().y + spr.getGlobalBounds().height)
    {
        if (nowSprite != 1)
        {
            spr.setTexture(texPressed);
            nowSprite = 1;
        }

        if (Game::event.type == sf::Event::MouseButtonPressed)
        {
            spr.setTexture(texReleased);
            nowSprite = 0;

            return true;
        }
    }
    else
    {
        if (nowSprite != 0)
        {
            spr.setTexture(texReleased);
            nowSprite = 0;
        }
    }

    return false;
}

void Button::draw()
{
    textObj.setPosition(textX + x, textY + y);

    Game::window->draw(spr);
    Game::window->draw(textObj);
}

// Setters
void Button::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
    spr.setPosition(this->x, this->y);
}

void Button::setTextPosition(int textX, int textY)
{
    this->textX = textX;
    this->textY = textY;
}

void Button::setText(string text)
{
    textObj.setString(text);
}

void Button::setTextCenter()
{
    textX = spr.getGlobalBounds().width / 2 - textObj.getLocalBounds().width / 2;
    textY = 15;
    textObj.setPosition(textX, textY);
}

// Getters
int Button::getX() const
{
    return spr.getPosition().x;
}

int Button::getY() const
{
    return spr.getPosition().y;
}

int Button::getWidth() const
{
    return spr.getGlobalBounds().width;
}

int Button::getHeight() const
{
    return spr.getGlobalBounds().height;
}
