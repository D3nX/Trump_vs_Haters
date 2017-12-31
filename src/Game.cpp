#include "Game.h"
#include <sstream>

int Game::WIDTH = 640;
int Game::HEIGHT = 480;
int Game::current_state = 0;
sf::Font Game::font = sf::Font();
sf::RenderWindow* Game::window = new sf::RenderWindow(sf::VideoMode(Game::WIDTH, Game::HEIGHT), "Trump vs Haters");
sf::Event Game::event = sf::Event();

Game::Game()
{
    // Load font
    font.loadFromFile("res/DESIB.ttf");
}

Game::~Game()
{

}

void Game::update()
{
    switch (current_state)
    {
        case 0:
            menuState.update(event);
            break;

        case 1:
            gameState.update(event);
            break;
    }
}

void Game::draw()
{
    switch (current_state)
    {
        case 0:
            menuState.draw();
            break;

        case 1:
            gameState.draw();
            break;
    }
}

void Game::run()
{
    window->setFramerateLimit(60);
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

            this->event = event;
        }

        window->clear();
        update();
        draw();
        window->display();
    }
}

string Game::toStr(int input)
{
   stringstream stream;
   string output;

   stream << input;
   stream >> output;

   return output;

}
