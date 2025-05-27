#pragma once
#include<string>
#include<fstream>


struct ProfileResult {
	std::string Name;
	long long Start, end;
	uint32_t ThreadID;
};

struct InstrumentationSession {
	std::string Name;
	InstrumentationSession(const std::string& name) :Name(name) {}
};


class Instrumentor {
private:
	InstrumentationSession* m_currentSession;
	std::ofstream m_outputStream;
	int m_profileCount;

public:
	Instrumentor();
	void beginSession(const std::string& name, const std::string& filePath = "result.json");
	void endSession();
	void writeProfile(const ProfileResult& result);
	void writeHeader();
	void writeFooter();
	static Instrumentor& GetInstance();
};

