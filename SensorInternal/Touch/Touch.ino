// set pin numbers
const int onPin = 4; 
const int offPin = 14;

const int ledPin = 16;


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
  pinMode (ledPin, OUTPUT);
}

void loop(){
  // read the state of the pushbutton value:
  onValue = touchRead(onPin);
  offValue = touchRead(offPin);

  if (offValue < threshold) {
    ledInt = 0;
  }  
  if(onValue < threshold){
    // turn LED on
    ledInt = 1;
  }

  if (ledInt == 1){
    digitalWrite(ledPin, HIGH);
  }  else {
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}
