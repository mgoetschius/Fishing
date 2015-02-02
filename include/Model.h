#ifndef MODEL_H
#define MODEL_H

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>

#include "Mesh.h"
#include "Shader.h"

class Model
{
    public:
        Model();
        void Setup(Shader & shade, bool left);
        void Setup(Shader &shader, int index);
        void Setup(Shader &shader, std::string name);
        void update(float speed);
        void render();
        void SetScale(glm::vec3 s) {scale = s;};
        glm::vec3 GetScale() {return scale;};
        float GetRotationAmount() {return rotationAmount;};
        void SetRotationAmount(float val) {rotationAmount = val;};
        void SetTranslation(glm::vec3 trans) {translation = trans;};
        void SetRotation(glm::vec3 rot) {rotation = rot;};
        glm::vec3 GetTranslation() {return translation;};
        virtual ~Model();
    protected:
        void getMesh(int index);
        void getMesh(std::string name);
        Mesh mesh;
        glm::vec3 translation;
        glm::vec3 rotation;
        glm::vec3 scale;
        glm::mat4 transMatrix;
        GLuint transUniform;
        float xSpeed, ySpeed;
        float xPos, yPos;
        float rotationAmount;
    private:

};

#endif // MODEL_H
