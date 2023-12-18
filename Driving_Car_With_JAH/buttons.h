#ifndef BUTTONS_H
#define BUTTONS_H


// Initial Setup for both buttons and enabeling them as interrupts.
void buttonSetup();

//ISR for setting driving false/true
void stopButtonISR();   // red button
void startButtonISR();// black button


#endif //BUTTONS_H
