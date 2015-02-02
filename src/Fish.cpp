#include "Fish.h"

Fish::Fish(Shader shader, float xPosition, float yPosition, float XSpeed, float YSpeed, float scale, std::string name)
    : Entity()
{
    caught = false;
    removeFish = false;

    model.Setup(shader, name);
    model.SetScale(glm::vec3(scale, scale, 1.0f));
    xPos = xPosition;
    yPos = yPosition;
    xSpeed = XSpeed;
    ySpeed = YSpeed;

    boxYPos = yPos;
    boxMaxY = boxYPos + .01;
    boxMinY = boxYPos - .01;
    if(xSpeed > 0)
        boxXPos = xPos + model.GetScale().x;

    else
        boxXPos = xPos - model.GetScale().x;

    boxMaxX = boxXPos + .01;
    boxMinX = boxXPos - .01;
}

void Fish::update(Boat & boat)
{
    if(!caught)
    {
        xPos += xSpeed;
        yPos += sin((glfwGetTime()-startTime)*4)/500;
    }

    if(caught)
    {
        yPos = boat.GetHookYPos();
        if(xSpeed < 0)
        {
            if(model.GetRotationAmount() > -90)
                model.SetRotationAmount(model.GetRotationAmount()-1);
        }
        if(xSpeed > 0)
        {
            if(model.GetRotationAmount() < 90)
                model.SetRotationAmount(model.GetRotationAmount()+1);
        }

        if(yPos > .64)
        {
            removeFish = true;
        }
    }

    model.SetTranslation(glm::vec3(xPos, yPos, 0.0));
    model.update(xSpeed);
    if(xSpeed > 0)
        boxXPos = xPos + model.GetScale().x;
    else
        boxXPos = xPos - model.GetScale().x;
    boxYPos = yPos;
    boxMaxY = boxYPos + .01;
    boxMinY = boxYPos - .01;
    boxMaxX = boxXPos + .01;
    boxMinX = boxXPos - .01;
}

void Fish::render()
{
    model.render();
}

Fish::~Fish()
{
    //dtor
}
