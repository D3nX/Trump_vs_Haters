#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <SFML/Graphics.hpp>
#include "InfiniteBackground.h"
#include "Button.h"

class MenuState
{
    public:
        MenuState();
        ~MenuState();
        void update(sf::Event &event);
        void draw();
        void reset();

    private:
        InfiniteBackground infBg;
        Button button[2];
        sf::Text text;
};

#endif // MENUSTATE_H
