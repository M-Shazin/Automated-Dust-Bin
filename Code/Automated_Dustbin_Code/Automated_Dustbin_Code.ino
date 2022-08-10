#include <SR04.h>
#include <Servo.h>
int Servo_Pin = 3;
int uls_trig = 5;
int uls_echo = 6;
Ultrasonic ultrasonic(uls_trig, uls_echo);
Servo myservo;

void setup() {
  myservo.attach(9);
}

void loop() {
  

}
