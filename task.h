#ifndef __TASK_H
#define __TASK_H

#include "common.h"

void startTimerShowTips();
void startTimerQueryWeather();
extern String scrollText[5];
extern hw_timer_t *timerQueryWeather;
extern hw_timer_t *timerShowTips;
extern NowWeather nowWeather;
extern FutureWeather futureWeather;
extern enum CurrentPage currentPage;
extern unsigned int timerCount;
void drawWeatherContent();
void drawFutureWeatherPage();
void drawWeatherPage();
void drawTimerPage();
void drawResetPage();
void drawThemePage();
void drawDateWeek();
void drawAirPage();
void drawNumsByCount(unsigned int count);
void startRunner();
void executeRunner();
void disableAnimScrollText();
void enableAnimScrollText();

#endif

