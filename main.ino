const int lightSensorPin=5;
const int waterSensorPin=6;
const int atmosSensorPin=7;
const int windSensorPin=8;

int lightSensorValue;
int waterSensorValue;
int atmosSensorValue;
int windSensorValue;

bool run=false;

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
    if (Serial.available()>0) {
        if (Serial.read()==("start",DEC)) {run=true;}
        if (Serial.read()==("stop",DEC)) {run=false;}
    }

    if (run==true) {
        lightSensorValue=analogRead(lightSensorPin);
        Serial.print("Light Sensor Value : ");
        Serial.println(lightSensorValue);

        waterSensorValue=analogRead(waterSensorPin);
        Serial.print("Ground humidity Sensor Value : ");
        Serial.println(waterSensorValue);

        atmosSensorValue=analogRead(atmosSensorPin);
        Serial.print("Atmospheric pressure Sensor Value : ");
        Serial.println(atmosSensorValue);

        windSensorValue=analogRead(windSensorPin);
        Serial.print("Wind Sensor Value : ");
        Serial.println(windSensorValue);

        delay(1000);
    }
}