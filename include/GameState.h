#ifndef GAMESTATE_H
#define GAMESTATE_H

class Game;

class GameState
{
    public:
        GameState();
        virtual void Init() = 0;
        virtual void Update(Game *game) = 0;
        virtual void Render() = 0;
        virtual ~GameState();
    protected:
    private:
};

#endif // GAMESTATE_H
