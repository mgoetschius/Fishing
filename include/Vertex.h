#ifndef VERTEX_H
#define VERTEX_H

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>


class Vertex
{
    public:
        Vertex();
        Vertex(glm::vec3 pos);
        Vertex(glm::vec3 pos, glm::vec2 tex);
        glm::vec3 GetPosition() { return position; }
        glm::vec2 GetTexCoord() { return texCoord; }
        virtual ~Vertex();
    protected:
    private:
        glm::vec3 position;
        glm::vec2 texCoord;
};

#endif // VERTEX_H
