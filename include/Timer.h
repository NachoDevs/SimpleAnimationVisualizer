#pragma once

#include <SDL.h>

class Timer
{

private:

	static Timer* m_sInstance;

	unsigned int m_startTicks;
	unsigned int m_elapsedTicks;

	float m_deltaTime;
	float m_timeScale;

public:

	static Timer* instance();
	static void release();

	void reset();
	void timeScale(float t_ts);

	float deltaTime();
	float timeScale();

	void update();

private:

	Timer();
	~Timer();

};