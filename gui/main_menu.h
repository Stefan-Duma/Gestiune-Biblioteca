#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include <SFML/Graphics.hpp>
#include "../lib/Gui.hpp"
#include "../lib/TextBox.hpp"
#include <GL/gl.h>

#define nr 4

class main_menu{
    private:
        gui::Button* buttons[nr];
    public:
        main_menu();
        gui::Button* operator[](int index);
        ~main_menu();
};

#endif //MAIN_MENU_H