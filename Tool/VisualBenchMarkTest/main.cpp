#include<iostream>
#include"InstrumentationTimer.h"
#include"Instrumentor.h"
#include<cmath>
#include<thread>

void Function1() 
{
	PROFILE_FUNCTION();
	for (int i = 0; i < 1000; ++i) {
		std::cout << "Hello World : " << i << std::endl;
	}
}

void Function2()
{
	PROFILE_FUNCTION();
	for (int i = 0; i < 1000; ++i) {
		std::cout << "Hello World : " << sqrt(i) << std::endl;
	}
}

void BenchMarkTest()
{
	PROFILE_FUNCTION();
	std::thread a([]() {Function1(); });
	std::thread b([]() {Function2(); });

	a.join();
	b.join();
}


int main()
{
	Instrumentor::GetInstance().beginSession("Profile");
	BenchMarkTest();
	Instrumentor::GetInstance().endSession();
}