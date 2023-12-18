#ifndef SOFTSERIAL_H
#define SOFTSERIAL_H

#include <SoftwareSerial.h>

#define BAUDRATE_BLUETOOTH_MODULE 9600
#define BAUDRATE_SERIAL_MONITOR 9600

extern SoftwareSerial SoftSerial; // RX | TX pins.  Can be reassigned to other pins if needed

void serialSetup();

void SoftSerialTest();



#endif //SOFTSERIAL_H
