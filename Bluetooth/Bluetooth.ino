#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
String command = "";
int led = 4;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(led, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    int sentData = SerialBT.read();
//    Serial.write(sentData);
    if (sentData != 13){
      char sentCharacter = sentData;
      if (sentCharacter == '\n') {
        executeCommand();
        command="";
      }
      else{
        command += sentCharacter;
      }
    }
  }
  delay(20);
}
void executeCommand(){
  if (command == "ON"){
    Serial.println("Turning LED on!");
    digitalWrite(led, HIGH);
  }
  else if (command == "OFF"){
    Serial.println("Turning LED off!");
    digitalWrite(led, LOW);
  }
  else if (command == "BLINK"){
    Serial.println("Blinking!");
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
  }
  else {
    Serial.println("Command unrecognized. Discarding.");
  }
}
