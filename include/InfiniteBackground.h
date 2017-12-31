#ifndef INFINITEBACKGROUND_H
#define INFINITEBACKGROUND_H

#include <SFML/Graphics.hpp>

class InfiniteBackground
{
    public:
        InfiniteBackground();
        virtual ~InfiniteBackground();
        void draw();
        void addSpeed(float speed);
        void resetSpeed();

    private:
        sf::Texture texBack;
        sf::Sprite sprBack[2];
        float speed;
};

#endif // INFINITEBACKGROUND_H
