int val = 0;
const int ledR = 16;
const int ledY = 4;

void setup() {
  Serial.begin(9600);
  pinMode (ledR, OUTPUT);
  pinMode (ledY, OUTPUT);
  pinMode (LED_BUILTIN, OUTPUT);
}

// put your main code here, to run repeatedly
void loop() {
  // read hall effect sensor value
  val = hallRead();
  // print the results to the serial monitor
  Serial.println(val);
  if (val > 45) {
     digitalWrite(ledR, HIGH);
     digitalWrite(ledY, LOW);
     digitalWrite(LED_BUILTIN, LOW);
  } else if (val < 0) {
    digitalWrite(ledR, LOW);
    digitalWrite(ledY, HIGH);
    digitalWrite(LED_BUILTIN, LOW);
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(ledR, LOW);
    digitalWrite(ledY, LOW);
  }
  delay(1000);
}
