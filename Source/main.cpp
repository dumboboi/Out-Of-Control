
#include <SFML/Graphics.hpp>
#include <Global.h>
#include <Game.h>
#include "time.h"

int main()
{
    srand(time(NULL));

    //creating a window for the game
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Out Of Control");
    //creating a view
    sf::View view(sf::FloatRect(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT));
    //Creating an object game of the class Game .
    Game game(window,view);
    //Initializing fpslimit/Texts/Score
    game.Init();
    //Running the game(Game loop)
    //this way its looks nicer than putting the game loop in here
    game.Run();

    //returns 0 after closing the game window
    return EXIT_SUCCESS;
}
