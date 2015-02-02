#ifndef INTROSTATE_H
#define INTROSTATE_H

#include "Game.h"
#include "GameState.h"
#include "Shader.h"
#include "Model.h"
#include "Input.h"


class IntroState : public GameState
{
    public:
        IntroState();
        void Init();
        void Update(Game *game);
        void Render();
        virtual ~IntroState();
    protected:
    private:
        Shader shader;
        Model background;
};

#endif // INTROSTATE_H
