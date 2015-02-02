#include "Input.h"

Input::Input()
{

}

bool Input::getKey(int key)
{
    return keys[key];
}

void Input::setKeyTrue(int key)
{
    keys[key] = true;
}

void Input::setKeyFalse(int key)
{
    keys[key] = false;
}

Input::~Input()
{
    //dtor
}
