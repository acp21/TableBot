#include <Arduino.h>

// Digital Pin to read IR signal from
// 1 = nothing detected, 0 = object detected
#define IR_PIN 8

int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(IR_PIN, INPUT);
}

void loop() {
  val = digitalRead(IR_PIN);
  Serial.println(val);
  delay(1000);
}