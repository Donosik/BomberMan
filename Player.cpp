#include "Player.h"

Player::Player()
{
    size = 40;
    shape.setSize(sf::Vector2f(size, size));
    shape.setFillColor(sf::Color::Red);
    SetStartingPosition(0, 0);
    movementSpeed = 2;
    SetStandardPlayerInput();
}

void Player::SetStartingPosition(int x, int y)
{
    xPos = x;
    yPos = y;

    shape.setPosition(xPos, yPos);
}

void Player::SetStandardPlayerInput()
{
    left = sf::Keyboard::A;
    right = sf::Keyboard::D;
    up = sf::Keyboard::W;
    down = sf::Keyboard::S;

}

void Player::SetAdditionalPlayerInput()
{
    left = sf::Keyboard::Left;
    right = sf::Keyboard::Right;
    up = sf::Keyboard::Up;
    down = sf::Keyboard::Down;
    shape.setFillColor(sf::Color::Blue);
}

int Player::GetX()
{
    return calculateX(xPos);
}

int Player::GetY()
{
    return calculateY(yPos);
}

void Player::Movement(Tile *tiles[11][11])
{
    int LLX = calculateX(xPos - movementSpeed);
    int LX = calculateX(xPos);
    int RX = calculateX(xPos + size);
    int RRX = calculateX(xPos + size + movementSpeed);

    int UUY = calculateY(yPos - movementSpeed);
    int UY = calculateY(yPos);
    int DY = calculateY(yPos + size);
    int DDY = calculateY(yPos + size + movementSpeed);

    if (sf::Keyboard::isKeyPressed(left))
    {
        if (LLX >= 0)
        {
            if (UY == DY)
            {
                if (tiles[LLX][UY]->IsWalkable())
                {
                    xPos -= 1 * movementSpeed;
                }
            }
            else if (DY == (UY + 1))
            {
                if (tiles[LLX][UY]->IsWalkable())
                {
                    if (tiles[LLX][DY]->IsWalkable())
                    {
                        xPos -= 1 * movementSpeed;
                    }
                }
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(right))
    {
        if (RRX < 11)
        {
            if (UY == DY)
            {
                if (tiles[RRX][UY]->IsWalkable())
                {
                    xPos -= -1 * movementSpeed;
                }
            }
            else if (DY == (UY + 1))
            {
                if (tiles[RRX][UY]->IsWalkable())
                {
                    if (tiles[RRX][DY]->IsWalkable())
                    {
                        xPos -= -1 * movementSpeed;
                    }
                }
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(up))
    {
        if (UUY >= 0)
        {
            if (LX == RX)
            {
                if (tiles[LX][UUY]->IsWalkable())
                {
                    yPos -= 1 * movementSpeed;
                }
            }
            else if (RX == (LX + 1))
            {
                if (tiles[LX][UUY]->IsWalkable())
                {
                    if (tiles[RX][UUY]->IsWalkable())
                    {
                        yPos -= 1 * movementSpeed;
                    }
                }
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(down))
    {
        if (DDY < 11)
        {
            if (LX == RX)
            {
                if (tiles[LX][DDY]->IsWalkable())
                {
                    yPos -= -1 * movementSpeed;
                }
            }
            else if (RX == (LX + 1))
            {
                if (tiles[LX][DDY]->IsWalkable())
                {
                    if (tiles[RX][DDY]->IsWalkable())
                    {
                        yPos -= -1 * movementSpeed;
                    }
                }
            }
        }
    }

    shape.setPosition(xPos, yPos);
}

void Player::Draw(sf::RenderWindow *window)
{
    window->draw(shape);
}

int Player::calculateX(int x)
{

    x /= 50;
    x -= 7;
    return x;
}

int Player::calculateY(int y)
{
    y /= 50;
    y -= 2;
    return y;
}