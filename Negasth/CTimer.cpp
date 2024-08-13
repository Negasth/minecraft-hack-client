#include "Negasth.h"

Negasth::CTimer::CTimer(std::chrono::milliseconds everyXms) {
	setEvery(everyXms);
}

bool Negasth::CTimer::isElapsed() {
	std::chrono::steady_clock::time_point timerNow = std::chrono::steady_clock::now();
	if (duration_cast<std::chrono::milliseconds>(timerNow - timerBegin) >= targetMs)
	{
		timerBegin = timerNow;
		return true;
	}
	return false;
}

void Negasth::CTimer::setEvery(std::chrono::milliseconds everyXms) {
	timerBegin = std::chrono::steady_clock::now();
	targetMs = everyXms;
}

void Negasth::CTimer::reset() {
	timerBegin = std::chrono::steady_clock::now();
}