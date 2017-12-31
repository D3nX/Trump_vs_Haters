#ifndef TRUMP_H
#define TRUMP_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Trump
{
    public:
        Trump();
        virtual ~Trump();
        void update(sf::Event &event);
        void draw();
        void reset();
        void setInvisibility(bool enableMetalTrump);
        void setLife(int life);
        void addSpeed(float speed);

        bool collides(sf::IntRect rect);
        bool isInvincible() const;

        int getLife() const;

    private:
        sf::Texture texTrump, texMetalTrump;
        sf::Sprite spr;
        sf::IntRect rect;
        sf::Clock clock;
        sf::Time time;
        float speed;
        bool invicibility;
        int life;

};

#endif // TRUMP_H
