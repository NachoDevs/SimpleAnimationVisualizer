#include <iostream>
#include <string>

#include "SDL.h"
#include "../include/Timer.h"
#include "../include/Sprite.h"

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 640

bool isRunning;

static SDL_Event event;

static SDL_Renderer *renderer;

SDL_Window *m_window;


bool init(const char * t_title, int t_xpos, int t_ypos, int t_width, int t_height, bool t_isFullScreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)																						// Initializing SDL
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL initialization failed: %s", SDL_GetError());
		return false;
	}

	m_window = SDL_CreateWindow(t_title, t_xpos, t_ypos, t_width, t_height, t_isFullScreen ? SDL_WINDOW_FULLSCREEN : 0);		// Creating the main widow

	// Checking if the window was created correctly
	if (!m_window)
	{
		SDL_LogError(SDL_LOG_CATEGORY_RENDER, "Window initialization failed: %s", SDL_GetError());
		return false;
	}

	renderer = SDL_CreateRenderer(m_window, -1, 0);																				// Creating the renderer

	// Checking if the renderer was created correctly
	if (!renderer)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Renderer initialization failed: %s", SDL_GetError());
		return false;
	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	return true;
}

void handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

int main(int argc, char *args[])
{
	int TARGET_FRAME_RATE = 60;
	int spriteSize = 32;
	int animationFrames = 4;
	int animationSpeed = 400;
	std::string animarionDirectory;

	// Framerate
	std::cout << "Enter the desired framerate (default: 60):" << std::endl;

	int framRateAux = 0;
	std::cin >> framRateAux; std::cout << std::endl;

	if (framRateAux > 0)
	{
		TARGET_FRAME_RATE = framRateAux;
	}

	// Directory
	std::cout << "Enter the directory where the file is stored in inside the 'Animations' folder (this file should only contain this animation, and the path should not contain spaces):" << std::endl;

	std::cin >> animarionDirectory; std::cout << std::endl;

	// Sprite Size
	std::cout << "Enter the size of the sprite (default: 32):" << std::endl;

	std::cin >> spriteSize; std::cout << std::endl;

	// Animation Frames
	std::cout << "Enter the amount of frames in the animation:" << std::endl;

	std::cin >> animationFrames; std::cout << std::endl;

	// Animation Speed
	std::cout << "Enter the play speed(default: 400):" << std::endl;

	std::cin >> animationSpeed; std::cout << std::endl;

	if (init("Simple Animation Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, false))
	{
		isRunning = true;
	}

	Sprite *sprite = new Sprite(renderer, animationFrames, spriteSize, animationSpeed, "Animations/" + animarionDirectory);

	Uint32 frameStart;

	Timer* timer = Timer::instance();

	while (isRunning)
	{
		timer->update();

		handleEvents();

		if (timer->deltaTime() >= (1.f / TARGET_FRAME_RATE))
		{
			SDL_RenderClear(renderer);

			sprite->update();

			SDL_RenderPresent(renderer);

			timer->reset();
		}
	}

	return 0;
}
