#include "Camera.h"
#include <Global.h>

Camera::Camera()
{}

void Camera::updateView(sf::View* view, sf::Vector2f playerPos, unsigned short Level,bool paused)
{
    //this function uses player position to update view.
    
    if (paused)
    {

        view->setCenter(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
        view->setSize(SCREEN_WIDTH,SCREEN_HEIGHT);
        return;
    }

    //camera control for level 3
    if (Level == 3)
    {

        if (playerPos.x >= CELL_WIDTH * 6 - 22)
        {

            if (playerPos.y <= CELL_HEIGHT * 4)
            {
                view->setCenter(CELL_WIDTH * 11 - 22, 260);
            }
            else if (playerPos.y < 500)
                view->setCenter(CELL_WIDTH * 11 - 22, 260);
            else
                view->setCenter(CELL_WIDTH * 11 - 22, 450);
            view->setSize(SCREEN_WIDTH - 200, SCREEN_HEIGHT - 200);

            return;
        }
        else
        {
            if (playerPos.y <= CELL_HEIGHT * 4)
            {
                view->setCenter(CELL_WIDTH * 8 - 10, 260);
            }
            else if (playerPos.y < 500)
                view->setCenter(CELL_WIDTH * 8 - 10, 260);
            else
                view->setCenter(CELL_WIDTH * 8 - 10, 450);
            view->setSize(SCREEN_WIDTH - 200, SCREEN_HEIGHT - 200);

            return;
        }

       
    }
    // camera control for level 1 / 2
    if (playerPos.x >= CELL_WIDTH * 6 - 22)
    {
        if (playerPos.y < 500)
            view->setCenter(CELL_WIDTH * 11 - 22, playerPos.y - 60);
        else
            view->setCenter(CELL_WIDTH * 11 - 22, 450);
        view->setSize(SCREEN_WIDTH - 200, SCREEN_HEIGHT - 200);

        return;
    }
    else
    {
        if (playerPos.y < 500)
            view->setCenter(CELL_WIDTH * 8 - 10, playerPos.y - 60);
        else
            view->setCenter(CELL_WIDTH * 8 - 10, 450);
        view->setSize(SCREEN_WIDTH - 200, SCREEN_HEIGHT - 200);
        return;
    }  
}