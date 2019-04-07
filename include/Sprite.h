#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <string>

class Sprite
{

private:
	int m_animIndex = 0;
	int m_animationSpeed = 0;
	int m_animationFrames = 0;
	int m_spriteSize = 0;

	std::string m_animationDirectory;

	SDL_Rect m_srcRect, m_destRect;

	SDL_Renderer *m_renderer;

	SDL_Texture *m_texture;

public:

	Sprite(SDL_Renderer *t_renderer, int t_animationFrames, int t_spriteSize, int t_animationSpeed, std::string t_animationDirectory);

	~Sprite();

	void draw();

	void init();

	void setTexture(std::string t_animationDirectory);

	void update();

};