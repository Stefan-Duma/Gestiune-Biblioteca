#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <vector>
#include "button.h"
using namespace std;
using namespace sf;

class main_menu{
    private:
        vector<Button> menu;
    public:
        main_menu(){}
        void add_button(Button& btn) {menu.push_back(btn);}
        void draw_menu(sf::RenderWindow& window)
        {
            for(Button& btn: menu) btn.draw(window);
        }
        vector<Button> get_menu() {return menu;}
        ~main_menu(){}
};


#endif //MAIN_MENU_H