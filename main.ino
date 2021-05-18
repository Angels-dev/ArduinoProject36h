const int lightSensorPin=5;
const int waterSensorPin=6;
const int atmosSensorPin=7;
const int SensorPin=8;


void setup()
{
    pinMode(lightSensorPin,INPUT);
    pinMode(waterSensorPin,INPUT);
    pinMode(atmosSensorPin,INPUT);
    pinMode(SensorPin,INPUT);
    Serial.begin(9600);
}

void loop()
{
    digitalWrite(2,HIGH);
    delay(100);
    digitalWrite(2,LOW);
    delay(100);
}
