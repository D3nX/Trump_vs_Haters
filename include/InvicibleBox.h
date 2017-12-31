#ifndef INVICIBLEBOX_H
#define INVICIBLEBOX_H

#include <SFML/Graphics.hpp>

class InvicibleBox
{
    public:
        InvicibleBox();
        virtual ~InvicibleBox();
        sf::IntRect getIntRect() const;
        void draw();
        void reset();
        void addSpeed(float speed);

    private:
        sf::Texture tex;
        sf::Sprite spr;
        sf::IntRect intRect;

        float speed;
};

#endif // INVICIBLEBOX_H
