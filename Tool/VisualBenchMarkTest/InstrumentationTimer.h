#pragma once
#include<chrono>
#include<iostream>

#define PROFILING 1
#if PROFILING
#define PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCSIG__)
#else
#define PROFILE_SCOPE(name)
#define PROFILE_FUNCTION()
#endif

class InstrumentationTimer {
private:
	const char* m_name;
	std::chrono::time_point<std::chrono::steady_clock> m_startTimePoint;
	bool m_stopped;

public:
	InstrumentationTimer(const char* name);
	~InstrumentationTimer();
	void Stop();	
};