/*
    COPYRIGHT GOES HERE
*/

#include <SDL3/SDL.h>
#include "game.hpp"

Game* game = nullptr;

int main() {
    game = new Game();
    game->init("Engine", 1280, 720, false);

    while (game->is_running()) {
        game->handle_events();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}
