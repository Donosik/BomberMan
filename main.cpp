#include "Game.h"

/// Główna funckja aplikacji
/// \return Zwraca 0, jeśli wszystko poprawne
int main()
{
    try
    {
        Game game;
        game.Run();
    }
    catch (std::exception ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
