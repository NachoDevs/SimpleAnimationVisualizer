#include "../include/Timer.h"

Timer* Timer::m_sInstance = NULL;

Timer* Timer::instance()
{
	if (m_sInstance == NULL)
	{
		m_sInstance = new Timer();
	}

	return m_sInstance;
}

void Timer::release()
{
	delete m_sInstance;
	m_sInstance = NULL;
}

Timer::Timer()
{
	reset();
	m_timeScale = 1.f;
}

Timer::~Timer()
{

}

void Timer::reset()
{
	m_startTicks = SDL_GetTicks();
	m_elapsedTicks = 0;
	m_deltaTime = .0f;
}

void Timer::timeScale(float t_ts)
{
	m_timeScale = t_ts;
}

float Timer::deltaTime()
{
	return m_deltaTime;
}

float Timer::timeScale()
{
	return m_timeScale;
}

void Timer::update()
{
	m_elapsedTicks = SDL_GetTicks() - m_startTicks;
	m_deltaTime = m_elapsedTicks * .001f;
}

