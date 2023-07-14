#pragma once

#include <SFML/Graphics.hpp>
#include "grid.hpp"

class GridManager{
    public:
        GridManager(int wsize, int gsize);
        void freeGrids();
        void showGrids(sf::RenderWindow &w);
        void setAlive(sf::Vector2f mousePos);
        void updateGrids();
        void resetGrids();
        void showOutline();
    private:
        int gridSize, distance;
        Grid **matrix;
        void checkNeighbours(int i, int j);
};