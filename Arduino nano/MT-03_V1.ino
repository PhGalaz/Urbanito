
#include <Servo.h>

Servo servo;
const int buttonPin = 9;
int buttonState = 0;

void setup() {
  servo.attach(12);
  pinMode(buttonPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(LED_BUILTIN, LOW);
    servo.write(80);

  } else {
    digitalWrite(LED_BUILTIN, HIGH);
    servo.write(125);
  }
}
