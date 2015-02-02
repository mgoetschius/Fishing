#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <vector>
#include <string>
#include "Vertex.h"
#include "Texture.h"


class Mesh
{
    public:
        Mesh();
        void Setup(std::vector<Vertex> vert, std::vector<GLuint> ind, Texture tex);
        void Setup(bool left);
        void update();
        void render();
        virtual ~Mesh();
    protected:
    private:
        GLuint vao, vbo, ibo;
        int indicesCount;
        std::vector<Vertex> vertexArray;
        std::vector<GLuint> indices;
        Texture texture;
};

#endif // MESH_H
