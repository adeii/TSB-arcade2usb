/*
 * c64mini-arcade2usb-converter.ino
 * 
 * C64 Mini Arcade Joystick to USB Converter.
 * 
 * Written & released in 2019 by M.F. Wieland (TSB)
 * 
 * This work is licensed under the terms of the MIT license.  
 * For a copy, see <https://opensource.org/licenses/MIT>.
 */

#include "joystick.h" 

// define buttons
const int pin_joystick_up = 2;
const int pin_joystick_down = 3;
const int pin_joystick_left = 4;
const int pin_joystick_right = 5;
const int pin_joystick_button1 = 6;
const int pin_joystick_button2 = 7;

int debounceDelay = 1; // debounce delay

void setup() {
  
  // setup input pins
  pinMode(pin_joystick_up, INPUT_PULLUP);       
  pinMode(pin_joystick_down, INPUT_PULLUP);       
  pinMode(pin_joystick_left, INPUT_PULLUP);       
  pinMode(pin_joystick_right, INPUT_PULLUP);       
  pinMode(pin_joystick_button1, INPUT_PULLUP);       
  pinMode(pin_joystick_button2, INPUT_PULLUP);       
}

void loop() {
  
  // Reset values for next loop..  
  Joystick.reset();
  
  // button 1 - c64 mini - button 1 (fire button)
  if (digitalRead(pin_joystick_button1) == LOW) {
    
    Joystick.button_press(0x40); 
    // see documentation to use other device
  }
  
  // button 2 - c64 mini - button 8 (menu)
  if (digitalRead(pin_joystick_button2) == LOW) {
    
    Joystick.button_press(0x200);
    // see documentation to use other device
  }
  // button up
  if (digitalRead(pin_joystick_up) == LOW) {
    
    Joystick.up();  
  }
  // button right
  if (digitalRead(pin_joystick_right) == LOW) {
    Joystick.right();
  }
  // button down
  if (digitalRead(pin_joystick_down) == LOW) {
    
    Joystick.down();
  }
  // button left
  if (digitalRead(pin_joystick_left) == LOW) {

    Joystick.left();
  }
  
  // update joystick actions
  Joystick.usb_update();
  
  delay(debounceDelay);
}
