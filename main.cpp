/*
COPYRIGHT GOES HERE
*/

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "game.hpp"

Game* game = nullptr;

int main() {
	game = new Game();
	game->init("5D Go with Multiverse Timetravel", 1280, 720, false);

	while (game->running()) {
		game->handle_events();
		game->update();
		game->render();
	}

	game->deinit();

	return 0;
}
