#include "Vertex.h"

Vertex::Vertex()
{
    position = glm::vec3(0,0,0);
}

Vertex::Vertex(glm::vec3 pos, glm::vec2 tex)
{
    position = pos;
    texCoord = tex;
}

Vertex::~Vertex()
{
    //dtor
}
