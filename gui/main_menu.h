#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <vector>
#include "button.h"
using namespace std;
using namespace sf;
#define default_param(y_offset) sf::Vector2f(10, 10 + (y_offset)*70), sf::Vector2f(150, 60), sf::Color(192, 192, 192)

class main_menu{
    private:
        vector<Button> menu;
    public:
        main_menu();
        void add_button(Button& btn) {menu.push_back(btn);}
        void create_menu();
        void draw_menu(sf::RenderWindow& window)
        {
            for(Button btn: menu) btn.draw(window);
        }
        vector<Button> get_menu() {return menu;}
        ~main_menu(){}
};


#endif //MAIN_MENU_H