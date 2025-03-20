#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "button.h"
#include "main_menu.h"

#define default_param(y_offset) sf::Vector2f(10, 10 + (y_offset)), sf::Vector2f(150, 60), sf::Color(128, 128, 128)

using namespace std;
using namespace sf;
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Button Example");
    Button myButton(default_param(0), "Click Me!");
    main_menu mn;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (myButton.isClicked(sf::Mouse::getPosition(window))) {
                        std::cout << "Button clicked!" << std::endl;
                    }
                }
            }
        }
        
        window.clear();
        myButton.draw(window);
        window.display();
    }

    return 0;
}