#pragma once

#include <SFML/Graphics.hpp>

class Grid{
    public:
        Grid();
        Grid(sf::Vector2f size, sf::Vector2f position);
        void setAlive();
        void setAliveStatus();
        bool getAlive();
        void reset();
        void showOutline();
        void showGrid(sf::RenderWindow &w);
    private:
        bool outline;
        bool aliveNow;
        bool aliveLastFrame;
        sf::RectangleShape body;
};