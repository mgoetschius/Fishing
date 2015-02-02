#include "Entity.h"
#include <math.h>
#include <ctime>

Entity::Entity()
{

}

void Entity::Setup(Shader shader, float xPosition, float yPosition, float XSpeed, float YSpeed, float scale, std::string name)
{
    model.Setup(shader, name);
    model.SetScale(glm::vec3(scale, scale, 1.0f));
    xPos = xPosition;
    yPos = yPosition;
    xSpeed = XSpeed;
    ySpeed = YSpeed;
}
void Entity::update()
{
    xPos += xSpeed;
    yPos += ySpeed;       //4 number of times up and down  500 amplitude
    model.SetTranslation(glm::vec3(xPos, yPos, 0.0));
    model.update(xSpeed);
}

void Entity::render()
{
    model.render();
}

Entity::~Entity()
{
    //dtor
}
