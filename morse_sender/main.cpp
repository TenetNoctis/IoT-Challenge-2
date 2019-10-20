/*
    Author: Abdullah Nibah Hussain, S1800980
    
    Morse code sender.
    
 */

#include "MicroBit.h"

MicroBit uBit;

MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);

int main() {
    // Initialise the micro:bit runtime.
    uBit.init();
    bool pressed = false;

    while(1) {
      uint64_t reading = system_timer_current_time();
      //if button a is pressed then it will send a signal to another microbit
      while (buttonA.isPressed()){
      pressed = true;
      uBit.io.P0.setDigitalValue(1);
    }
    
    uBit.io.P0.setDigitalValue(0);
    uint64_t time = system_timer_current_time()-reading;

        if(pressed){
          //hold for dash
          if(time > 500 && time < 2500){
            uBit.display.print("-");
            uBit.sleep(600);
          }
          //press for dot
          else if (time < 500){
            uBit.display.print(".");
            uBit.sleep(300);

          }
          pressed = false;
          uBit.display.clear();
        }
        uBit.io.P0.setDigitalValue(0);
      }

      release_fiber();

    }

