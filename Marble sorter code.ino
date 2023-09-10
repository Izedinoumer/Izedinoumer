#include <Servo.h>
int pulsePin = 7;
int prescale0Pin = 3;
int prescale1Pin = 4;
int colorSelect0pin = 5;
int colorSelect1pin = 6;

int serv0 = 8;
int serv1 = 9;

Servo servoR;
Servo servof;


void setup() {
servoR.attach(serv0);
servof.attach(serv1);

pinMode(prescale0Pin, OUTPUT);
pinMode(prescale1Pin, OUTPUT);

digitalWrite(prescale0Pin,HIGH);
digitalWrite(prescale1Pin, HIGH);

pinMode(colorSelect0pin,OUTPUT);
pinMode(colorSelect1pin,OUTPUT);
pinMode(pulsePin,INPUT);

Serial.begin(9600);
Serial.println("Color Reader");

pinMode(10,OUTPUT);

}


void loop()

{
servof.write(180);
delay(3000);
servof.write(130);
digitalWrite(10,HIGH);

long red=readRed();
long green=readGreen();
long blue = readBlue();
long white=readWhite();


if ((red<green)&&(red<blue))

{

Serial.println("RED");
Serial.println(red);

Serial.println(blue);

Serial.println(green);
Serial.println(white);

servoR.write(0);
delay(2000);
servof.write(45);
delay(2000);

}


if((green < red) && (green < blue))

{

Serial.println("GREEN");
Serial.println(red);

Serial.println(blue);

Serial.println(green);
Serial.println(white);

servoR.write(45);
delay(2000);
servof.write(45);
delay(2000);

}

if ((blue < green) && (blue < red) && (red > 100))

{

Serial.println("BLUE");
Serial.println(red);

Serial.println(blue);

Serial.println(green);
Serial.println(white);

servoR.write(90);
delay(2000);
servof.write(45);
delay(2000);

}

if ((white<40) && (green<40 )&& (red<40))

{

Serial.println("WHITE");
Serial.println(red);

Serial.println(blue);

Serial.println(green);
Serial.println(white);

servoR.write(135);
delay(2000);
servof.write(45);
delay(2000);
}


//the next line turns off the LED
digitalWrite(10,LOW);
delay(1000);
//for your final project code to direct the marble to its proper color bin goes here
//this is the end of the loop
}

long readRed()

{

return (readColor(LOW,LOW));

}

long readGreen()

{

return(readColor(HIGH,HIGH));

}

long readBlue()

{

return(readColor(LOW,HIGH));

}

long readWhite()

{

return(readColor(HIGH,LOW));

}

long readColor(int bit0, int bit1)

{

digitalWrite(colorSelect0pin, bit0);

digitalWrite(colorSelect1pin, bit1);
//millis is a time  this is measuring time to read in from the pulsePin 
long start = millis();

for (int i = 0; i <1000; i++)

{

pulseIn(pulsePin,HIGH);

}

return (millis()-start);

}