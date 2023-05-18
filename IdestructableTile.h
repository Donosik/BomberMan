#ifndef BOMBERMAN_IDESTRUCTABLETILE_H
#define BOMBERMAN_IDESTRUCTABLETILE_H

#include "Tile.h"

/// Klasa niezniszczalnego pola
class IndestructableTile : public Tile
{
public:
    /// Domyślny konstruktor
    IndestructableTile();

    /// Parametryzowany konstuktor
    /// \param x Pozycja x pola na planszy
    /// \param y Pozycja y pola na planszy
    /// \param c Kolor pola
    IndestructableTile(int x, int y, sf::Color c);

    /// Czy płytka nadaje się do chodzenia
    /// \return Zwraca false
    bool IsWalkable() override;

    /// Czy płytka jest zniszczalna
    /// \return Zwraca false
    bool IsDestructable() override;

    /// Rysuje wszystkie elementy graficzne w oknie
    /// \param window Wskażnik na okno do rysowania
    void Draw(sf::RenderWindow *window) override;
};


#endif BOMBERMAN_IDESTRUCTABLETILE_H
