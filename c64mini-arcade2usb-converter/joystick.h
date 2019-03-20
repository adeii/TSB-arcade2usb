/*
 * joystick.h
 * 
 * Joystick routines to handle arcade to usb conversion
 * 
 * Written & released in 2019 by M.F. Wieland (TSB)
 * 
 * This work is licensed under the terms of the MIT license.  
 * For a copy, see <https://opensource.org/licenses/MIT>.
 */

#ifndef JOYSTICK_h
#define JOYSTICK_h

#include "HID.h"

//================================================================================
//  Joystick
//================================================================================

class Joystick_
{
private:
  uint16_t _buttons = 0x0;
  uint8_t _x_axis = 0x7F;
  uint8_t _y_axis = 0x7F;
  
public:
  
  Joystick_(void);

  void buttons(uint16_t b);
  void reset(void);
  void up();
  void right();
  void down();
  void left();
  void button_press(uint16_t b);
  void usb_update(); 
};
extern Joystick_ Joystick;

#endif
