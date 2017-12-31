#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Button
{
    public:
        Button();
        void draw();
        bool isPressed();

        static sf::Texture texReleased;
        static sf::Texture texPressed;
        static sf::Font font;

        // Getter
        int getX() const;
        int getY() const;
        int getWidth() const;
        int getHeight() const;

        // Setters
        void setPosition(int x, int y);
        void setTextPosition(int textX, int textY);
        void setTextCenter();
        void setText(string text);

    private:
        static bool isInit;
        int nowSprite;
        int x, y;
        int textX, textY;

        sf::Sprite spr;
        sf::Text textObj;

};

#endif // BUTTON_H
