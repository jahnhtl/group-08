#include <avr/io.h>

#include "Driving_Car_With_JAH.h"
#include "SoftSerial.h"
#include "buttons.h"
#include "Motor_controll.h"

bool driving = false;

int main(void)
{
  init();
  buttonSetup();
  serialSetup();
  while(true){
    do{ /* NOTHING */ }while(!driving);
    while(driving){ 
      delay(25);
      motorControl();
      SoftSerialTest();
    }
    
  }
  return 0;
}
