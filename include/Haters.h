#ifndef HATERS_H
#define HATERS_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Haters
{
    public:
        Haters();
        virtual ~Haters();
        void draw();
        sf::IntRect getIntRect() const;
        void addSpeed(float speed);
        void reset();

        static sf::Texture *tex;
        static std::string *hashtags;
        static bool initialized;
        static float speed;

    private:
        sf::Sprite spr;
        sf::IntRect intRect;
        sf::Text text;
        std::string ht;
        float m_speed;

};

#endif // HATERS_H
