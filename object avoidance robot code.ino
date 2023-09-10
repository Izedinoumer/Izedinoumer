
#include <Servo.h>
Servo leftServo;
Servo rightServo;
Servo extraServo;
int pingPin=4;
long int duration, distanceInches;
long distanceFront=0;//cm
int startAvoidanceDistance=20;//cm
long microsecondsToInches(long microseconds)
{
  return microseconds/74/2;
}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds/29/2;
}
long distanceCm(){
  pinMode(pingPin,OUTPUT);
  digitalWrite(pingPin,LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin,HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin,LOW);
  pinMode(pingPin,INPUT);
  duration=pulseIn(pingPin,HIGH);
  distanceInches=microsecondsToInches(duration);
  return microsecondsToCentimeters(duration);
}
void center()
{
pinMode(8,OUTPUT);

digitalWrite(8,HIGH);
delay(50);
digitalWrite(8,LOW);
delay(50);
digitalWrite(8,HIGH);
delay(50);
digitalWrite(8,LOW);
delay(50);
digitalWrite(8,HIGH);
delay(50);
digitalWrite(8,LOW);
delay(50);
digitalWrite(8,HIGH);
delay(50);
digitalWrite(8,LOW);
delay(50);
digitalWrite(8,HIGH);
delay(50);
digitalWrite(8,LOW);
delay(50);
digitalWrite(8,HIGH);
delay(50);
digitalWrite(8,LOW);
delay(50);


digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
leftServo.write(90);
rightServo.write(90);
delay(100);
digitalWrite(6,LOW);
delay(100);
}
void moveForward()
{
digitalWrite(8,HIGH);
  leftServo.write(180);
rightServo.write(0);
delay(1000);
//Need code here for forward
  }
  void turnAround()
  {
  digitalWrite(6,HIGH);
  tone(7,900,1000);
 leftServo.write(0);
 rightServo.write(0);
 

//Add code for turning and or obstacle avoidance
  delay(385);
  digitalWrite(6,LOW);
  
  delay(1000);

  }
  
  void setup()
  {
    leftServo.attach(2);
    rightServo.attach(3);
    extraServo.attach(5);
    pinMode(4,OUTPUT);
    pinMode(6,OUTPUT);
  }
  void loop ()
  {
    distanceFront=distanceCm();
    if(distanceFront>1){
      if(distanceFront<startAvoidanceDistance){
        center();
        turnAround();
 delay(100);
        }
  else{
    moveForward();
    delay(125);
  }

    }
  }
