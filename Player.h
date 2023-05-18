#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include <SFML/Graphics.hpp>
#include "WalkableTile.h"
#include "SolidTile.h"

/// Klasa reprezentująca gracza
class Player
{
    /// Kształt gracza
    sf::RectangleShape shape;
    /// Prędkość ruchu gracza
    float movementSpeed;
    /// Pozycja x gracza
    float xPos;
    /// Pozycja y gracza
    float yPos;
    /// Rozmiar
    int size;
    /// Przycisk do poruszania się w lewo
    sf::Keyboard::Key left;
    /// Przycisk do poruszania się w prawo
    sf::Keyboard::Key right;
    /// Przycisk do poruszania się w górę
    sf::Keyboard::Key up;
    /// Przycisk do poruszania się w dół
    sf::Keyboard::Key down;
public:
    /// Domyślny konstruktor
    Player();

    /// Ustawia pozycję początkową gracza
    /// \param x Pozycja x gracza
    /// \param y Pozycja y gracza
    void SetStartingPosition(int x, int y);

    /// Getter dla pozycji x
    /// \return Zwraca pole x na planszy
    int GetX();

    /// Getter dla pozycji y
    /// \return Zwraca pole y na planszy
    int GetY();

    /// Ustawia klawisze na WASD
    void SetStandardPlayerInput();

    /// Ustawia klawisze na strzałki
    void SetAdditionalPlayerInput();

    /// Funkcja odpowiedzialna za ruch gracza
    /// \param tiles Cała plansza gry
    void Movement(Tile *tiles[11][11]);

    /// Rysuje wszystkie elementy graficzne w oknie
    /// \param window Wskażnik na okno do rysowania
    void Draw(sf::RenderWindow *window);

private:
    /// Oblicza na podstawie pozycji na jakim polu się znajduje
    /// \param x Pozycja x
    /// \return Zwraca x pola
    int calculateX(int x);

    /// Oblicza na podstawie pozycji na jakim polu się znajduje
    /// \param y Pozycja y
    /// \return Zwraca y pola
    int calculateY(int y);
};


#endif BOMBERMAN_PLAYER_H
