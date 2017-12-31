#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "MenuState.h"
#include "GameState.h"

class Game
{
    public:
        Game();
        virtual ~Game();
        void update();
        void draw();
        void run();

        static string toStr(int input);

        static int WIDTH, HEIGHT;
        static int current_state;
        static sf::RenderWindow *window;
        static sf::Event event;
        static sf::Font font;

    private:
        MenuState menuState;
        GameState gameState;

};

#endif // GAME_H
