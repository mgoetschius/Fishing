#include "Boat.h"

Boat::Boat()
    : Entity()
{
    //ctor
}

void Boat::Setup(Shader shader)
{
    isCasting = false;
    std::string name = "boat";
    model.Setup(shader, name);
    model.SetScale(glm::vec3(0.25, 0.25, 0.25));
    xPos = 0.0;
    yPos = 0.78;
    xSpeed = 0.01;
    ySpeed = 0;

    name = "line";
    line.Setup(shader, name);
    line.SetScale(glm::vec3(.002,.05,1));
    lineXPos = xPos;
    lineYPos = yPos - line.GetScale().y;

    name = "hook";
    hook.Setup(shader, name);
    hook.SetScale(glm::vec3(.03, .03, 1));
    hookXPos = lineXPos;
    hookYPos = lineYPos - line.GetScale().y - hook.GetScale().y;
}

void Boat::update()
{
    if(!isCasting && Input::getKey(Input::KEY_D) && xPos < 1 - model.GetScale().x)
    {
        xPos += xSpeed;
        lineXPos = xPos;
        hookXPos = lineXPos;
    }
    if(!isCasting && Input::getKey(Input::KEY_A) && xPos > -1 + model.GetScale().x)
    {
        xPos -= xSpeed;
        lineXPos = xPos;
        hookXPos = lineXPos;
    }
    if(Input::getKey(Input::KEY_S) && !fishHooked)
    {
        isCasting = true;
        if(line.GetScale().y < .75)
        {
            line.SetScale(glm::vec3(.002, line.GetScale().y + .01, 1));
            lineYPos = yPos - line.GetScale().y;
            hookYPos = lineYPos - line.GetScale().y - hook.GetScale().y;;
        }

    }
    if( line.GetScale().y > .05)
    {
        line.SetScale(glm::vec3(.002, line.GetScale().y - .005, 1));
        lineYPos = yPos - line.GetScale().y;
        hookYPos = lineYPos - line.GetScale().y - hook.GetScale().y;;
    }

    if(isCasting and line.GetScale().y <= .05)
    {
        isCasting = false;
    }

    model.SetTranslation(glm::vec3(xPos, yPos, 0.0));
    model.update(0);
    line.SetTranslation(glm::vec3(lineXPos, lineYPos, 0.0));
    line.update(0);
    hook.SetTranslation(glm::vec3(hookXPos, hookYPos, 0.0));
    hook.update(0);
}

void Boat::render()
{
    model.render();
    line.render();
    hook.render();
}

Boat::~Boat()
{
    //dtor
}
