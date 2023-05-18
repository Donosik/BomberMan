#ifndef BOMBERMAN_GAME_H
#define BOMBERMAN_GAME_H

#include <SFML/Graphics.hpp>
#include "SolidTile.h"
#include "WalkableTile.h"
#include "IdestructableTile.h"
#include "Player.h"
#include "Bomb.h"
#include <vector>
#include <iostream>

/// Główna klasa gry
class Game
{
    /// Obiekt okna
    sf::RenderWindow window;
    /// Szerokość okna
    int width;
    /// Wysokość okna
    int height;
    /// Tablica 2-wymiarowa wszystkich pól gry
    Tile *tiles[11][11];
    /// Rozmiar pola gry
    int boardSize;
    /// Obiekt gracza 1
    Player player1;
    /// Obiekt gracza 2
    Player player2;
    /// Wektor wszystkich aktywnych bomb
    std::vector<Bomb> bombs;
    /// Informajca, który gracz przegrał
    int deadPlayer;
    /// Czcionka do wyświetlania tekstów
    sf::Font font;
    /// Tekst informujący o zwycięzcy
    sf::Text text;
public:
    /// Domyślny konstruktor
    Game();

    /// Główna pętla gry
    void Run();

    /// Obsługa zdarzeń
    void EventHandler();

    /// Rysowanie wszystkich elementów
    void Draw();

private:
    /// Inicjalizowanie pola gry
    void InitMap();

    /// Inicjalizowanie pojedycznego pola
    /// \param x Wartość x pola
    /// \param y Wartość y pola
    /// \param type Jaki ma być typ pola
    void InitTile(int x, int y, int type);

    /// Ustawia odpowiedni tekst o zwycięzcy
    /// \param playerNumber Numer przegranego gracza
    void PlayerDead(int playerNumber);
};


#endif BOMBERMAN_GAME_H
