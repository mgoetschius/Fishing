#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "Game.h"
#include "GameState.h"
#include "Shader.h"
#include "Model.h"
#include "Input.h"
#include "Boat.h"
#include "TextRenderer.h"
#include "AudioPlayer.h"
#include "Fish.h"


class PlayState : public GameState
{
    public:
        PlayState();
        void Init();
        void Update(Game *game);
        void Render();
        virtual ~PlayState();
    protected:
    private:
        Shader shader;
        Model background;
        Boat boat;
        TextRenderer tr;
        AudioPlayer ap;
        std::vector<Fish*> entities;
        unsigned int numCaught;
        void addFish();
        float getRand(float a, float b);
};

#endif // PLAYSTATE_H
