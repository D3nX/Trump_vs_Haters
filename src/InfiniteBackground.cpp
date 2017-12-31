#include "InfiniteBackground.h"
#include <iostream>
#include "Game.h"

using namespace std;

InfiniteBackground::InfiniteBackground()
{
    texBack.loadFromFile("res/background.png");

    speed = 4.0f;

    int x = -texBack.getSize().x;

    for (int i = 0; i < 2; i++)
    {
        sprBack[i].setTexture(texBack);
        sprBack[i].setPosition(x, 0);

        x += texBack.getSize().x;
    }
}

InfiniteBackground::~InfiniteBackground()
{

}

void InfiniteBackground::draw()
{

    for (int i = 0; i < 2; i++)
    {
        Game::window->draw(sprBack[i]);

        sprBack[i].setPosition(sprBack[i].getPosition().x - speed, 0);

        if (sprBack[i].getPosition().x + (int)texBack.getSize().x < 0)
        {
            sprBack[i].setPosition((int)texBack.getSize().x, 0);
        }
    }
}

void InfiniteBackground::addSpeed(float speed)
{
    this->speed += speed;
}

void InfiniteBackground::resetSpeed()
{
    speed = 4.0f;
}
