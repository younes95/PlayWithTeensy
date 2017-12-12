#include <Arduino.h>

void setup() {
    // put your setup code here, to run once:
    //Init LED for blinking
    pinMode(LED_BUILTIN, OUTPUT);
    //turn led on to show that the teensy is working
    digitalWrite(LED_BUILTIN, HIGH);
    //excuting 
    

    //turn led of when teensy finish his "mission"
    digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
   delay(1000);
}