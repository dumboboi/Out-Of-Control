#include "HUD.h"
#include <Global.h>


HUD::HUD()
{
    //loading textures
	dpsTexture.loadFromFile("../assets/dpsicon.png");
	dpsSpr.setTexture(dpsTexture);
	font.loadFromFile("../assets/Plaguard-ZVnjx.otf");
	dps.setFont(font);
	dps.setCharacterSize(16);
	dps.setStyle(sf::Text::Style::Bold);
	dps.setFillColor(sf::Color::White);
}

//drawing dps on the window
void HUD::drawDPS(sf::RenderWindow* window, short dps, sf::Vector2f playerPos,unsigned short Level)
{
	this->dps.setString(std::to_string(dps));
	this->dps.setPosition(48, playerPos.y - 300);
	dpsSpr.setPosition(24, playerPos.y - 300);
    if (Level == 3)
    {

        if (playerPos.x >= CELL_WIDTH * 6 - 22)
        {

            if (playerPos.y <= CELL_HEIGHT * 4)
            {
                this->dps.setPosition(234, 10);
                dpsSpr.setPosition(210, 10);
            }
            else if (playerPos.y < 500)
            {
                this->dps.setPosition(234, 10);
                dpsSpr.setPosition(210, 10);
            }
            else
            {
                this->dps.setPosition(234, 230);
                dpsSpr.setPosition(210, 230);
            }
        }
        else
        {
            if (playerPos.y <= CELL_HEIGHT * 4)
            {
                this->dps.setPosition(48, 10);
                dpsSpr.setPosition(24, 10);
            }
            else if (playerPos.y < 500)
            {
                this->dps.setPosition(48, 10);
                dpsSpr.setPosition(24, 10);
            }
            else
            {
                this->dps.setPosition(48, 230);
                dpsSpr.setPosition(24, 230);
            }
        }
    }
    else
    {
        if (playerPos.y >= 560)
        {
            this->dps.setPosition(48, 230);
            dpsSpr.setPosition(24, 230);
        }
        else
            if (playerPos.x >= CELL_WIDTH * 6 - 22)
            {
                this->dps.setPosition(234, playerPos.y - 300);
                dpsSpr.setPosition(210, playerPos.y - 300);
            }
    }
	window->draw(dpsSpr);
	window->draw(this->dps);
}