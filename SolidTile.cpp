#include "SolidTile.h"

SolidTile::SolidTile(): SolidTile(0,0,sf::Color::White)
{

}

SolidTile::SolidTile(int x, int y, sf::Color c): Tile(x,y,c)
{

}

bool SolidTile::IsWalkable()
{
    return false;
}

bool SolidTile::IsDestructable()
{
    return true;
}

void SolidTile::Draw(sf::RenderWindow *window)
{
    window->draw(border);
    window->draw(shape);
}

