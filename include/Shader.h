#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Shader
{
    public:
        GLint program;
        Shader();
        virtual ~Shader();
        void Setup(const GLchar* vertexPath, const GLchar* fragmentPath);
        GLint createShader(const char * filename, GLenum shaderType);
        void loadShaderFile(char const * filepath, string & str);
        void bind();
        //void test();
    protected:
    private:
};

#endif // SHADER_H
