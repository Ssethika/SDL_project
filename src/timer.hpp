#include "SDL_error.h"
#include "SDL_events.h"
#include "SDL_timer.h"
#include "util/loggers.hpp"
#include <functional>

/* using Callback = std::function<int(int, void*)>; */
/* const int NEXT_TICK = SDL_USEREVENT + 1; */ 
/* inline unsigned int TimerCallBack(unsigned int interval, void* param) { */
/* 			SDL_Event event; */
/* 			SDL_memset(&event, 0, sizeof(event)); */
/* 			event.type = NEXT_TICK; */
/* 			SDL_PushEvent(&event); */
/* 			return interval; */
/* } */
/* class Timer { */
/* public: */ 
/* 	unsigned int interval; */
/* 	void *param; */
/* 	SDL_TimerID timerID; */
/* 	const int NEXT_TICK = SDL_USEREVENT + 1; */ 
/* 	std::function<unsigned int(unsigned int, void*)> callback; */ 
	
/* 	Timer(int interval ,void* param) */
/* 		: interval(interval), param(param) { */
/* 		SDL_TimerID timerID = SDL_AddTimer(interval, TimerCallBack, param); */
/* 	} */
/* }; */

class Timer {
public:
    Timer(Uint32 interval, std::function<void()> callback)
        : interval(interval), callback(callback), timerID(0) {}

    ~Timer() {
        stop();
    }

    void start() {
        if (timerID == 0) {
            timerID = SDL_AddTimer(interval, Timer::timerCallback, this);
        }
    }

    void stop() {
        if (timerID != 0) {
            SDL_RemoveTimer(timerID);
            timerID = 0;
        }
    }

private:
    static Uint32 timerCallback(Uint32 interval, void* param) {
        Timer* timer = static_cast<Timer*>(param);
        if (timer->callback) {
            timer->callback();
        }
        return interval; // Return the interval to keep the timer repeating
    }

    Uint32 interval;
    std::function<void()> callback;
    SDL_TimerID timerID;
};
