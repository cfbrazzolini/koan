#include "Timer.h"

Timer::Timer()
{
	time = 0;
}

void Timer::update(float dt){
	time += dt;
}

void Timer::restart(){
	time = 0;
}

float Timer::getTime(){
	return time;
}
