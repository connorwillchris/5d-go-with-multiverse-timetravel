#include "game.hpp"

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int width, int height, bool fullscreen) {
	int flags = 0;

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		running = false;
	}
	else {
		std::cout << "Subsystem initialized." << std::endl;

		window = SDL_CreateWindow("5D Go with Multiverse Timetravel", width, height, flags);
		if (window) {
			std::cout << "window created." << std::endl;
		}

		renderer = SDL_CreateRenderer(window, "");
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created." << std::endl;
		}
		running = true;
	}
}

void Game::handle_events() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_EVENT_QUIT:
			running = false;
			break;
		default:
			break;
	}
}

void Game::update() {
}

void Game::render() {
	SDL_RenderClear(renderer);

	// this is where we add stuff to render
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Game cleaned." << std::endl;
}

bool Game::is_running() {
	return running;
}