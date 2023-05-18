#ifndef BOMBERMAN_SOLIDTILE_H
#define BOMBERMAN_SOLIDTILE_H

#include "Tile.h"

/// Klasa niszczalnego pola
class SolidTile : public Tile
{
public:
    /// Domyślny konstruktor
    SolidTile();

    /// Parametryzowany konstuktor
    /// \param x Pozycja x pola na planszy
    /// \param y Pozycja y pola na planszy
    /// \param c Kolor pola
    SolidTile(int x, int y, sf::Color c);

    /// Czy płytka nadaje się do chodzenia
    /// \return Zwraca false
    bool IsWalkable() override;

    /// Czy płytka jest zniszczalna
    /// \return Zwraca true
    bool IsDestructable() override;

    /// Rysuje wszystkie elementy graficzne w oknie
    /// \param window Wskażnik na okno do rysowania
    void Draw(sf::RenderWindow *window) override;
};


#endif BOMBERMAN_SOLIDTILE_H
