
#include "Shader.h"

Shader::Shader()
{

}

void Shader::Setup(const GLchar* vertexPath, const GLchar* fragmentPath)
{
    this->program = glCreateProgram();
    vector<GLint> shaders;
    shaders.push_back(createShader(vertexPath, GL_VERTEX_SHADER));
    shaders.push_back(createShader(fragmentPath, GL_FRAGMENT_SHADER));
    glLinkProgram(this->program);
    GLint result;
    GLchar infoLog[512];
    glGetProgramiv(this->program, GL_LINK_STATUS, &result);
    if(!result)
    {
        glGetProgramInfoLog(this->program, 512, NULL, infoLog);
        cout << "ERROR Linking Program" << endl;
        cout << infoLog << endl;
    }

    for(vector<GLint>::const_iterator i = shaders.begin(); i != shaders.end(); i++ )
    {
        glDeleteShader(*i);
    }
}

GLint Shader::createShader(const char * filename, GLenum shaderType)
{
    GLuint shader = glCreateShader(shaderType);
    string shaderCode;
    loadShaderFile(filename, shaderCode);
    char const * shaderSource = shaderCode.c_str();
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    GLint result;
    GLchar infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

    if(!result)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        cout << "ERROR: " << filename;
        cout << infoLog << endl;
    }

    glAttachShader(this->program, shader);

    return shader;
}

void Shader::loadShaderFile(const GLchar * filepath, string & str)
{
    try
    {
        ifstream shaderFile(filepath);
        stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        str = shaderStream.str();
    }
    catch(exception e)
    {
        cout << "ERROR Loading: " << filepath << endl;
    }
}

void Shader::bind()
{
    glUseProgram(this->program);
}

Shader::~Shader()
{
    //dtor
}
