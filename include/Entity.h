#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "Model.h"
#include "Shader.h"
#include <glm/vec3.hpp>
#include <GL/glfw3.h>


class Entity
{
    public:
        Entity();
        virtual void Setup(Shader shader, float xPosition, float yPosition, float xSpeed, float ySpeed, float scale, std::string name);
        virtual void update();
        virtual void render();
        virtual ~Entity();
        float GetXPos() {return xPos;};
        float GetYPos() {return yPos;};
        glm::vec3 GetScale() {return model.GetScale();};
        float GetXSpeed() {return xSpeed;};
        void SetXPos(float XPos) {xPos = XPos;};

        float GetBoxMaxX() {return boxMaxX;};
        float GetBoxMaxY() {return boxMaxY;};
        float GetBoxMinX() {return boxMinX;};
        float GetBoxMinY() {return boxMinY;};
    protected:
        Model model;
        float xPos, yPos;
        float xSpeed, ySpeed;
        float startTime = glfwGetTime();

        float boxXPos;
        float boxYPos;
        float boxMinX, boxMinY, boxMaxX, boxMaxY;
    private:

};

#endif // ENTITY_H
