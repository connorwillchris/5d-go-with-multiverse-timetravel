#ifndef GAME_HPP
#define GAME_HPP

#include <SDL3/SDL.h>
#include <iostream>

class Game {

public:
	Game();
	~Game();

	void init(
		const char* title,
		int width,
		int height,
		bool fullscreen
	);

	void handle_events();
	void update();
	void render();
	void clean();
	bool is_running();

private:
	bool running;
	SDL_Window* window;
	SDL_Renderer* renderer;

};

#endif
