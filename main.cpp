#include <GL/glew.h>
#include <GL/glfw3.h>

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
#include "Game.h"
#include "Input.h"


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void window_size_callback(GLFWwindow* window, int width, int height);
void run(GLFWwindow* win, Game &game);
void update(Game &game);
void render(GLFWwindow* window, Game &game);
void printFPS(const int& f, const int& u);

bool showFPS = true;
bool Input::keys[350];  //GLFW uses up to 348;
int Game::windowWidth = 640;
int Game::windowHeight = 480;


int main()
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(Game::windowWidth, Game::windowHeight, "Fishing Rodeo", NULL, NULL);
    glfwMakeContextCurrent(window);
    // Set the required callback functions  other available
    glfwSetKeyCallback(window, key_callback);
    glfwSetWindowSizeCallback(window, window_size_callback);

    glewExperimental = GL_TRUE;
    glewInit();

    cout << "OpenGL Version: " << glGetString(GL_VERSION) << "\n\n";

    glViewport(0, 0, Game::windowWidth, Game::windowHeight);
    glClearColor(0.0, 0.0, 0.7, 1.0);

    Game game;
    game.Init();

    run(window, game);

    glfwTerminate();
    return 0;
}

void run(GLFWwindow* win, Game &game)
{
    double lastTime= glfwGetTime();
    double timer = lastTime;
    double delta = 0;
    int frames = 0;
    int updates = 0;
    while(!glfwWindowShouldClose(win))
    {
        double now = glfwGetTime();
        delta += (now-lastTime)/(1.0/60.0);
        lastTime = now;
        while (delta > 1)
        {
            update(game);
            updates++;
            delta--;
        }
        render(win, game);
        frames++;
        if(glfwGetTime() - timer > 1.0)
        {
            if(showFPS)
            {
                printFPS(frames, updates);
            }

            frames = 0;
            updates = 0;
            timer++;
        }
    }
}

void update(Game &game)
{
    glfwPollEvents();
    game.Update();
}

void render(GLFWwindow* window, Game &game)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    game.Render();

    glfwSwapBuffers(window);
}




void printFPS(const int& f, const int& u)
{
    cout << "FPS: " << f << " UPS: " << u << endl;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    //cout << key << endl;
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if(key && action == GLFW_PRESS)
        Input::setKeyTrue(key);
    if(key && action == GLFW_RELEASE)
        Input::setKeyFalse(key);
}

void window_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    glOrtho(0.0f, width, height, 0.0f, 0.0f, 1.0f);
    Game::windowWidth = width;
    Game::windowHeight = height;
}

