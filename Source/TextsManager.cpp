#include "TextsManager.h"
#include <Global.h>


TextsManager::TextsManager()
{
	font.loadFromFile("../assets/Plaguard-ZVnjx.otf");
	title.setFont(font);
	title.setCharacterSize(60);
	title.setPosition(SCREEN_WIDTH / 2 - 220, 175);
	title.setStyle(sf::Text::Style::Regular);
	GameOver = title;
	CountDown = title;
	CountDown.setPosition((SCREEN_WIDTH / 2) - 100, SCREEN_HEIGHT / 2 - 80);
	GameOver.setPosition((SCREEN_WIDTH / 2) - 350, 100);
	GameOver.setCharacterSize(35);
	CountDown.setCharacterSize(80);
	CountDown.setStyle(sf::Text::Style::Bold);
	title.setString("Out Of Control");
	GameOver.setString("Congratulations on finishing the game");


}
//draw a given text on the screen
void TextsManager::drawText(sf::RenderWindow* window, sf::Text text)
{
	window->draw(text);
}

//draw countdown
void TextsManager::drawCountDown(sf::RenderWindow* window, std::string Text)
{
	CountDown.setString(Text);
	window->draw(CountDown);
}
