#include "WalkableTile.h"

WalkableTile::WalkableTile(): WalkableTile(0,0,sf::Color::Green)
{

}

WalkableTile::WalkableTile(int x, int y, sf::Color c):Tile(x,y,c)
{

}

bool WalkableTile::IsWalkable()
{
    return true;
}

bool WalkableTile::IsDestructable()
{
    return false;
}

void WalkableTile::Draw(sf::RenderWindow *window)
{
    window->draw(border);
    window->draw(shape);
}