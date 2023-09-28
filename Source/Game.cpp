#include "Game.h"
#include "Global.h"
#include <math.h>
#include <Player.h>
#include <TextsManager.h>
#include <Button.h>
#include <MapManager.h>
#include <Enemy.h>
#include "Collision.h"
#include <Camera.h>
#include <SwitchToCells.h>
#include <Boss.h>
#include <iostream>
#include <fstream>
#include <HUD.h>

//making objects

MapManager mapMan; //manage the map
Player player; // manage the player
TextsManager textMan; // manage texts

//buttons
Button playButton("play", sf::Vector2f(SCREEN_WIDTH / 2 - 50, 400), sf::Vector2f(80, 30)); // a "play" button
Button returnButton("return", sf::Vector2f(SCREEN_WIDTH / 2 - 40, 350), sf::Vector2f(80, 30)); // a "return" button
Button MMButton("MainMenu", sf::Vector2f(SCREEN_WIDTH / 2 - 40, 450), sf::Vector2f(80, 30)); // a "return" button
Button resetButton("reset", sf::Vector2f(SCREEN_WIDTH / 2 - 50, 600), sf::Vector2f(80, 30)); // a "return" button

//HUD(dps)
HUD hud;

//Level 1 enemy
Enemy mummy(sf::Vector2f( CELL_WIDTH * 8, CELL_HEIGHT * 11 ), static_cast<float>(CELL_WIDTH * 7), static_cast<float>(CELL_WIDTH * 10),5,1); // a mummy enemy

//Level 2 boss
Boss soulReaper(1);

//Level 3 enemies
Enemy mummy1(sf::Vector2f(CELL_WIDTH * 4, CELL_HEIGHT * 3), static_cast<float>(CELL_WIDTH *6), static_cast<float>(CELL_WIDTH * 15), 20,2); // a mummy enemy
Enemy mummy2(sf::Vector2f(CELL_WIDTH * 4, CELL_HEIGHT * 6), static_cast<float>(CELL_WIDTH *4), static_cast<float>(CELL_WIDTH * 15), 20,2); // a mummy enemy
Enemy mummy3(sf::Vector2f(CELL_WIDTH * 4, CELL_HEIGHT * 9), static_cast<float>(CELL_WIDTH *3), static_cast<float>(CELL_WIDTH * 13), 20,2); // a mummy enemy
Enemy mummy4(sf::Vector2f(CELL_WIDTH * 4, CELL_HEIGHT * 12), static_cast<float>(CELL_WIDTH), static_cast<float>(CELL_WIDTH * 3), 20,2); // a mummy enemy

//Level 4 boss

Boss finalBoss(2);



Game::Game(sf::RenderWindow& win, sf::View& v) :
    //getting the window from the main.cpp
    window(win),
    view(v),
    //setting isRunning to 1
    isRunning(1),
    isPlaying(0),
    canPause(0)
{
    //Capping the fps to 120
    window.setFramerateLimit(120);
    
    //setting icon
    icon.loadFromFile("../assets/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    Starting = 1;
    paused = 0;
    //get highscore stored in "highScore" text file
    Saves.open("../Saves.txt", std::ios::in);
    if (Saves.is_open()) {
        getline(Saves, savedLevels);
        Saves.close();
    }
    //if file is empty - > game will start from level 1
    if (savedLevels == "")
        Level = 1;
    else // else  game will start from previous saves ( convert the string to an int then cast it to an unsigned short because thats the type of variable Level)
        Level = (unsigned short)std::stoi(savedLevels);
    
    
}




//Initialiser
void Game::Init()
{
    //loading backgrounds to textures
    bgtexture.loadFromFile("../assets/Bg.png");
    pausedbgtexture.loadFromFile("../assets/pausedBg.png");
    //insertings texture to sprite
    bg.setTexture(bgtexture);
    //Initialize map and player to current LEVEL
    mapMan.init(Level);
    player.reset(Level);
}


//game loop
void Game::Run()
{
    //while isRunning is 1 the game loop keeps going
    while (Running())
    {

        float currentTime = clock.restart().asSeconds();
        float fps = 1.0f / (currentTime);

        while (1 == window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                Close();
                break;
            }
        }
        //game logic
        Logic();
    }
}



void Game::Logic()
{
    //clear the screen in the game loop
    Clear();
    if (isPlaying)
    {
        if (Starting) // if game is starting (entered level 2 / 4) ->  start a 5 seconds countdown
        {
            textMan.drawCountDown(&window, std::to_string((int)CountDown / 120));
            Draw();
            if (CountDown > 0)
                CountDown--;
            else
            {
                CountDown = 600;
                Starting = 0;
                canPause = 1;
            }
        }
        else
        {   // in game - > updated everything , draw everything
            Updates();
            Draw();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && canPause)
            {
                paused = 1;
                isPlaying = 0;
                bg.setTexture(pausedbgtexture);
            }
        }
    }
    else if (paused) // if games is paused ( pressed escape key)
    {

        window.draw(bg);
        returnButton.draw(window);
        returnButton.update(CursCoords());
        MMButton.draw(window);
        MMButton.update(CursCoords());
        //updating camera/view.
        Camera::updateView(&view, player.getPos(), Level, paused);
       // window.setView(view);
        window.setView(view);

        if (returnButton.checkClickedButton(CursCoords()))
        {
            paused = 0;
            canPause = 0;
            bg.setTexture(bgtexture);
            isPlaying = 1;
        }
        else if (MMButton.checkClickedButton(CursCoords()))
        {
            isPlaying = 0;
            paused = 0;
            bg.setTexture(bgtexture);
        }
    }
    else // main menu
    {
        //updating camera/view.
        Camera::updateView(&view, player.getPos(), Level, 1);
        // window.setView(view);
        window.setView(view);
        window.draw(bg);
        textMan.drawText(&window, textMan.title);
        playButton.update(CursCoords());
        playButton.draw(window);
        resetButton.update(CursCoords());
        resetButton.draw(window);
        if (finishedGame)
        {
            textMan.drawText(&window, textMan.GameOver);
        }
        if (playButton.checkClickedButton(CursCoords())) // if pressed play button - > game start
        {
            isPlaying = 1;
        }
        else if (resetButton.checkClickedButton(CursCoords()))
        {
            Level = 1;
            //empty file saves
            Saves.open("../Saves.txt", std::ios::out);
            Saves << "";
            Saves.close();
            mapMan.init(Level);
            player.reset(Level);
            mummy.reset();
            mummy1.reset();
            mummy2.reset();
            mummy3.reset();
            mummy4.reset();
            soulReaper.reset();
            finalBoss.reset();
        }
    }
    window.display();
}

//clearing the window
void Game::Clear()
{
    window.clear(sf::Color::Black);
}


//Updating ingame objects(Map/player/enemies/bosses)
void Game::Updates()
{
    //pausing cooldown
    if (!canPause)
    {
        if (pauseCD > 0)
            pauseCD--;
        else
        {
            pauseCD = 80;
            canPause = 1;
        }
    }
    //------------------//
    switch (Level)
    {
    case 1: // level 1 - > update player / level 1 enemy
    {
        player.update(mapMan.getMap(), { mummy.getPos() }, EnemyType::Mummy, Level);
        if (!mummy.dead()) // if enemy is alive -> update him
        {
            mummy.update(player.getPos());
            if (player.Attacking()) //if player attacks -> damage enemy , gives player a cooldown for his attack
            {
                mummy.damage(player.dps);
                player.damageEnemy = 0;
            }
            if (mummy.Attacking()) //if enemy attacks -> damage player , gives enemy a cooldown for his attack
            {
                player.damage(mummy.dps);
                mummy.attacked = 0;
            }
        }
        else //if enemy died -> update map ( drops look (green coins that increases player dps)).
        {
            if (!mapMan.updated())
            {
                mapMan.update(Level);
            }
        }
        break;
    }
    case 2: // level 2 -> update player / boss( soulreaper)
    {
        player.update(mapMan.getMap(), { soulReaper.getPos() }, EnemyType::SoulReaper, Level);
        if (!soulReaper.dead())
        {
            soulReaper.update(player.getPos());
            if (player.Attacking())
            {
                soulReaper.damage(player.dps);
                player.damageEnemy = 0;
            }
            if (soulReaper.Attacking())
            {
                player.damage(soulReaper.dps);
                soulReaper.attacked = 0;
            }
            if (soulReaper.Transformed()) // if health bar is smaller or equal to 30 -> boss becomes dangerous
            {
                soulReaper.phase2update();
            }
        }
        else // if the boss died - > drops loot (green coins that increases dps)
        {
            if (!mapMan.updated())
            {
                mapMan.update(Level);
            }
            if (!soulReaper.droppedLoot)
            {
                mapMan.init_coins(Level,550);
                soulReaper.droppedLoot = true;
            }
        }

        break;
    }
    case 3: //level 3 : update player / level 3 enemies ( the same things as above but in level 3 there is more than 1 enemy)
    {
        player.update(mapMan.getMap(), { mummy1.getPos(),mummy2.getPos(),mummy3.getPos(),mummy4.getPos() }, EnemyType::Mummy, Level);
        if (!mummy1.dead())
        {
            mummy1.update(player.getPos());
            if (player.Attacking())
            {
                mummy1.damage(player.dps);
                player.damageEnemy = 0;
            }
            if (mummy1.Attacking())
            {
                player.damage(mummy1.dps);
                mummy1.attacked = 0;
            }
        }
        if (!mummy2.dead())
        {
            mummy2.update(player.getPos());
            if (player.Attacking())
            {
                mummy2.damage(player.dps);
                player.damageEnemy = 0;
            }
            if (mummy2.Attacking())
            {
                player.damage(mummy2.dps);
                mummy2.attacked = 0;
            }
        }
        if (!mummy3.dead())
        {
            mummy3.update(player.getPos());
            if (player.Attacking())
            {
                mummy3.damage(player.dps);
                player.damageEnemy = 0;
            }
            if (mummy3.Attacking())
            {
                player.damage(mummy3.dps);
                mummy3.attacked = 0;
            }
        }
        if (!mummy4.dead())
        {
            mummy4.update(player.getPos());
            if (player.Attacking())
            {
                mummy4.damage(player.dps);
                player.damageEnemy = 0;
            }
            if (mummy4.Attacking())
            {
                player.damage(mummy4.dps);
                mummy4.attacked = 0;
            }
        }
        else if(!mapMan.isUpdated)
        {
            mapMan.update(Level);
            mapMan.isUpdated = 1;

        }
        break;
    }
    case 4: // final boss updates
    {
        player.update(mapMan.getMap(), { finalBoss.getPos() }, EnemyType::SoulReaper, Level);
        if (!finalBoss.dead())
        {
            finalBoss.update(player.getPos());
            if (finalBoss.Attacking())
            {
                player.damage(finalBoss.dps);
                finalBoss.attacked = 0;
            }
            if (player.Attacking() && finalBoss.isDown)
            {
                finalBoss.damage(player.dps);
                player.damageEnemy = 0;
            }
        }
        else // if final boss died - > game is over
        {
            finishedGame = 1;
            isPlaying = 0;
            Level = 1;
            mapMan.init(Level);
            player.reset(Level);
            Starting = 1;
        }
    }
    default:
        break;

    }
    //checking if player fall off map 
    if (player.getPos().y > SCREEN_HEIGHT - 10)
    {
        Reset();
    }

    //checking collision with coins
    for (unsigned short c = 0; c < mapMan.coinsVect.size(); c++)
    {
        if (coinCollision(player.getGlobalBounds(), mapMan.coinsVect[c].getGlobalBounds()))
        {
            mapMan.coinsVect.erase(mapMan.coinsVect.begin() + c);
            player.dps++;
        }
    }

    //if player entered a door
    if (walls_collision(player.getPos().x, player.getPos().y - 1, mapMan.getMap(), { Cell::Door }, player.isFlipped()))
    {
        Level++;
        switch (Level)
        {
        case 2:
        {
            SwitchVectToCells(mapMan.Level2, mapMan.getMap());
            break;
        }
        case 3:
        {
            SwitchVectToCells(mapMan.Level3, mapMan.getMap());
            break;
        }
        case 4:
        {
            SwitchVectToCells(mapMan.Level4, mapMan.getMap());
            break;
        }
        default:
            break;

        }
        //SwitchVectToCells(mapMan.Level2, mapMan.getMap());
        player.resetPos(Level);
        Starting = 1;
        mapMan.isUpdated = 0;
        mapMan.coinsVect.clear();
        //Saving Levels
        Saves.open("../Saves.txt", std::ios::out);
        Saves << std::to_string(Level);
        Saves.close();
    }
}


//drawing objects(map/player/score/enemies/control camera)
void Game::Draw()
{
    
    window.draw(bg); //drawing background
    mapMan.draw(&window); //drawing map
    player.draw(&window); //drawing player sprite
    hud.drawDPS(&window, player.dps, player.getPos(),Level); // drawing hud(damage per second)
    //Drawing enemies :
    switch (Level)
    {
    case 1:
    {
        mummy.draw(&window);
        break;
    }
    case 2:
    {
        soulReaper.draw(&window);
        break;
    }
    case 3:
    {
        mummy1.draw(&window);
        mummy2.draw(&window);
        mummy3.draw(&window);
        mummy4.draw(&window);
        break;
    }
    case 4:
    {
        finalBoss.draw(&window);
    }
    default:
        break;
    }


    //updating camera/view.
    Camera::updateView(&view, player.getPos(),Level,paused);


    window.setView(view);
}


//getting cursor coords on the window;
sf::Vector2f Game::CursCoords()
{
    // get the current mouse position in the window
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    // convert it to world coordinates
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
    return worldPos;
}


//reseing player/map/enemies
void Game::Reset()
{
    player.reset(Level); // reset player

    mapMan.reset(Level); // reset map
    //reseting enemies

    switch (Level)
    {
    case 1:
    {
        mummy.reset();
        break;
    }
    case 2:
    {
        soulReaper.reset();
        break;
    }
    case 3:
    {
        mummy1.reset();
        mummy2.reset();
        mummy3.reset();
        mummy4.reset();
        break;
    }case 4:
    {
        finalBoss.reset();
        break;
    }
    default:
        break;
    }
}

//closing game
void Game::Close()
{
    isRunning = 0;
    window.close();
}
