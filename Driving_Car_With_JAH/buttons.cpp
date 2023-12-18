#include <WInterrupts.c>
#include "buttons.h"
#include "SoftSerial.h"

#define startButtonDDR DDRD
#define startButtonPORT PORTD
#define startButtonPINREG PIND
#define startButtonPin 3

#define stopButtonDDR DDRD
#define stopButtonPORT PORTD
#define stopButtonPINREG PIND
#define stopButtonPin 2

extern bool driving;

void buttonSetup(){
  // define both Pins as inputs
  //interrupts(); // should not be necessary. For safety
  
  startButtonDDR  &= ~(1 << startButtonPin);
  startButtonPORT |=  (1 << startButtonPin); // PULLUP
  stopButtonDDR   &= ~(1 << stopButtonPin);
  stopButtonPORT  |=  (1 << stopButtonPin); // PULLUP

  //attachInterrupt(digitalPinToInterrupt(pin), ISR, mode) (recommended)
  attachInterrupt(digitalPinToInterrupt(stopButtonPin), stopButtonISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(startButtonPin), startButtonISR, FALLING);  
}

void stopButtonISR(){   // red button
  driving = false;
  SoftSerial.println("Pressed STOP Button");
}
void startButtonISR(){  // black button
  driving = true;
  SoftSerial.println("Pressed START Button");
}
