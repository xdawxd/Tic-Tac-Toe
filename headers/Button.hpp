#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class Button : public sf::Drawable {
public:
    Button() = default;
    Button(const sf::String& text);

public:
    void setStyle(sf::Font& font, sf::Color fillColor, sf::Color outlineColor, float outlineThickness, unsigned int characterSize);
    void setButtonPosition(float x, float y);

public:
    bool isClicked(sf::Event& event, sf::Vector2f mousePosition);
    bool isHovered(sf::Event& event, sf::Vector2f mousePosition);
    void scaleOnHover(sf::Vector2f mousePosition);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::Text m_text;
};