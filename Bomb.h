#ifndef BOMBERMAN_BOMB_H
#define BOMBERMAN_BOMB_H

#include <SFML/Graphics.hpp>

/// Klasa reprezentująca bombę na planszy
class Bomb
{
    /// Ile czasu pozostało do wybuchu
    int timer;
    /// Pozycja x w oknie
    int xPos;
    /// Pozycja y w oknie
    int yPos;
    /// Pozycja x na planszy
    int x;
    /// Pozycja y na planszy
    int y;
    /// Poziomy kształ bomby
    sf::RectangleShape shape1;
    /// Pionowy kształt bomby
    sf::RectangleShape shape2;
    /// Pozioma obramówka bomby
    sf::RectangleShape border1;
    /// Pionowa obramówka bomby
    sf::RectangleShape border2;
public:
    /// Domyślny konstruktor
    Bomb();

    /// Konstruktor parametryczny
    /// \param x Pozycja x bomby na planszy
    /// \param y Pozycja y bomby na planszy
    Bomb(int x, int y);

    /// Getter dla pozycji x na planszy
    /// \return Zwraca x
    int GetX();

    /// Getter dla pozycji y na planszy
    /// \return Zwraca y
    int GetY();

    /// Getter dla timera
    /// \return Zwraca timer
    int GetTimer();

    /// Zmniejsza z każdym wywołaniem timer o 1, gdy będzie poniżej zera, wywołuje Explode
    void DecreaseTimer();

    /// Symuluje eksplozję, zmienia kształ bomby by przypominała wybuch
    void Explode();

    /// Rysuje wszystkie elementy graficzne w oknie
    /// \param window Wskażnik na okno do rysowania
    void Draw(sf::RenderWindow *window);
};


#endif BOMBERMAN_BOMB_H
