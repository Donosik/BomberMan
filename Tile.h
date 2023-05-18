#ifndef BOMBERMAN_TILE_H
#define BOMBERMAN_TILE_H

#include <SFML/Graphics.hpp>

/// Klasa abstrakcyjna pola
class Tile
{
protected:
    /// Kształt pola
    sf::RectangleShape shape;
    /// Obramowanie pola
    sf::RectangleShape border;
    /// Kolor pola
    sf::Color color;
    /// Pozycja x pola
    int xPos;
    /// Pozycja y pola
    int yPos;
public:
    /// Domyślny konstruktor
    Tile();

    /// Parametryzowany konstuktor
    /// \param x Pozycja x pola na planszy
    /// \param y Pozycja y pola na planszy
    /// \param c Kolor pola
    Tile(int x, int y, sf::Color c);

    // Wirtualne Czy płytka nadaje się do chodzenia
    /// \return Zwraca bool
    virtual bool IsWalkable() = 0;

    /// Wirtualne Czy płytka jest zniszczalna
    /// \return Zwraca bool
    virtual bool IsDestructable() = 0;

    /// Wirtualnie Rysuje wszystkie elementy graficzne w oknie
    /// \param window Wskażnik na okno do rysowania
    virtual void Draw(sf::RenderWindow *window) = 0;
};


#endif BOMBERMAN_TILE_H
