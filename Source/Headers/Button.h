#pragma once

#include "SFML/Graphics.hpp"
//*--------------------------------------------------*//

//since sfml doesnt have a pre-defined button class, i made my own button class which is pretty helpfull.

//*--------------------------------------------------*//

class Button
{
public:
    // a constructor that takes the button title, button position, button size
    Button(const char* backGroundstr, sf::Vector2f buttonPos, sf::Vector2f buttonSize);

    //Functions
public:
    //Drawing button
    void draw(sf::RenderWindow& window);
    //Loading texts
    void loadText(const char* backGroundstr);
    //set button's background to white-gray color.
    void hoverOverButton();
    //set button's background transparent
    void Unhover();
    //Updates
    void update(sf::Vector2f CursCoords);
    //get button's position.
    sf::Vector2f getPos() { return button.getPosition(); }
    //getting button's size.
    sf::Vector2f thesize() { return button.getSize(); }
    //check if button is clicked
    bool checkClickedButton(sf::Vector2f cursorPosition);
    //check if cursor is in button bounds
    bool checkCursInButton(sf::Vector2f cursorPosition);

    //Variables
public:
    sf::Text text;

private:
    sf::RectangleShape button;
    sf::Font font;

};

