#include "main_menu.h"
using namespace gui;

main_menu::main_menu()
{
    buttons[0] = new Button("Adauga carte");
    buttons[1] = new Button("Adauga client");
    buttons[2] = new Button("Inchiriaza carte");
    buttons[3] = new Button("Exit to desktop");
}

Button* main_menu::operator[](int index)
{
    if(index < nr) return buttons[index];
    return NULL;
}

main_menu::~main_menu()
{
    for(int i = 0; i < nr; i++) delete buttons[i];
}