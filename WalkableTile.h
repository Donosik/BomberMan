#ifndef BOMBERMAN_WALKABLETILE_H
#define BOMBERMAN_WALKABLETILE_H

#include "Tile.h"

/// Klasa pola do chodzenia
class WalkableTile : public Tile
{
public:
    /// Domyślny konstruktor
    WalkableTile();

    /// Parametryzowany konstuktor
    /// \param x Pozycja x pola na planszy
    /// \param y Pozycja y pola na planszy
    /// \param c Kolor pola
    WalkableTile(int x, int y, sf::Color c);

    /// Czy płytka nadaje się do chodzenia
    /// \return Zwraca true
    bool IsWalkable() override;

    /// Czy płytka jest zniszczalna
    /// \return Zwraca false
    bool IsDestructable() override;

    /// Rysuje wszystkie elementy graficzne w oknie
    /// \param window Wskażnik na okno do rysowania
    void Draw(sf::RenderWindow *window) override;
};


#endif BOMBERMAN_WALKABLETILE_H
