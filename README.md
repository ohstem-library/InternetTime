# Internet Time
This library allow user to get time from Internet

## Prequisites
- ESP32's peripheral, installed at firmware. 
https://github.com/ohstem-library/esp32-at-firmware
- ESP32 Library for Arduino or YoloUno

## How to use
- Update Internet Time from Server
    ```
    bool InternetTime::update();
    ```
- Get Year
    ```
    int InternetTime::getYear();
    ```
- Get Month
    ```
    int InternetTime::getMonth();
    ```
- Get Day
    ```
    int InternetTime::getDay();
    ```
- Get Hour
    ```
    int InternetTime::getHour();
    ```
- Get Minute
    ```
    int InternetTime::getMinute();
    ```
- Get Second
    ```
    int InternetTime::getSecond();
    ```
