#define sensorFront A2
#define sensorRight A0
#define sensorLeft A4

#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4

#define DDR_IN1 DDRD
#define PORT_IN1 PORTD
#define PINREG_IN1 PIND
#define PIN_IN1 7
#define DDR_IN2 DDRD
#define PORT_IN2 PORTD
#define PINREG_IN2 PIND
#define PIN_IN2 6
#define DDR_IN3 DDRD
#define PORT_IN3 PORTD
#define PINREG_IN3 PIND
#define PIN_IN3 5
#define DDR_IN4 DDRD
#define PORT_IN4 PORTD
#define PINREG_IN4 PIND
#define PIN_IN4 4

/*
  IN3 und IN4 sind die linken Räder
  IN3 < IN4 Auto fährt vorwärts
  IN3 > IN4 Auto fährt rückwerts
  
  IN1 und IN2 sind die rechten Räder
  IN1 < IN2 Auto fährt vorwärts
  IN1 > IN2 Auto fährt rückwerts  
*/

#include <Arduino.h>
#include "SoftSerial.h"

void motorSetup(){
  //define Pins as Outputs. (Should)
  DDR_IN1 |= (1 << PIN_IN1);
  DDR_IN2 |= (1 << PIN_IN2);
  DDR_IN3 |= (1 << PIN_IN3);
  DDR_IN4 |= (1 << PIN_IN4); 

}

void motorControl(){
  int distanceFront, distanceRight, distanceLeft;
  int diff;
  static int motorSpeed=200;


  distanceFront = analogRead(sensorFront);
  SoftSerial.print("vorne: ");
  SoftSerial.println(distanceFront);
  delay(25);
  distanceRight = analogRead(sensorRight);
  SoftSerial.print("Rechts: ");
  SoftSerial.println(distanceRight);
  delay(25);
  distanceLeft = analogRead(sensorLeft);
  SoftSerial.print("Links: ");
  SoftSerial.println(distanceLeft);
  delay(25);

  diff = distanceLeft - distanceRight;
  
  if(diff <= 50 && diff >= -50){ 
   
     if(distanceFront < 250){
      SoftSerial.println("Beschleunigen");
      while(motorSpeed<200){
        motorSpeed = motorSpeed+25;
        analogWrite(IN3, motorSpeed);
        PINREG_IN4 &= ~(1 << PIN_IN3);
        analogWrite(IN1, motorSpeed);
        PINREG_IN2 &= ~(1 << PIN_IN1);
      }
    delay(25);
    }
  
    if(distanceFront >= 250){
      SoftSerial.println("Bremsen");
      while(motorSpeed > 0){
         motorSpeed = motorSpeed-25 ;
        analogWrite(IN3, motorSpeed);
        PINREG_IN4 &= ~(1 << PIN_IN3);
        analogWrite(IN3, motorSpeed);
        PINREG_IN2 &= ~(1 << PIN_IN1);
      }
    }
    delay(25);
  }
  
  else if(distanceRight < distanceLeft){  // kurve Rechts
    SoftSerial.println("Rechts kurve");
    //Linken Räder
    analogWrite(IN3,100+(diff/4));
    PINREG_IN4 &= ~(1 << PIN_IN3);

    //Rechten Räder
    analogWrite(IN1,100-(diff/4));
    PINREG_IN2 &= ~(1 << PIN_IN1);
    delay(25);
  }
  else if(distanceRight > distanceLeft){    // kurve Links
    SoftSerial.println("kurve Links");
    //Linken Räder
    analogWrite(IN3,100-(diff/4));
    PINREG_IN4 &= ~(1 << PIN_IN3);

    //Rechten Räder
    analogWrite(IN1,100+(diff/4));
    PINREG_IN2 &= ~(1 << PIN_IN1);
    delay(25);
  }
  
    delay(1000);
}
