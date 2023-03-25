#include "Arduino.h"
#include "esp32/esp32.h"
#include "InternetTime.h"

SoftwareSerial esp_serial(2,3);
Esp32::Wifi wifi(&esp_serial);
InternetTime time_client(&esp_serial);

void setup(){
    Serial.begin(115200);
    esp_serial.begin(115200);

    if(wifi.restart()){
        Serial.println("Wifi restart successful");
    }

    if(wifi.connect_to_ap("Ot Dieu", "abcd@1234")){
        Serial.println("Connected to Wifi");
    }

}


void loop(){
    if(time_client.update()){
        Serial.printf("Year %d\r\n", time_client.getYear());
        Serial.printf("Month %d\r\n", time_client.getMonth());
        Serial.printf("Day %d\r\n", time_client.getDay());
        Serial.printf("Hour %d\r\n", time_client.getHour());
        Serial.printf("Minute %d\r\n", time_client.getMinute());
        Serial.printf("Second %d\r\n", time_client.getSecond());
    }
    delay(5000);
}