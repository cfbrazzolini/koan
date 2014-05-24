#ifndef TIMER_H
#define TIMER_H

class Timer
{
public:
    Timer();
    void update(float);
    void restart();
    float getTime();
private:
	float time;
};

#endif // TIMER_H
