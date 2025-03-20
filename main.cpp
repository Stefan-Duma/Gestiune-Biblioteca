#include <SFML/Graphics.hpp>
#include <iostream>
#include "src/client.h"
#include "src/carte.h"
#include "src/persoana.h"
#include "src/exceptie.h"
#include "gui/button.h"
#include "gui/main_menu.h"

using namespace std;

#define default_param(y_offset) sf::Vector2f(10, 10 + (y_offset)*70), sf::Vector2f(150, 60), sf::Color(192, 192, 192)

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Main");
    main_menu mn;
    // char str[][20] = {"Adauga client", "Adauga carte", "Afisare clienti", "Afisare carti"};
    // Button* btns = new Button[20];
    // btns[0] = Button(default_param(0), str[0]);
    // mn.add_button(btns[0]);
    // btns[1] = Button(default_param(1), str[1]);
    // mn.add_button(btns[1]);
    Button btn = Button(default_param(0), "Adauga client");
    mn.add_button(btn);
    Button btn1 = Button(default_param(1), "Adauga carte");
    mn.add_button(btn1);
    Button btn2 = Button(default_param(2), "Afisare clienti");
    mn.add_button(btn2);
    Button btn3 = Button(default_param(3), "Afisare carti");
    mn.add_button(btn3);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
            {
                for(Button& buton : mn.get_menu())
                {
                    if(buton.isClicked(sf::Mouse::getPosition(window)))
                    {
                        cout << "It works!" << endl;
                    }
                }
            }
            window.clear();
            mn.draw_menu(window);
            window.display();
        }
    }
    return 0;
}