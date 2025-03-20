#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button {
    private:
        sf::RectangleShape shape;
        sf::Vector2f position;
        sf::Vector2f size;
        sf::Color color;
        sf::Font font;
        sf::Text text;
    public:
        Button(){}
        ~Button(){}
        Button(sf::Vector2f position, sf::Vector2f size, sf::Color color, std::string text);
        void draw(sf::RenderWindow& window);
        bool isClicked(sf::Vector2i mousePos);
        
};

#endif // BUTTON_H