#ifndef BOAT_H
#define BOAT_H

#include <Entity.h>
#include <Shader.h>
#include <Input.h>
#include <string>


class Boat : public Entity
{
    public:
        Boat();
        void Setup(Shader Shader);
        void update();
        void render();
        virtual ~Boat();
        float GetHookXPos() { return hookXPos;};
        float GetHookYPos() { return hookYPos;};
        glm::vec3 GetHookScale() { return hook.GetScale();};
        bool GetFishHooked() {return fishHooked;};
        void SetFishHooked(bool val) {fishHooked = val;};
    protected:
    private:
        Model line;
        Model hook;
        float lineXPos, lineYPos;
        float hookXPos, hookYPos;
        bool fishHooked;
        bool isCasting;
};

#endif // BOAT_H
