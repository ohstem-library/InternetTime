#include "InternetTime.h"

InternetTime::InternetTime(SoftwareSerial *_serial){
    http = Esp32::Http(_serial);
}

bool InternetTime::update(){
    http.request(Esp32::Http::GET, "");
    // Process response
    
}

int InternetTime::getYear(){
    return year;
}

int InternetTime::getMonth(){
    return month;
}

int InternetTime::getDay(){
    return day;
}

int InternetTime::getHour(){
    return hour;
}

int InternetTime::getMinute(){
    return minute;
}

int InternetTime::getSecond(){
    return second;
}