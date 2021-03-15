const int buttonPin = 4;  // the number of the pushbutton pin
const int ledPin =  5;    // the number of the LED pin
const int buttonPin2 = 14;
const int ledPin2 = 15;
const int reverseButton = 18;
int buttonState = 0;
int buttonState2 = 0;
int reverseState = 0;
int currentButtonState;
int lastButtonState; 
void setup() {
  Serial.begin(115200);  
  // initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(reverseButton, INPUT_PULLUP);
  // initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  currentButtonState = digitalRead(reverseButton);
}
void loop() {
  // read the state of the pushbutton value
  lastButtonState    = currentButtonState;
  currentButtonState = digitalRead(reverseButton);
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  if (lastButtonState==HIGH and currentButtonState==LOW) {
    reverseState = !reverseState;
    digitalWrite(LED_BUILTIN, reverseState);
  }
  if ((buttonState2 == HIGH and reverseState==0) or (buttonState == HIGH and reverseState==1) ) {
    digitalWrite(ledPin2, HIGH);
  } else {
    digitalWrite(ledPin2, LOW);
  }
  
  if ((buttonState == HIGH and reverseState==0) or (buttonState2 == HIGH and reverseState==1)) {
    // turn LED on
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off
    digitalWrite(ledPin, LOW);
  }
}
