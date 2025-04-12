#ifndef TEXT_INPUT_H
#define TEXT_INPUT_H
#include <SFML/Graphics.hpp>
#include <string>

class text_input {
private:
    sf::RectangleShape inputBox;
    sf::Text inputText;
    sf::RectangleShape cursor;
    sf::Clock cursorClock;
    bool showCursor = true;
    std::string inputString;
    sf::Font& font;
    sf::Text label;
    bool isFocused;
public:
    text_input(sf::Vector2f position, sf::Vector2f size, sf::Font& font, int characterSize, const std::string& labelText);
    void handleEvent(const sf::Event& event);
    void draw(sf::RenderWindow& window);
    std::string getText() const;
    void setText(std::string str);
    void setFocus(bool focus);
    bool isMouseOver(sf::Vector2i mousePos);
    void setLabel(const std::string& labelText);
};

#endif //TEXT_INPUT_H