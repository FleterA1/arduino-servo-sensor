#define echoPin 2
#define trigPin 3
#include <Servo.h>

long duration;
int distance;

Servo myServo;
int pos = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(13,OUTPUT);
  myServo.attach(5);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  if (distance <= 10) {
    if (distance >=1) {
    Serial.print("Distance: ");
    Serial.println(distance);
    digitalWrite(13, HIGH);
    myServo.write(180);
    }
    else {
    }
  } else {
    digitalWrite(13, LOW);
    myServo.write(90);
  }
}
