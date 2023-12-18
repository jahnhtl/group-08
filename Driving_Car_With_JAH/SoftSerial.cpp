#include "SoftSerial.h"

SoftwareSerial SoftSerial(0, 1); // RX | TX pins.  Can be reassigned to other pins if needed

#define BAUDRATE_BLUETOOTH_MODULE 9600
#define BAUDRATE_SERIAL_MONITOR 9600

void serialSetup(){
  SoftSerial.begin(BAUDRATE_BLUETOOTH_MODULE);
//  Serial.begin(BAUDRATE_SERIAL_MONITOR);
}
void SoftSerialTest(){
  SoftSerial.print("Test of text  ");
  SoftSerial.println("An here should be a end of line at the end");
  SoftSerial.print("Test of number: ");
  SoftSerial.println(228922);
  SoftSerial.print("Test of boolean");
  SoftSerial.println(true);
  SoftSerial.print("Test of Float");
  SoftSerial.println(3.1415926);
  //SoftSerial.print("Test for C++ Syntax: \"%d\"",1);

  
/*  
    c = SoftSerial.read();*/
}
