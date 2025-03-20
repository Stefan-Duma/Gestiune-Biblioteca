#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Button Example");
    Button myButton(sf::Vector2f(10, 10), sf::Vector2f(150, 60), sf::Color::Red, "Click Me!");
    Button myButton2(sf::Vector2f(10, 10+10+60), sf::Vector2f(150, 60), sf::Color::Green, "Click Me!");

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
        myButton2.draw(window);
        window.display();
    }

    return 0;
}