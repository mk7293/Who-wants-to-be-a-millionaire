#include <iostream>
#include "src/game.h"

int main() {
    Game::initialize_game();
    Game("Hakim").play_game();
    return 0;
}