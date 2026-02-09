#include "game.hpp"

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "SDL initialized" << std::endl;

		window = SDL_CreateWindow(title, width, height, flags);

		if (window) {
			std::cout << "Window initialized" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, "");
		if (renderer) {
			std::cout << "Renderer initialized" << std::endl;
		}

		is_running = true;
	}
	else {
		is_running = false;
	}
}

void Game::deinit() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Game deinitialized" << std::endl;
}

void Game::update() {}

void Game::render() {
	SDL_RenderClear(renderer);
	/* THIS IS WHERE WE ADD STUFF TO RENDER */
	SDL_RenderPresent(renderer);
}

void Game::handle_events() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_EVENT_QUIT:
			is_running = false;
			break;
		default:
			break;
	}
}

bool Game::running() {
	return is_running;
}