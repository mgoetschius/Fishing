#ifndef FISH_H
#define FISH_H

#include <Entity.h>
#include "Boat.h"
#include "Texture.h"


class Fish : public Entity
{
    public:
        static Texture tex1;
        static Texture tex2;
        Fish(Shader shader, float xPosition, float yPosition, float XSpeed, float YSpeed, float scale, std::string name);
        void update(Boat& boat);
        void render();
        void IsCaught(bool val) {caught = val;};
        bool GetRemoveFish() {return removeFish;};
        virtual ~Fish();
    protected:
    private:
        bool caught;
        bool removeFish;
};

#endif // FISH_H
