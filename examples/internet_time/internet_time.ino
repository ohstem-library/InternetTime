#include "SoftwareSerial.h"
#include "esp32.h"
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
        Serial.print("Year: ");
        Serial.println(time_client.getYear());
        Serial.print("Month: ");
        Serial.println(time_client.getMonth());
        Serial.print("Day: ");
        Serial.println(time_client.getDay());
        Serial.print("Hour: ");
        Serial.println(time_client.getHour());
        Serial.print("Minute: ");
        Serial.println(time_client.getMinute());
        Serial.print("Second: ");
        Serial.println(time_client.getSecond());
    }
    delay(5000);
}