#include <Arduino.h>

// Digital Pin to read IR signal from
// 1 = nothing detected, 0 = object detected
#define IR_PIN 8

// Pins to control motor direction
// Each state needs to be opposite, one HIGH, one LOW
#define IN1 13
#define IN2 12
#define IN3 5
#define IN4 4

// Motor speed pins, use PWM and analogWrite() to control
#define ENA 6
#define ENB 5

// Ultrasonic sensor pins
#define ECHO_PIN 2
#define TRIG_PIN 3

long duration;
int distance;

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Initialize Pins
  pinMode(IR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Turn off all motors on boot
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  // Set motor speed to zero on boot
  analogWrite(ENA, LOW);
  analogWrite(ENB, LOW);

  digitalWrite(TRIG_PIN, LOW);
}

void loop() {

  // Handling Ultrasonic sensor.

  // Clears the TRIG_PIN condition
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  // Sets the TRIG_PIN HIGH (ACTIVE) for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // Reads the ECHO_PIN, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
}