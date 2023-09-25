#include <Servo.h>

#define trigPin1 5
#define echoPin1 6

#define trigPin2 7
#define echoPin2 8

//#define pump1 2
//#define pump2 4

Servo servo1,servo2;



long duration, distance, RightSensor,LeftSensor;

void setup()
{
Serial.begin (9600);

pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);

pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
    
 //   pinMode(pump1, OUTPUT);
 //   pinMode(pump2, OUTPUT);

//    digitalWrite(pump1, HIGH);
//    digitalWrite(pump2, HIGH);
    
    
    servo1.attach(2); 
    servo2.attach(3); 
    
    servo1.write(0);
    servo2.write(0);
    
}



void loop()
 {

SonarSensor(trigPin1, echoPin1);
RightSensor = distance;

SonarSensor(trigPin2, echoPin2);
LeftSensor = distance;

Serial.print(LeftSensor);

Serial.println(RightSensor);

if(RightSensor<=20)
    {
     // digitalWrite(pump1, LOW);
        servo1.write(90);
        delay(1);
       // digitalWrite(pump1, HIGH);
  // Serial.print("PUMP 1");
    }
    
    else
        {
         //digitalWrite(pump1, HIGH);
        servo1.write(0);
        }

if(LeftSensor<=20)
    {
     // digitalWrite(pump2, LOW);
        servo2.write(90);
        delay(1);
      //  digitalWrite(pump2, HIGH);
   //  Serial.print("PUMP 2");
    }
    
    else
        {
       //  digitalWrite(pump2, HIGH);
        servo2.write(0);
        }

//delay(1);

}

void SonarSensor(int trigPin,int echoPin)
{

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

}