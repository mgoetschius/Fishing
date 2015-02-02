#include "Mesh.h"
#include "Vertex.h"
#include <iostream>

Mesh::Mesh()
{

}

void Mesh::Setup(std::vector<Vertex> vert, std::vector<GLuint> ind, Texture tex)
{
    vertexArray.clear();
    indices.clear();

    vertexArray = vert;
    indices = ind;
    texture = tex;

    int arraySize = 5 * indices.size();
    GLfloat vertices[arraySize];

    int j = 0;
    for(int i = 0; i < arraySize; i+=5 )
    {
        vertices[i] = vertexArray[j].GetPosition().x;
        vertices[i+1] = vertexArray[j].GetPosition().y;
        vertices[i+2] = vertexArray[j].GetPosition().z;
        vertices[i+3] = vertexArray[j].GetTexCoord().x;
        vertices[i+4] = vertexArray[j].GetTexCoord().y;
        j++;
    }

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));

    glBindVertexArray(0);

    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);
}

void Mesh::Setup(bool left)
{
    vertexArray.clear();
    indices.clear();
    if(left)
        texture.Setup("res/textures/fish.png");
    else
        texture.Setup("res/textures/fishr.png");

    if(true)
    {
        //left fisth
        Vertex v1(glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f));
        Vertex v2(glm::vec3(1.0f, -1.0f,0.0f), glm::vec2(1.0f, 1.0f));
        Vertex v3(glm::vec3(-1.0f, -1.0f, 0.0f), glm::vec2(0.0f, 1.0f));
        Vertex v4(glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f));
        vertexArray.push_back(v1);
        vertexArray.push_back(v2);
        vertexArray.push_back(v3);
        vertexArray.push_back(v4);
    }
    else
    {
        //right fish
        Vertex v1(glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f));
        Vertex v2(glm::vec3(1.0f, -1.0f,0.0f), glm::vec2(0.0f, 1.0f));
        Vertex v3(glm::vec3(-1.0f, -1.0f, 0.0f), glm::vec2(1.0f, 1.0f));
        Vertex v4(glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f));
        vertexArray.push_back(v1);
        vertexArray.push_back(v2);
        vertexArray.push_back(v3);
        vertexArray.push_back(v4);
    }


    int arraySize = 5 * 4;
    GLfloat vertices[arraySize];

    int j = 0;
    for(int i = 0; i < arraySize; i+=5 )
    {
        vertices[i] = vertexArray[j].GetPosition().x;
        vertices[i+1] = vertexArray[j].GetPosition().y;
        vertices[i+2] = vertexArray[j].GetPosition().z;
        vertices[i+3] = vertexArray[j].GetTexCoord().x;
        vertices[i+4] = vertexArray[j].GetTexCoord().y;
        j++;
    }

    GLuint ind[] = {  // Note that we start from 0!
        0, 1, 3,	// First Triangle
        1, 2, 3,
    };

    for(int i = 0; i < 6; i++)
        indices.push_back(ind[i]);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));

    glBindVertexArray(0);

    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);
}


void Mesh::update()
{

}

void Mesh::render()
{
    glBindVertexArray(vao);
    //make sure soil is loading RGBA image
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture.GetTexture());
    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);
}

Mesh::~Mesh()
{
    //dtor
}
