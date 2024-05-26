#include "Button.hpp"

Button::Button(const sf::String& text) {
    m_text.setString(text);
};

void Button::setStyle(sf::Font& font, const sf::Color fillColor, const sf::Color outlineColor, float outlineThickness, unsigned int characterSize) {
    m_text.setFont(font);
    m_text.setFillColor(fillColor);
    m_text.setOutlineColor(outlineColor);
    m_text.setOutlineThickness(outlineThickness);
    m_text.setCharacterSize(characterSize);
}

void Button::setButtonPosition(float x, float y) {
    m_text.setOrigin(
            m_text.getGlobalBounds().left + m_text.getGlobalBounds().width / 2.f,
            m_text.getGlobalBounds().top + m_text.getGlobalBounds().height / 2.f
    );
    m_text.setPosition(x, y);
}

bool Button::isClicked(sf::Event& event, sf::Vector2f mousePosition) {
    if (event.type == sf::Event::MouseButtonReleased && m_text.getGlobalBounds().contains(mousePosition))
        return true;
    return false;
}

bool Button::isHovered(sf::Event &event, sf::Vector2f mousePosition) {
    if (m_text.getGlobalBounds().contains(mousePosition))
        return true;
    return false;
}

void Button::scaleOnHover(sf::Vector2f mousePosition) {
    if (m_text.getGlobalBounds().contains(mousePosition))
        m_text.setScale(1.1f, 1.1f);
    else
        m_text.setScale(1.f, 1.f);
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(m_text);
}
