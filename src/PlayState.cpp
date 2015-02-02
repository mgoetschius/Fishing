#include "PlayState.h"

#include <ctime>

PlayState::PlayState()
{
    //ctor
}

void PlayState::Init()
{
    srand(time(0));
    shader.Setup("res/shaders/vertexshader.vs", "res/shaders/fragmentshader.fs");
    background.Setup(shader, string("background"));
    background.SetScale(glm::vec3(1,1,1));
    background.update(0);
    boat.Setup(shader);
    numCaught = 0;

    for(unsigned int i = 0; i < 5; i++)
    {
        addFish();
    }

    for(unsigned int i = 0; i < entities.size(); i++)
    {
        entities[i]->update(boat);
    }
}

void PlayState::Update(Game *game)
{
    if(Input::getKey(Input::KEY_Z))
    {
        game->ChangeState(1);
    }
    else
    {
        for(std::vector<Fish*>::iterator i = entities.begin(); i != entities.end(); )
        {
             if((*i)->GetXPos() > 1 + (*i)->GetScale().x)
            {
                delete *i;
                i = entities.erase(i);
                addFish();
            }
            else if((*i)->GetXPos() < -1 - (*i)->GetScale().x)
            {
                delete *i;
                i = entities.erase(i);
                addFish();
            }
            else if ((*i)->GetRemoveFish())
            {
                delete *i;
                i = entities.erase(i);
                addFish();
                boat.SetFishHooked(false);
            }
            else ++i;
        }
        for(unsigned int i = 0; i < entities.size(); i++)
        {
            entities[i]->update(boat);
        }

        boat.update();

         /********************************************************
        *   Check Collision
        *********************************************************/

        if(!boat.GetFishHooked())
        {
            float hookMinX = boat.GetHookXPos() - boat.GetHookScale().x;
            float hookMaxX = boat.GetHookXPos() + boat.GetHookScale().x;
            float hookMinY = boat.GetHookYPos() - boat.GetHookScale().y;
            float hookMaxY = boat.GetHookYPos() + boat.GetHookScale().y;


            for(unsigned int i = 0; i < entities.size(); i++)
            {
                Fish * f = static_cast<Fish*> (entities[i]);

                float fishMinX = f->GetBoxMinX();
                float fishMaxX = f->GetBoxMaxX();
                float fishMinY = f->GetBoxMinY();
                float fishMaxY = f->GetBoxMaxY();

                if(   fishMinX < hookMaxX && fishMaxX > hookMinX
                   && fishMinY < hookMaxY && fishMaxY > hookMinY)
                {
                    f->IsCaught(true);
                    if(f->GetXSpeed() < 0)
                        f->SetXPos(boat.GetHookXPos() + f->GetScale().x - .02);
                    else
                        f->SetXPos(boat.GetHookXPos() - f->GetScale().x);
                    boat.SetFishHooked(true);
                    numCaught++;
                    ap.play(1);
                }
            }
        }
    }
}

void PlayState::Render()
{
    shader.bind();
    background.render();
    boat.render();


    for(std::vector<Fish*>::iterator it = entities.begin(); it != entities.end(); it++)
    {
        (*it)->render();
    }
    std::ostringstream ss;
    ss << numCaught;
    tr.renderText(ss.str(), Game::windowWidth - ss.str().length()*20 -5, Game::windowHeight - 25, 20, Game::windowWidth, Game::windowHeight);
}

PlayState::~PlayState()
{
    for(std::vector<Fish*>::iterator it = entities.begin(); it != entities.end(); it++)
    {
        delete (*it);
    }
    entities.clear();
}

void PlayState::addFish()
{
    if(rand() % 2 == 0)
    {
        float s = getRand(0.05, 0.15);
        float y = getRand(-.8+s, .25-s);
        float xSpeed = getRand(0.005f, 0.006f)*-1;
        entities.push_back(new Fish(shader, 1.0, y, xSpeed, 0.0, s, "fish"));
    }
    else
    {
        float s = getRand(0.05f, 0.15f);
        float y = getRand(-0.8f+s, 0.25f-s);
        float xSpeed = getRand(0.005f, 0.006f);
        entities.push_back(new Fish(shader, -1.0, y, xSpeed, 0.0, s, "fishr"));
    }


}
float PlayState::getRand(float a, float b)
{
    return ((b-a)*((float)rand()/RAND_MAX))+a;
}
