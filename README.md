# Bare_Arduino_Cpp_Proj
Bare bones arduino project to be used as a template so I don't have to use the IDE.


THE FILE IS MOSTLY PORTED OVER FROM THE OTHER THING. PLS REVIEW WHEN I GET HOME TO CHECK IF IT WORKS.

ALSO ADD STUFF TO FLASH. ADD DEBUG STUFF.

MAYBE FIGURE OUT HOW TO ADD THE ARDUINO DEFAULT LIBRARY 


THIS FLASHES BTW
avrdude -v -p atmega328p -c arduino -P /dev/ttyUSB0 -b 115200 -D -U flash:w:build/Bare_Arduino_Cpp_release/Bare_Arduino_Cpp.hex:i
