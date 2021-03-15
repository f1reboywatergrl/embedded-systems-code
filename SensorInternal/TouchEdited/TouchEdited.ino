// set pin numbers
const int onPin = 4; 
const int offPin = 14;

const int ledPinR = 16;
const int ledPinB = 18;
const int ledPinY = 19;


// change with your threshold value
const int threshold = 20;
// variable for storing the touch pin value 
int ledInt;

int onValue;
int offValue;

void setup(){
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  // initialize the LED pin as an output:
  pinMode (ledPinR, OUTPUT);
  pinMode (ledPinB, OUTPUT);
  pinMode (ledPinY, OUTPUT);
}

void loop(){
  // read the state of the pushbutton value:
  onValue = touchRead(onPin);
  offValue = touchRead(offPin);

  if (offValue < threshold) {
    Serial.println(offValue);
    
    digitalWrite(ledPinY, LOW);
    delay(200);
    digitalWrite(ledPinB, LOW);
    delay(200);
    digitalWrite(ledPinR, LOW);
    delay(200);
  }  
  if(onValue < threshold){
    Serial.println(onValue);
    digitalWrite(ledPinR, HIGH);
    delay(200);
    digitalWrite(ledPinB, HIGH);
    delay(200);
    digitalWrite(ledPinY, HIGH);
    delay(200);
  }Serial.println(onValue);
  delay(500);
}
