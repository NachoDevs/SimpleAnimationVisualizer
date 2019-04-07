#include "../include/Sprite.h"

Sprite::Sprite(SDL_Renderer *t_renderer, int t_animationFrames, int t_spriteSize, int t_animationSpeed, std::string t_animationDirectory)
	:m_renderer(t_renderer), m_animationFrames(t_animationFrames), m_spriteSize(t_spriteSize), m_animationSpeed(t_animationSpeed) , m_animationDirectory(t_animationDirectory)
{
	setTexture(m_animationDirectory);

	init();
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(m_texture);
}

void Sprite::draw()
{
	SDL_RenderCopyEx(m_renderer, m_texture, &m_srcRect, &m_destRect, NULL, NULL, SDL_FLIP_NONE);
}

void Sprite::init()
{
	m_srcRect.w = m_spriteSize;
	m_srcRect.h = m_spriteSize;

	m_srcRect.x = 0;
	m_srcRect.y = 0;

	m_destRect.w = m_spriteSize * 5;
	m_destRect.h = m_spriteSize * 5;
	
	m_destRect.x = 400 - (m_destRect.w / 2);
	m_destRect.y = 320 - (m_destRect.h / 2);
}

void Sprite::setTexture(std::string t_animationDirectory)
{
	SDL_Surface* tmpSurface = IMG_Load(t_animationDirectory.c_str());
	m_texture = SDL_CreateTextureFromSurface(m_renderer, tmpSurface);

	SDL_FreeSurface(tmpSurface);
}

void Sprite::update()
{
	m_srcRect.x = m_srcRect.w * static_cast<int>((SDL_GetTicks() / m_animationSpeed) % m_animationFrames);

	draw();
}
