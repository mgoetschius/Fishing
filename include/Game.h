#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "GameState.h"
#include "IntroState.h"
#include "PlayState.h"
#include "Fish.h"

enum GameStates
{
    NO_STATE,
    INTRO,
    PLAY
};


class Game
{
    public:
        Game();
        void Init();
        void Update();
        void Render();
        bool IsRunning();
        void ChangeState(int state); // make some sort of enum type thing
        virtual ~Game();
        static int windowWidth;
        static int windowHeight;
    protected:
    private:
        bool isRunning;
        GameState *gameState;
};

#endif // GAME_H
