#include "InvicibleBox.h"
#include "Game.h"

InvicibleBox::InvicibleBox()
{
    tex.loadFromFile("res/metal_box.png");
    spr.setTexture(tex);

    speed = 4.0f;

    reset();
}

InvicibleBox::~InvicibleBox() {}


void InvicibleBox::draw()
{
    spr.setPosition(spr.getPosition().x - speed, spr.getPosition().y);

    if (spr.getPosition().x + spr.getTexture()->getSize().x < 0)
    {
        reset();
    }

    intRect = (sf::IntRect)spr.getGlobalBounds();

    Game::window->draw(spr);
}

void InvicibleBox::reset()
{
    speed = 4.0f;
    spr.setPosition(Game::WIDTH + 500 + rand() % 1000, rand() % Game::HEIGHT);
}

sf::IntRect InvicibleBox::getIntRect() const
{
    return intRect;
}

void InvicibleBox::addSpeed(float speed)
{
    this->speed += speed;
}
