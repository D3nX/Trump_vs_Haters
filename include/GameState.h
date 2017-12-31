#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "InfiniteBackground.h"
#include "InvicibleBox.h"
#include "Button.h"
#include "Trump.h"
#include "Haters.h"

class GameState
{
    public:
        GameState();
        virtual ~GameState();
        void update(sf::Event &event);
        void draw();
        void reset();

    private:
        int hatersNmb;
        int distance;
        float speed;

        InfiniteBackground infBg;
        Trump trump;
        Haters hater[3];
        InvicibleBox box;

        Button button;

        sf::Clock clock;
        sf::Time time;

        sf::Text text, gameOverText;
        sf::Music music;

        sf::SoundBuffer punchSoundBuffer;
        sf::Sound punchSound;
};

#endif // GAMESTATE_H
