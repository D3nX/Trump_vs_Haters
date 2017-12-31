#include "Haters.h"
#include "Game.h"
#include <time.h>

sf::Texture* Haters::tex = new sf::Texture[3];
std::string* Haters::hashtags = new std::string[6];
bool Haters::initialized = false;
float Haters::speed = 5.0f;

Haters::Haters()
{
    if (!initialized)
    {
        for (int i = 0; i < 3; i++)
            tex[i].loadFromFile("res/hater_" + Game::toStr(i) + ".png");

        hashtags[0] = "#YouAreBad!";
        hashtags[1] = "#VoteHillaryClinton!";
        hashtags[2] = "#LongLiveMexican!";
        hashtags[3] = "#TrumpTheBestDumbassEver";
        hashtags[4] = "#F**KTRUMP!!!";
        hashtags[5] = "#H.C.TheBest!";

        ht = hashtags[rand() % 6];

        initialized = true;
    }

    text.setFont(Game::font);
    text.setString(ht);
    text.setScale(0.8f, 0.8f);
    text.setColor(sf::Color(255, 64, 64));

    spr.setTexture(tex[rand() % 3]);
    spr.setPosition(Game::WIDTH + 10, rand() % Game::HEIGHT);

    m_speed = (rand() % 20) / 10.0f;
}

Haters::~Haters()
{

}

void Haters::draw()
{
    spr.setPosition(spr.getPosition().x - speed - m_speed, spr.getPosition().y);

    if (spr.getPosition().x + spr.getTexture()->getSize().x < 0)
    {
        reset();
    }

    intRect = (sf::IntRect)spr.getGlobalBounds();

    text.setPosition(spr.getPosition().x, spr.getPosition().y + 120);

    Game::window->draw(spr);
    Game::window->draw(text);
}

sf::IntRect Haters::getIntRect() const
{
    return intRect;
}

void Haters::addSpeed(float speed)
{
    m_speed += speed;
}

void Haters::reset()
{
    m_speed = (rand() % 20) / 10.0f;

    spr.setPosition(Game::WIDTH + 10, rand() % Game::HEIGHT);

    text.setString(hashtags[rand() % 6]);

    spr.setTexture(tex[rand() % 3]);

    while (text.getString() == ht)
    {
        text.setString(hashtags[rand() % 6]);
    }

    ht = text.getString();
}
