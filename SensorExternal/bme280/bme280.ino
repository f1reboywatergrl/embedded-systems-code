#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; 
unsigned long delayTime;
float initialAltitude;
void setup() {
  Serial.begin(9600);
  Serial.println(F("BME280 test"));
  bool status;
  status = bme.begin(0x76);  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  Serial.println("-- Default Test --");
  delayTime = 1000;
  Serial.println();
  initialAltitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
}

void loop() { 
  printValues();
  delay(delayTime);
  pinMode(LED_BUILTIN, OUTPUT);
}

void printValues() {
  Serial.print("Temperature = "); Serial.print(bme.readTemperature());  Serial.println(" *C");
  
  Serial.print("Pressure = ");  Serial.print(bme.readPressure() / 100.0F);  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  if (bme.readAltitude(SEALEVELPRESSURE_HPA) - initialAltitude > 0.50) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  Serial.println(" m");

  Serial.print("Initial Altitude ");  Serial.print(initialAltitude);  Serial.println(" m");
  Serial.print("Humidity = ");  Serial.print(bme.readHumidity()); Serial.println(" %");
  
  Serial.println();
}
