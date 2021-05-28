//#include <future>
//#include "1_sensors.ino"

const int lightSensorPin=5;
const int waterSensorPin=6;
const int atmosSensorPin=7;
const int windSensorPin=8;

void setup()
{
    pinMode(lightSensorPin,INPUT);
    pinMode(waterSensorPin,INPUT);
    pinMode(atmosSensorPin,INPUT);
    pinMode(windSensorPin,INPUT);
    Serial.begin(9600);
    Serial.println("Enter 'start' to launch the sensors, 'stop' to stop them.");
}

void loop()
{
    sensors();
}