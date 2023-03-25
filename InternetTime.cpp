#include "InternetTime.h"

InternetTime::InternetTime(SoftwareSerial *_serial){
    http = Esp32::Http(_serial);
}

InternetTime::~InternetTime(){

}

bool InternetTime::update(){
    if(http.request(Esp32::Http::GET, "http://103.170.122.203/time.php")){
        // Process response
        String response = http.getDataResponse();
        // Get Day
        int day_idx = response.indexOf(":", 0);
        day = response.substring(0,day_idx).toInt();
        // Get Month
        int month_idx = response.indexOf(":", day_idx + 1);
        month = response.substring(day_idx + 1,month_idx).toInt();
        // Get Year
        int year_idx = response.indexOf(":", month_idx + 1);
        year = response.substring(month_idx + 1,year_idx).toInt();
        // Get Hour
        int hour_idx = response.indexOf(":", year_idx + 1);
        hour = response.substring(year_idx + 1, hour_idx).toInt();
        // Get Minute
        int minute_idx = response.indexOf(":", hour_idx + 1);
        minute = response.substring(hour_idx + 1,minute_idx).toInt();
        // Get Year
        int second_idx = response.indexOf(":", minute_idx + 1);
        second = response.substring(minute_idx + 1,second_idx).toInt();
        return true;
    }
    return false;
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