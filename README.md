Introduction
============
This is clone of project "MiniC64 arcade joystick to USB converter" by I am TSB.
Original project was on GitHub, but was migrated to https://gitlab.com/iamtsb/c64mini-arcade2usb-converter
With this converter you can use an old Arcade joystick on a C64 Mini.
It is converting the signal from the old type connector (DB9/Atari-based) to USB.
It can be used on a stock C64 Mini machine, without any modifications.
It will also work under Windows/linux with Vice

Modifications
=============
My target was to revive old Atari/Amiga/C64 joystick and use it on PC and Android phone/tablet.
The simpliest and the cheapest PCB to for this project is clone of Arduino Pro Micro. (From P.R.C. about 3$)
Original SparkFun Pro Micro is about 20$. So I got chinese clone, ATmega32U4 cpu, 3.3V 8MHz clock.
Original project is for Pro Micro, 5V 16MHz and PC detects connected device as Arduino Leonardo or Arduino Pro Micro.
Mine was detected as LilyPad USB, which is flower-shape device also from SparkFun. But it is definitely not.

After modding C:\Program Files (x86)\Arduino\hardware\arduino\avr\boards.txt
*.build.vid=0x22BA
*.build.pid=0x1020
*.build.usb_product="C64Mini Arcade to USB converter"

for both leonardo and lilypadusb, setting Arduino IDE 1.8.9 (Board: Arduino Leonardo, next time LilyPad USB, and certain port COMx) and uploading sketch c64mini-arcade2usb-converter.ino. Mine USB device got lost and identifies as Unknown device. No other uploading could be done, no other devices could be install....

Good news 1:
Solder touch button between terminals RESET and GND. One click reset device, double click put device to bootloader mode for 8 seconds (seems fewer). PC detects is as LilyPad USB booloader adapter for short time. So you could upload something else, blank eeprom or EVEN flash another/stock/custom BootLoader to device (if you had another Arduino device, AVR programer or DIY Paraller Programer).
But nothing restore devices...

Good news 2:
Most for devices use ATmega328P or ATmega168 cpu, 5V, 16 MHz...but there was not support for mine in Adruino IDE.
SparkFun on the other hand, has better support and you could add devices but adding:
    
    https://raw.githubusercontent.com/sparkfun/Arduino_Boards/master/IDE_Board_Manager/package_sparkfun_index.json

in File -> Preferences -> Additional Boards Manager URL. Nice adding. Tools -> Boards submenu got many new SparkFun devices!!!
One of them is Board: SparkFun Pro Micro, Processor: ATmega32U4 3.3V 8MHz. That is device what really works!!!
Additional boards are defined in C:\Users\Adeii\AppData\Local\Arduino15\packages\SparkFun\hardware\avr\1.1.12\boards.txt
Turn off Arduino IDE, edit boards.exe to mod that works:
promicro.build.usb_product="C64Mini Arcade"
promicro.build.vid=0x22BA
promicro.menu.cpu.8MHzatmega32U4.build.pid=0x1020

Verify, put device to bootloader mode, upload ...done. Devices is detected as C64Mini Arcade. Drivers is missing on Windows XP/7.
Needs for manually install: update driver for C64Mini Arcade, manualy add HID device, HID GameController and thats it!

Documentation
=============
Full documentation can be found on https://www.tsb.space/projects/c64-mini-arcade2usb-converter/
