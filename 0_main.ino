//#include <future>
//#include "1_sensors.ino"

const int motorPin=2;
const int lightSensorPin=5;
const int waterSensorPin=6;
const int atmosSensorPin=7;
const int windSensorPin=8;

const int lightWantedValue;
const int waterWantedValue;
const int atmosWantedValue;
const int windWantedValue;

int lightSensorValue;
int waterSensorValue;
int atmosSensorValue;
int windSensorValue;

int activateByLight;
int activateByWater;
int activateByAtmos;
int activateByWind;

bool run=false;

void setup()
{
    pinMode(motorPin,OUTPUT);
    pinMode(lightSensorPin,INPUT);
    pinMode(waterSensorPin,INPUT);
    pinMode(atmosSensorPin,INPUT);
    pinMode(windSensorPin,INPUT);

    Serial.begin(9600);
}

void loop()
{
    sensors();
    action();
}

void sensors() {
    Serial.println("Enter 'start' to launch the sensors, 'stop' to stop them.");

    if (Serial.available()>0) {
        if (Serial.read()==("start",DEC)) {run=true;}
        if (Serial.read()==("stop",DEC)) {run=false;}
    }

    if (run==true) {
        lightSensorValue=analogRead(lightSensorPin);
        Serial.print("Light Sensor Value : ");
        Serial.println(lightSensorValue);
        if (lightSensorValue>=lightWantedValue) {
            activateByLight=1;
            Serial.println("Warning, the light is superior than wanted, watering may enable !");
        }

        waterSensorValue=analogRead(waterSensorPin);
        Serial.print("Ground humidity Sensor Value : ");
        Serial.println(waterSensorValue);
        if (waterSensorValue<=waterWantedValue) {
            activateByWater=1;
            Serial.println("Warning, the ground humidity is inferior than wanted, watering may enable !");
        }

        atmosSensorValue=analogRead(atmosSensorPin);
        Serial.print("Atmospheric pressure Sensor Value : ");
        Serial.println(atmosSensorValue);
        if (atmosSensorValue==atmosWantedValue) {
            activateByAtmos=1;
            Serial.println("Warning, the atmospheric pressure is equal than wanted, watering may enable !");
        }

        windSensorValue=analogRead(windSensorPin);
        Serial.print("Wind Sensor Value : ");
        Serial.println(windSensorValue);
        if (windSensorValue>=windWantedValue) {
            activateByWind=1;
            Serial.println("Warning, the wind is superior than wanted, watering may enable !");
        }
    }
}

void action() {
    if (activateByLight&activateByWater&activateByAtmos&activateByWind) {
        Serial.println("Warning, enabling watering !");
        digitalWrite(motorPin,1);
    }
}
