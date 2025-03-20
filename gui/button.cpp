#include "button.h"
#include <iostream>

Button::Button(sf::Vector2f position_, sf::Vector2f size_, sf::Color color_, std::string text_)
    : position(position_), size(size_), color(color_), text() {
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(color);

    if (!font.loadFromFile("gui/Arial.ttf")) { // Replace with your font file
        std::cerr << "Error loading font!" << std::endl;
    }

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setString(text_);
    text.setPosition(position_.x + size_.x / 2 - text.getLocalBounds().width / 2,
                        position_.y + size_.y / 2 - text.getLocalBounds().height / 2 - 10); // Center the text
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}

bool Button::isClicked(sf::Vector2i mousePos) {
    sf::FloatRect bounds = shape.getGlobalBounds();
    return bounds.contains(static_cast<sf::Vector2f>(mousePos));
}