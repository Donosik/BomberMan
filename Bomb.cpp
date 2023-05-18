#include "Bomb.h"

Bomb::Bomb() : Bomb(0, 0)
{

}

Bomb::Bomb(int x, int y)
{
    timer = 15;

    this->x = x;
    this->y = y;
    xPos = 360 + x * 50;
    yPos = 110 + y * 50;

    border1.setPosition(xPos, yPos);
    border2.setPosition(xPos, yPos);
    shape1.setPosition(xPos + 2, yPos + 2);
    shape2.setPosition(xPos + 2, yPos + 2);

    border1.setFillColor(sf::Color::White);
    border2.setFillColor(sf::Color::White);
    shape1.setFillColor(sf::Color::Cyan);
    shape2.setFillColor(sf::Color::Cyan);

    border1.setSize(sf::Vector2f(34, 34));
    border2.setSize(sf::Vector2f(34, 34));
    shape1.setSize(sf::Vector2f(30, 30));
    shape2.setSize(sf::Vector2f(30, 30));
}

int Bomb::GetX()
{
    return x;
}

int Bomb::GetY()
{
    return y;
}

int Bomb::GetTimer()
{
    return timer;
}

void Bomb::DecreaseTimer()
{
    timer--;
    if (timer < 0)
    {
        Explode();
    }
}

void Bomb::Explode()
{
    int xPos2 = xPos - 30;
    int yPos2 = yPos - 30;

    border1.setPosition(xPos2, yPos);
    shape1.setPosition(xPos2 + 2, yPos + 2);

    border1.setSize(sf::Vector2f(94, 34));
    shape1.setSize(sf::Vector2f(90, 30));

    border2.setPosition(xPos, yPos2);
    shape2.setPosition(xPos, yPos2 + 2);

    border2.setSize(sf::Vector2f(34, 94));
    shape2.setSize(sf::Vector2f(30, 90));
}

void Bomb::Draw(sf::RenderWindow *window)
{
    window->draw(border1);
    window->draw(border2);
    window->draw(shape1);
    window->draw(shape2);
}