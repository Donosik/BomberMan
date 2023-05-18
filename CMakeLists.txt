cmake_minimum_required(VERSION 3.22)
project(BomberMan)

set(CMAKE_CXX_STANDARD 23)

add_executable(BomberMan main.cpp Game.cpp Game.h Tile.cpp Tile.h Player.cpp Player.h Bomb.cpp Bomb.h WalkableTile.cpp WalkableTile.h SolidTile.cpp SolidTile.h IdestructableTile.cpp IdestructableTile.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(BomberMan sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
