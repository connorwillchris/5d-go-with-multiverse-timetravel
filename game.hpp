#ifndef GAME_HPP
#define GAME_HPP

#include <SDL3/SDL.h>
#include <iostream>

class Game {

public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);
	void deinit();
	void update();
	void render();
	void handle_events();

	bool running();

private:
	bool is_running;
	SDL_Window* window;
	SDL_Renderer* renderer;

};

#endif
