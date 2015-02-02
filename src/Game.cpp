#include "Game.h"

Texture Fish::tex1;
Texture Fish::tex2;

Game::Game()
{
    //ctor
}

void Game::Init()
{
    std::cout << "Initializing Game\n";
    isRunning = true;
    gameState = new IntroState();
    gameState->Init();
    Fish::tex1.Setup("res/textures/fish.png");
    Fish::tex2.Setup("res/textures/fishr.png");
}

void Game::Update()
{
    gameState->Update(this);
}

void Game::Render()
{
    gameState->Render();
}

bool Game::IsRunning()
{
    return isRunning;
}

void Game::ChangeState(int state)
{
    delete gameState;

    if(state == INTRO)
    {
        gameState = new IntroState();
        gameState->Init();
    }
    if(state == PLAY)
    {
        gameState = new PlayState();
        gameState->Init();
    }
}

Game::~Game()
{
    delete gameState;
}
