#include "Game.h"

Game::Game()
{
    width = 1280;
    height = 720;
    window.create(sf::VideoMode(width, height), "BomberMan", sf::Style::Titlebar | sf::Style::Close);
    boardSize = 11;
    InitMap();
    player2.SetAdditionalPlayerInput();
    player1.SetStartingPosition(355, 105);
    player2.SetStartingPosition(855, 605);
    deadPlayer = false;
    if (!font.loadFromFile("arial.ttf"))
    {
        throw std::exception("Failed to load font file");
    }
    text.setFont(font);
    text.setString("");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Cyan);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(450, 20);
}

void Game::InitMap()
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (i % 2 == 1 && j % 2 == 1)
            {
                InitTile(i, j, 2);
            }
            else
            {
                InitTile(i, j, 0);
            }
        }
    }

    InitTile(0, 0, 1);
    InitTile(1, 0, 1);
    InitTile(0, 1, 1);

    InitTile(10, 10, 1);
    InitTile(9, 10, 1);
    InitTile(10, 9, 1);
}

void Game::InitTile(int x, int y, int type)
{
    if (type == 0)
    {
        tiles[x][y] = new SolidTile(350 + x * 50, 100 + y * 50, sf::Color::Magenta);
    }
    else if (type == 1)
    {
        tiles[x][y] = new WalkableTile(350 + x * 50, 100 + y * 50, sf::Color::Green);
    }
    else if (type == 2)
    {
        tiles[x][y] = new IndestructableTile(350 + x * 50, 100 + y * 50, sf::Color::Red);
    }
}

void Game::PlayerDead(int playerNumber)
{
    if (playerNumber == 1)
    {
        deadPlayer = 1;
        text.setString("Player 2 wins");
    }
    else if (playerNumber == 2)
    {
        deadPlayer = 2;
        text.setString("Player 1 wins");
    }
}

void Game::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time fpsLimit = sf::seconds(1.f / 5.f);

    while (window.isOpen())
    {
        sf::Time delta = clock.restart();
        timeSinceLastUpdate += delta;
        EventHandler();
        while (timeSinceLastUpdate > fpsLimit)
        {
            timeSinceLastUpdate -= fpsLimit;
            for (int i = 0; i < bombs.size(); i++)
            {
                if (bombs[i].GetTimer() < 0)
                {
                    int x = bombs[i].GetX();
                    int y = bombs[i].GetY();

                    int p1x = player1.GetX();
                    int p1y = player1.GetY();
                    int p2x = player2.GetX();
                    int p2y = player2.GetY();

                    if (x == p1x && y == p1y)
                    {
                        PlayerDead(1);
                    }
                    if (x == p2x && y == p2y)
                    {
                        PlayerDead(2);
                    }

                    if (x >= 1)
                    {
                        if (!tiles[x - 1][y]->IsWalkable())
                        {
                            if (tiles[x - 1][y]->IsDestructable())
                            {
                                tiles[x - 1][y] = new WalkableTile(350 + (x - 1) * 50, 100 + y * 50, sf::Color::Green);
                            }
                        }
                        if ((x - 1) == p1x && y == p1y)
                        {
                            PlayerDead(1);
                        }
                        if ((x - 1) == p2x && y == p2y)
                        {
                            PlayerDead(2);
                        }
                    }
                    if (x < boardSize - 1)
                    {
                        if (!tiles[x + 1][y]->IsWalkable())
                        {
                            if (tiles[x + 1][y]->IsDestructable())
                            {
                                tiles[x + 1][y] = new WalkableTile(350 + (x + 1) * 50, 100 + y * 50, sf::Color::Green);
                            }
                        }
                        if ((x + 1) == p1x && y == p1y)
                        {
                            PlayerDead(1);
                        }
                        if ((x + 1) == p2x && y == p2y)
                        {
                            PlayerDead(2);
                        }
                    }
                    if (y >= 1)
                    {
                        if (!tiles[x][y - 1]->IsWalkable())
                        {
                            if (tiles[x][y - 1]->IsDestructable())
                            {
                                tiles[x][y - 1] = new WalkableTile(350 + x * 50, 100 + (y - 1) * 50, sf::Color::Green);
                            }
                        }
                        if (x == p1x && (y - 1) == p1y)
                        {
                            PlayerDead(1);
                        }
                        if (x == p2x && (y - 1) == p2y)
                        {
                            PlayerDead(2);
                        }
                    }
                    if (y < boardSize - 1)
                    {
                        if (!tiles[x][y + 1]->IsWalkable())
                        {
                            if (tiles[x][y + 1]->IsDestructable())
                            {
                                tiles[x][y + 1] = new WalkableTile(350 + x * 50, 100 + (y + 1) * 50, sf::Color::Green);
                            }
                        }
                        if (x == p1x && (y + 1) == p1y)
                        {
                            PlayerDead(1);
                        }
                        if (x == p2x && (y + 1) == p2y)
                        {
                            PlayerDead(2);
                        }
                    }

                    bombs.erase(bombs.begin() + i);
                }
                else
                {
                    bombs[i].DecreaseTimer();
                }
            }
        }
        Draw();
    }
}

void Game::EventHandler()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        if (deadPlayer == 0)
        {
            player1.Movement(tiles);
            player2.Movement(tiles);
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    int x = player1.GetX();
                    int y = player1.GetY();
                    Bomb bomb(x, y);

                    bombs.push_back(bomb);
                }
                if (event.key.code == sf::Keyboard::RShift)
                {
                    int x = player2.GetX();
                    int y = player2.GetY();
                    Bomb bomb(x, y);

                    bombs.push_back(bomb);
                }
            }
        }
    }
}

void Game::Draw()
{
    if (window.isOpen())
    {
        window.clear(sf::Color(0, 0, 0, 0));
        for (int i = 0; i < boardSize; i++)
        {
            for (int j = 0; j < boardSize; j++)
            {
                tiles[i][j]->Draw(&window);
            }
        }
        if (deadPlayer != 1)
        {
            player1.Draw(&window);
        }
        if (deadPlayer != 2)
        {
            player2.Draw(&window);
        }
        for (auto bomb: bombs)
        {
            bomb.Draw(&window);
        }
        window.draw(text);
        window.display();
    }
}