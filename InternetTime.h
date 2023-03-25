#ifndef INTERNET_TIME_H
#define INTERNET_TIME_H

#include "SoftwareSerial.h"
#include "esp32/esp32.h"
class InternetTime {
    private: 
        Esp32::Http http;
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
    public: 
        InternetTime(SoftwareSerial *_serial);
        ~InternetTime();
        bool update();
        int getYear();
        int getMonth();
        int getDay();
        int getHour();
        int getMinute();
        int getSecond();
}


#endif