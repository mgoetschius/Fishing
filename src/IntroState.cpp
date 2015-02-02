#include "IntroState.h"

IntroState::IntroState()
{
    //ctor
}

void IntroState::Init()
{
    shader.Setup("res/shaders/vertexshader.vs", "res/shaders/fragmentshader.fs");
    background.Setup(shader, string("startscreen"));
    background.SetScale(glm::vec3(1,1,1));
    background.update(0);
}

void IntroState::Update(Game *game)
{
    if(Input::getKey(Input::KEY_P))
        game->ChangeState(2);
}

void IntroState::Render()
{
    shader.bind();
    background.render();
}

IntroState::~IntroState()
{
    //dtor
}
