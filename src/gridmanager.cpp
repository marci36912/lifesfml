#include <iostream>
#include <cmath>
#include "gridmanager.hpp"

GridManager::GridManager(int wsize, int gsize)
{
    distance = wsize / gsize;
    gridSize = gsize;
    matrix = new Grid*[gridSize];

    for(int i = 0; i < gridSize; ++i)
    {
        matrix[i] = new Grid[gridSize];
        for(int j = 0; j < gridSize; ++j)
        {
            matrix[i][j] = Grid(sf::Vector2f(distance, distance), sf::Vector2f(i*distance,j*distance));
        }
    }
}

void GridManager::freeGrids()
{
    for(int i = 0; i < gridSize; ++i)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void GridManager::showGrids(sf::RenderWindow &w)
{
    for(int i = 0; i < gridSize; ++i)
    {
        for(int j = 0; j < gridSize; ++j)
        {
            matrix[i][j].setAlive();
            matrix[i][j].showGrid(w);
        }
    }
}

void GridManager::setAlive(sf::Vector2f mousePos)
{
    matrix[(int)std::floor(mousePos.x/distance)][(int)std::floor(mousePos.y/distance)].setAliveStatus();
}

void GridManager::updateGrids()
{
    for(int i = 0; i < gridSize; ++i)
    {
        for(int j = 0; j < gridSize; ++j)
        {
            checkNeighbours(i,j);
        }
    }
}

void GridManager::checkNeighbours(int i, int j)
{
    int neighbours = 0; 
    //makes sure we wont go out of bounds for both i and j
    int x = i-1 >= 0 ? i-1 : i;
    int n = i+1 < gridSize ? i+1 : i;
    int m = j+1 < gridSize ? j+1 : j;

    for(; x <= n; ++x)
    {
        for(int y = j-1 >= 0 ? j-1 : j;y <= m; ++y)
        {
            //count the neighbours
            if(x == i && y == j)
            {
                continue;
            }
            else if(matrix[x][y].getAlive())
                ++neighbours;
        }
    }

    if(matrix[i][j].getAlive())
    {
        if(neighbours < 2 || neighbours > 3)
            matrix[i][j].setAliveStatus();
    }
    else
    {
        if(neighbours == 3)
            matrix[i][j].setAliveStatus();
    }
}

void GridManager::resetGrids()
{
    for(int i = 0; i < gridSize; ++i)
    {
        for(int j = 0; j < gridSize; ++j)
        {
            matrix[i][j].reset();
        }
    }
}

void GridManager::showOutline()
{
    for(int i = 0; i < gridSize; ++i)
    {
        for(int j = 0; j < gridSize; ++j)
        {
            matrix[i][j].showOutline();
        }
    }
}