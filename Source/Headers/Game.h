#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "fstream"
class Game
{
public:
    Game(sf::RenderWindow& win,sf::View& v);

    //Functions
public:
    //Initialize things
    void Init();
    //Game loop
    void Run();
private:
    //Game logic
    void Logic();
    //Clear window
    void Clear();
    //Update objects(Map/player/enemies)
    void Updates();
    //Draw objects
    void Draw();
    //Reset the game
    void Reset();
    //Close the game
    void Close();

    bool Running() { return isRunning; }
    sf::Vector2f CursCoords();


    //variables
private:
    //bool variables
    bool isRunning;
    bool isPlaying;
    bool levelComplete = 0;
    bool Starting;
    bool paused;
    bool canPause;
    bool finishedGame;
    
    //sfml variables
    sf::RenderWindow& window;
    sf::Event event;
    sf::Clock clock;
    sf::Image icon;
    sf::Texture bgtexture;
    sf::Texture pausedbgtexture;
    sf::Sprite bg;
    sf::View view;

    //file 
    std::fstream Saves;

    //short variables
    unsigned short Level ;

    //float variables
    float CountDown = 600;
    float pauseCD = 80;

    //strings variables
    std::string savedLevels;

};

