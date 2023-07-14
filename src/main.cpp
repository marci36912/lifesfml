#include <SFML/Graphics.hpp>
#include <iostream>
#include "gridmanager.hpp"

#define WINDOW_SIZE 1000
#define GRID_SIZE 15
#define UPDATETIME 0.3

int main()
{
    bool activeGame = false;
    float counter = UPDATETIME;
    sf::Clock c;
    GridManager gridManager(WINDOW_SIZE, GRID_SIZE);
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "life");

    while (window.isOpen())
    {
        sf::Event event;

        if(activeGame && counter < 0)
        {
            gridManager.updateGrids();
            counter = UPDATETIME;
        }
        else
            counter -= c.restart().asSeconds();
        
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonReleased:
                    if(event.mouseButton.button == sf::Mouse::Left)
                        gridManager.setAlive(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
                    break;
                case sf::Event::KeyReleased:
                    if(event.key.scancode == sf::Keyboard::Scan::Space)
                    {
                        activeGame = !activeGame;
                        std::cout << (activeGame ? "megy" : "nem emgyen") << std::endl;
                    }
                    else if(event.key.scancode == sf::Keyboard::Scan::R)
                        gridManager.resetGrids();
                    else if(event.key.scancode == sf::Keyboard::Scan::O)
                        gridManager.showOutline();
                    break;
                default:
                    break;
            }
        }

        window.clear();
        gridManager.showGrids(window);
        window.display();
    }

    gridManager.freeGrids();
    return 0;
}
