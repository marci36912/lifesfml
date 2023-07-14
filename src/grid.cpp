#include "grid.hpp"

Grid::Grid(){}
Grid::Grid(sf::Vector2f size, sf::Vector2f position):
body(size)
{
    aliveLastFrame = false;
    aliveNow = false;
    outline = false;
    body.setOutlineColor(sf::Color::Red);
    body.setFillColor(sf::Color::Black);
    body.setPosition(position);
}

void Grid::setAliveStatus()
{
    aliveLastFrame = !aliveLastFrame;
}

void Grid::setAlive()
{
    if(aliveLastFrame != aliveNow)
    {
        aliveNow = aliveLastFrame;
        body.setFillColor(aliveNow ? sf::Color::White : sf::Color::Black);
    }
}

void Grid::showGrid(sf::RenderWindow &w)
{
    w.draw(body);
}

bool Grid::getAlive()
{
    return aliveNow;
}

void Grid::reset()
{
    aliveNow = false;
    aliveLastFrame = false;
    body.setFillColor(sf::Color::Black);
}

void Grid::showOutline()
{
    outline = !outline;

    body.setOutlineThickness(outline ? 0.5f : 0);
}