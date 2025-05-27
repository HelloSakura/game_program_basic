#include"Instrumentor.h"
#include<algorithm>

Instrumentor::Instrumentor()
	:m_currentSession(nullptr), m_profileCount(0)
{
}

void Instrumentor::beginSession(const std::string& name, const std::string& filePath)
{
	m_outputStream.open(filePath);
	writeHeader();
	m_currentSession = new InstrumentationSession(name);
}

void Instrumentor::endSession()
{
	writeFooter();
	m_outputStream.close();
	delete m_currentSession;
	m_currentSession = nullptr;
	m_profileCount = 0;
}

void Instrumentor::writeProfile(const ProfileResult& result) {
	if (m_profileCount++ > 0) {
		m_outputStream << ",";
	}

	std::string name = result.Name;
	std::replace(name.begin(), name.end(), '"', '\'');

	m_outputStream << "{";
	m_outputStream << "\"cat\":\"function\",";
	m_outputStream << "\"dur\":" << (result.end - result.Start) << ",";
	m_outputStream << "\"name\":\"" << name << "\",";
	m_outputStream << "\"ph\":\"X\",";
	m_outputStream << "\"pid\":0,";
	m_outputStream << "\"tid\":"<<result.ThreadID<<",";
	m_outputStream << "\"ts\":" << result.Start;
	m_outputStream << "}";

	m_outputStream.flush();
}

void Instrumentor::writeHeader()
{
	m_outputStream << "{\"otherData\":{}, \"traceEvents\":[";
	m_outputStream.flush();
}

void Instrumentor::writeFooter() {
	m_outputStream << "]}";
	m_outputStream.flush();
}

Instrumentor& Instrumentor::GetInstance() {
	static Instrumentor* instance = new Instrumentor();
	return *instance;
}


