#include "text_input.h"

text_input::text_input(sf::Vector2f position, sf::Vector2f size, sf::Font& font, int characterSize)
    : font(font) {
    inputBox.setPosition(position);
    inputBox.setSize(size);
    inputBox.setFillColor(sf::Color::White);
    inputBox.setOutlineThickness(1);
    inputBox.setOutlineColor(sf::Color::Black);

    inputText.setFont(font);
    inputText.setCharacterSize(characterSize);
    inputText.setFillColor(sf::Color::Black);
    inputText.setPosition(position.x + 5, position.y); // Add some padding
    cursor.setFillColor(sf::Color::Black);
}

void text_input::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128) {
            if (event.text.unicode == 8 && !inputString.empty()) {
                inputString.pop_back();
            } else if (event.text.unicode != 13) {
                inputString += static_cast<char>(event.text.unicode);
            }
        }
    }
}

void text_input::draw(sf::RenderWindow& window) {
    inputText.setString(inputString);

    if (cursorClock.getElapsedTime().asMilliseconds() > 500) {
        showCursor = !showCursor;
        cursorClock.restart();
    }

    cursor.setSize(sf::Vector2f(2, inputText.getGlobalBounds().height));
    cursor.setPosition(inputText.getPosition().x + inputText.getLocalBounds().width + 2, inputText.getPosition().y + 5);
    window.draw(inputBox);
    window.draw(inputText);
    if (showCursor) {
        window.draw(cursor);
    }
}

std::string text_input::getText() const {
    return inputString;
}