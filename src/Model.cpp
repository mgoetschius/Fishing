#include "Model.h"
#include "Vertex.h"
#include "Texture.h"
#include "Fish.h"
#include <vector>
#include <string>

Model::Model()
{
    //ctor
}

void Model::Setup(Shader &shader, std::string name)
{
    getMesh(name);
    transUniform = glGetUniformLocation(shader.program, "transMatrix");

    translation = glm::vec3(0.0f, 0.0f, 0.0f);
    rotation = glm::vec3(0.0, 0.0, 1.0);
    scale = glm::vec3(0.0,0.0,0.0);
    rotationAmount = 0;

    transMatrix = glm::translate(transMatrix, translation);
    transMatrix = glm::rotate(transMatrix, glm::radians(rotationAmount),  rotation);
    transMatrix = glm::scale(transMatrix, scale);
}

void Model::Setup(Shader &shader, int index)
{
    getMesh(index);
    transUniform = glGetUniformLocation(shader.program, "transMatrix");

    translation = glm::vec3(0.0f, 0.0f, 0.0f);
    rotation = glm::vec3(0.0, 0.0, 1.0);
    scale = glm::vec3(0.0,0.0,0.0);

    transMatrix = glm::translate(transMatrix, translation);
    transMatrix = glm::rotate(transMatrix, glm::radians(rotationAmount),  rotation);
    transMatrix = glm::scale(transMatrix, scale);

}

void Model::Setup(Shader & shader, bool left)
{
    getMesh(1);
    transUniform = glGetUniformLocation(shader.program, "transMatrix");

    translation = glm::vec3(0.0f, 0.0f, 0.0f);
    rotation = glm::vec3(0.0, 0.0, 1.0);
    scale = glm::vec3(0.0,0.0,0.0);

    transMatrix = glm::translate(transMatrix, translation);
    transMatrix = glm::rotate(transMatrix, glm::radians(rotationAmount),  rotation);
    transMatrix = glm::scale(transMatrix, scale);

}

void Model::update(float speed)
{
    transMatrix = glm::mat4();
    glm::mat4 rotMat;
    if(speed > 0)
    {
        // use rotMat to move square to point, rotate the square, then move it back
        rotMat = glm::translate(rotMat, glm::vec3(1,0.0f,0.0f));  // one works here because it is 1/2 of 2, the width of the square
        rotMat = glm::rotate(rotMat, glm::radians(rotationAmount),  rotation);
        rotMat = glm::translate(rotMat, glm::vec3(-1, 0, 0));
        transMatrix = glm::translate(transMatrix, translation);
        transMatrix = glm::rotate(transMatrix, glm::radians(0.0f),  rotation);
        transMatrix = glm::scale(transMatrix, scale);
        transMatrix = transMatrix * rotMat;
    }
    else
    {
        rotMat = glm::translate(rotMat, glm::vec3(-1,0.0f,0.0f));
        rotMat = glm::rotate(rotMat, glm::radians(rotationAmount),  rotation);
        rotMat = glm::translate(rotMat, glm::vec3(1,0, 0));
        transMatrix = glm::translate(transMatrix, translation);
        transMatrix = glm::rotate(transMatrix, glm::radians(0.0f),  rotation);
        transMatrix = glm::scale(transMatrix, scale);
        transMatrix = transMatrix * rotMat;
    }

    mesh.update();
}

void Model::render()
{
    glUniformMatrix4fv(transUniform, 1, GL_FALSE, glm::value_ptr(transMatrix));
    mesh.render();
}

void Model::getMesh(std::string name)
{
    std::vector<Vertex> vertexArray;
    std::vector<GLuint> indices;

        Vertex v1(glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f));
        Vertex v2(glm::vec3(1.0f, -1.0f,0.0f), glm::vec2(1.0f, 1.0f));
        Vertex v3(glm::vec3(-1.0f, -1.0f, 0.0f), glm::vec2(0.0f, 1.0f));
        Vertex v4(glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f));
        vertexArray.push_back(v1);
        vertexArray.push_back(v2);
        vertexArray.push_back(v3);
        vertexArray.push_back(v4);
        GLuint ind[] = {
        0, 1, 3,
        1, 2, 3,
        };
        for(int i = 0; i < 6; i++)
        indices.push_back(ind[i]);

    if(name == "fish")
    {
        mesh.Setup(vertexArray, indices, Fish::tex1);
    }
    else if(name == "fishr")
    {
        mesh.Setup(vertexArray, indices, Fish::tex2);
    }
    else
    {
        Texture texture;
        std::string path = "res/textures/" + name + ".png";
        texture.Setup(path.c_str());
        mesh.Setup(vertexArray, indices, texture);
    }


}

void Model::getMesh(int index)
{
    std::vector<Vertex> vertexArray;
    std::vector<GLuint> indices;

        Vertex v1(glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f));
        Vertex v2(glm::vec3(1.0f, -1.0f,0.0f), glm::vec2(1.0f, 1.0f));
        Vertex v3(glm::vec3(-1.0f, -1.0f, 0.0f), glm::vec2(0.0f, 1.0f));
        Vertex v4(glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f));
        vertexArray.push_back(v1);
        vertexArray.push_back(v2);
        vertexArray.push_back(v3);
        vertexArray.push_back(v4);
        GLuint ind[] = {
        0, 1, 3,
        1, 2, 3,
        };
        for(int i = 0; i < 6; i++)
        indices.push_back(ind[i]);

    if(index == 0)
    {
    Texture texture;
    texture.Setup("res/textures/fish.png");
    mesh.Setup(vertexArray, indices, texture);
    }
    if(index == 1)
    {
    Texture texture;
    texture.Setup("res/textures/fishr.png");
    mesh.Setup(vertexArray, indices, texture);
    }
}

Model::~Model()
{
    //dtor
}
