#include "Button.h"
#include <Global.h>
#include <string.h>

Button::Button(const char* backGroundstr, sf::Vector2f buttonPos, sf::Vector2f buttonSize)
{
    //setting the button size/position
    button.setSize(buttonSize);
    button.setFillColor(sf::Color(255, 0, 0, 0));
    button.setPosition(buttonPos);
    //loading text.
    loadText(backGroundstr);

}
//loading/setting texts ..
void Button::loadText(const char* backGroundstr)
{
    //loading font/text/setting text's position
    font.loadFromFile("../assets/Plaguard-ZVnjx.otf"); //game font.
    text.setFont(font);
    text.setString(backGroundstr);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(getPos().x + (thesize().x / 2) - 40, getPos().y + (thesize().y / 2) - 20);
}

void Button::hoverOverButton()
{
    //text becomes gray
    text.setFillColor(sf::Color(255, 255, 255, 128));
}

void Button::Unhover()
{
    text.setFillColor(sf::Color::White);
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(text);
}


//if cursor is inside the button -> we call the hover function(means text becomes gray)
void Button::update(sf::Vector2f CursCoords)
{

    if (checkCursInButton(CursCoords))
    {
        hoverOverButton();
    }
    else
    {
        Unhover();
    }


}

//checking if cursor is inside the button or not

bool Button::checkCursInButton(sf::Vector2f cursorPosition)
{
    return(cursorPosition.x >= button.getPosition().x && cursorPosition.x <= button.getPosition().x + button.getSize().x && cursorPosition.y >= button.getPosition().y && cursorPosition.y <= button.getPosition().y + button.getSize().y);
}
bool Button::checkClickedButton(sf::Vector2f cursorPosition)
{

    if (checkCursInButton(cursorPosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        return true;
    }
    return false;
}
