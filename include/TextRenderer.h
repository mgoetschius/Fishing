#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include "Shader.h"
#include "Texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>


class TextRenderer
{
    public:
        TextRenderer();
        void renderText(std::string text, int x, int y, int size, int windowWidth, int windowHeight);
        virtual ~TextRenderer();
    protected:
    private:
        Shader shader;
        Texture texture;
        std::vector<glm::vec3> vertices;
        std::vector<glm::vec2> texCoords;
        GLuint vao, verticesBuffer, texCoordsBuffer;
        GLuint widthUniform, heightUniform;
};

#endif // TEXTRENDERER_H
