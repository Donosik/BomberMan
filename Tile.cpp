#include "Tile.h"

Tile::Tile(): Tile(0,0,sf::Color::Yellow)
{
}

Tile::Tile(int x, int y, sf::Color c)
{
    xPos=x;
    yPos=y;
    color=c;

    border.setPosition(xPos,yPos);
    border.setSize(sf::Vector2f(50,50));
    border.setFillColor(sf::Color::White);

    shape.setPosition(xPos+2,yPos+2);
    shape.setSize(sf::Vector2f(46,46));
    shape.setFillColor(color);
}
