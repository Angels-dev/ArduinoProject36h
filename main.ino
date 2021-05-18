const int lightSensorPin=5;
const int waterSensorPin=6;
const int atmosSensorPin=7;
const int windSensorPin=8;

int lightSensorValue;
int waterSensorValue;
int atmosSensorValue;
int windSensorValue;

void setup()
{
    pinMode(lightSensorPin,INPUT);
    pinMode(waterSensorPin,INPUT);
    pinMode(atmosSensorPin,INPUT);
    pinMode(windSensorPin,INPUT);
    Serial.begin(1000);
}

void loop()
{
    lightSensorValue=analogRead(lightSensorPin);
    Serial.write("Light Sensor Value : ");
    Serial.write(lightSensorValue);

    waterSensorValue=analogRead(waterSensorPin);
    Serial.write("Ground humidity Sensor Value : ");
    Serial.write(waterSensorValue);

    atmosSensorValue=analogRead(atmosSensorPin);
    Serial.write("Atmospheric pressure Sensor Value : ");
    Serial.write(atmosSensorValue);

    windSensorValue=analogRead(windSensorPin);
    Serial.write("Wind Sensor Value : ");
    Serial.write(windSensorValue);

    delay(1000);
}