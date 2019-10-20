/*
    Author: Abdullah Nibah Hussain, S1800980
    
    Morse code receiver/translator.
    
 */
 
#include "MicroBit.h"

MicroBit uBit;
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);
MicroBitButton buttonB(MICROBIT_PIN_BUTTON_B, MICROBIT_ID_BUTTON_B);
//initialising variables
ManagedString currentData;
ManagedString morse[26] = {"..-", ".-...", ".-.-.", ".-..", "..", "...-.", ".--.", ".....", "...", "..---", ".-.-", "..-..", ".--", ".-.", ".---", "..--.", ".--.-", "..-.", "....", ".-", "...-", "....-", "..--", ".-..-", ".-.--", ".--.."} ;
ManagedString letter[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K" , "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

int main()  {
    //initialise the micro:bit runtime.
    uBit.init();
    bool pressed;
    uBit.buttonA.setEventConfiguration(MICROBIT_BUTTON_ALL_EVENTS);

    while(1) {
      int time = 0;
      uint64_t reading = system_timer_current_time();
      //if button A is pressed do the following
      while (buttonA.isPressed()){
        //translating morse code from dots and dashes to letters
        for(int i =0; i <= 26; i++) {
            if (currentData == morse[i]) {
                uBit.display.print(letter[i]);
            }   
         }
         currentData = ".";
      }
      //loop to check whether dot or dash
      while(uBit.io.P0.getDigitalValue()==1) {
        pressed = true;
        time = system_timer_current_time() - reading;
       }       
       if(pressed){
           //dot
           if(time < 250){
             uBit.display.print(".");
             currentData = currentData +".";
             uBit.sleep(time);

           }
           //dash 
           else {
             uBit.display.print("-");
             currentData = currentData +"-";
             uBit.sleep(time);
           }
        }
       pressed = false;
       uBit.display.clear();
    }
}

