#include"InstrumentationTimer.h"
#include"Instrumentor.h"
#include<thread>

InstrumentationTimer::InstrumentationTimer(const char* name)
	:m_name(name), m_stopped(false)
{
	this->m_startTimePoint = std::chrono::high_resolution_clock::now();
}

void InstrumentationTimer::Stop()
{
	auto endTimepoint = std::chrono::high_resolution_clock::now();

	long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimePoint).time_since_epoch().count();
	long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

	std::cout << m_name << ": " << (end - start) << "ms\n";
	uint32_t threadID = std::hash<std::thread::id>{}(std::this_thread::get_id());
	Instrumentor::GetInstance().writeProfile({m_name, start, end, threadID});

	m_stopped = true;
}

InstrumentationTimer::~InstrumentationTimer()
{
	if (!m_stopped) {
		Stop();
	}
}
