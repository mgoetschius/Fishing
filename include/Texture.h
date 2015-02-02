#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

class Texture
{
    public:
        Texture();
        void Setup(const char * filepath);
        GLuint loadTexture(const char * filepath);
        GLuint GetTexture() { return texID; };
        virtual ~Texture();
    protected:
    private:
        GLuint texID;
};

#endif // TEXTURE_H
