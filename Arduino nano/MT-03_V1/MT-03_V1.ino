
#include <Servo.h>

Servo servo;
const int buttonPin = 7;
int buttonState = 0;

void setup() {
  servo.attach(10);
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
    servo.write(135);
  }
}
