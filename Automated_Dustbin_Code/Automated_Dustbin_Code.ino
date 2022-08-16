#include "Ultrasonic.h"
#include <Servo.h>
int Servo_Pin = 3;
int uls_trig = 4;
int uls_echo = 2;
int ultraSonicRange = 60;//you can put value from 2 -> 400
Ultrasonic ultrasonic(uls_trig, uls_echo);
Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(Servo_Pin);
  myservo.write(90);
}

void loop() {
  int dist = ultrasonic.distanceRead(CM);
  Serial.println(dist);
  if(dist < 60){
    myservo.write(-180);
    delay(1000);
    }
    else{
      myservo.write(90);
      }
  delay(60);

}
