#include "main_menu.h"

main_menu::main_menu(){
    Button* btn = new Button(default_param(0), "Adauga client");
    add_button(*btn);
    Button* btn1 = new Button(default_param(1), "Adauga carte");
    add_button(*btn1);
    Button* btn2 = new Button(default_param(2), "Afisare clienti");
    add_button(*btn2);
    Button* btn3 = new Button(default_param(3), "Afisare carti");
    add_button(*btn3);
}