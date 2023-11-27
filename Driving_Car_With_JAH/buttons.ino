#define startButtonDDR DDRD
#define startButtonPORT PORTD
#define startButtonPINREG PIND
#define startButtonPin 2

#define stopButtonDDR DDRD
#define stopButtonPORT PORTD
#define stopButtonPINREG PIND
#define stopButtonPin 3

inline void buttonSetup(){
  // define both Pins as inputs
  interrupts(); // should not be necessary. For safety
  
  startButtonDDR  &= ~(1 << startButtonPin);
  startButtonPORT |=  (1 << startButtonPin); // PULLUP
  stopButtonDDR   &= ~(1 << stopButtonPin);
  stopButtonPORT  |=  (1 << stopButtonPin); // PULLUP

  //attachInterrupt(digitalPinToInterrupt(pin), ISR, mode) (recommended)
  attachInterrupt(digitalPinToInterrupt(stopButtonPin), stopButtonISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(startButtonPin), startButtonISR, FALLING);  
}

void stopButtonISR(){
  driving = false;
  bluetoothModule.println("Pressed STOP Button");
}
void startButtonISR(){
  driving = true;
  bluetoothModule.println("Pressed START Button");
}
