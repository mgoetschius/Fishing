#include "TextRenderer.h"

TextRenderer::TextRenderer()
{
    shader.Setup("res/shaders/textvertexshader.vs", "res/shaders/textfragmentshader.fs");
    std::string path = "res/textures/characters.png";
    texture.Setup(path.c_str());

    widthUniform = glGetUniformLocation(shader.program, "windowWidth" );
    heightUniform = glGetUniformLocation(shader.program, "windowHeight" );


    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &verticesBuffer);
	glGenBuffers(1, &texCoordsBuffer);
}

void TextRenderer::renderText(std::string text, int x, int y, int size, int windowWidth, int windowHeight)
{
    vertices.clear();
    texCoords.clear();
    for(unsigned int i = 0; i < text.length(); i++)
    {
        glm::vec3 topLeft = glm::vec3(x+i*size, y + size, 0);
        glm::vec3 topRight = glm::vec3(x+i*size+size, y + size, 0);
        glm::vec3 bottomLeft = glm::vec3(x+i*size, y, 0);
        glm::vec3 bottomRight = glm::vec3(x+i*size+size, y, 0);

        vertices.push_back(topLeft);
		vertices.push_back(bottomLeft);
		vertices.push_back(topRight);

		vertices.push_back(bottomRight);
		vertices.push_back(topRight);
		vertices.push_back(bottomLeft);

		char c = text[i];
		float texCoordX = (c % 16)/16.0f;
		float texCoordY = (c / 16)/16.0f;

		glm::vec2 topLeftTex    = glm::vec2( texCoordX, texCoordY );
		glm::vec2 topRightTex   = glm::vec2( texCoordX+1.0f/16.0f, texCoordY );
		glm::vec2 bottomRightTex = glm::vec2( texCoordX+1.0f/16.0f, (texCoordY + 1.0f/16.0f) );
		glm::vec2 bottomLeftTex  = glm::vec2( texCoordX, (texCoordY + 1.0f/16.0f) );
		texCoords.push_back(topLeftTex   );
		texCoords.push_back(bottomLeftTex );
		texCoords.push_back(topRightTex  );

		texCoords.push_back(bottomRightTex);
		texCoords.push_back(topRightTex);
		texCoords.push_back(bottomLeftTex);
    }

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, texCoordsBuffer);
    glBufferData(GL_ARRAY_BUFFER, texCoords.size() * sizeof(glm::vec2), &texCoords[0], GL_STATIC_DRAW);

    shader.bind();

    glUniform1i(widthUniform, windowWidth);
    glUniform1i(heightUniform, windowHeight);

    glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, texCoordsBuffer);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0 );

    glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture.GetTexture());

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glDrawArrays(GL_TRIANGLES, 0, vertices.size() );

	glDisable(GL_BLEND);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);

}

TextRenderer::~TextRenderer()
{
    //dtor
}
