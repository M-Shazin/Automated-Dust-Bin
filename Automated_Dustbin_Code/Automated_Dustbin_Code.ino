//-----------------------------------------------------//  

 //By Shazin
 
//-----------------------------------------------------//  



//defining libraries
#include <Servo.h> //defined Servo motor library

#define echoPin 2 // attach pin D2 of Arduino to pin Echo of HC-SR04
#define trigPin 4 //attach pin D4 of Arduino to pin Trig of HC-SR04
#define servoPin = 3; //attach pin D3 of Arduino to pin data pin of Servo motor

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

Servo myservo; // create servo object to control a servo
void setup() {
  myservo.attach(servoPin); //Sets servoPin as Servo pin
  myservo.write(92); //rotation servo to 92 degree
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // Serial Communication is starting with 9600 of baudrate speed
  
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  /*checking weather the distance is leser than ultrasonic coverage distance 
  and rotating servo motor according to it.*/
  if(distance < 60){
    myservo.write(-180);
    delay(1000);
    }
    else{
      myservo.write(92);
      } 
  delay(60); //60 millisecond delay
}
