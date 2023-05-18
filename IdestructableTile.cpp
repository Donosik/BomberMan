#include "IdestructableTile.h"

IndestructableTile::IndestructableTile() : IndestructableTile(0, 0, sf::Color::Red)
{

}

IndestructableTile::IndestructableTile(int x, int y, sf::Color c) : Tile(x, y, c)
{

}

bool IndestructableTile::IsWalkable()
{
    return false;
}

bool IndestructableTile::IsDestructable()
{
    return false;
}

void IndestructableTile::Draw(sf::RenderWindow *window)
{
    window->draw(border);
    window->draw(shape);
}