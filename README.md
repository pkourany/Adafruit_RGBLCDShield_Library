This is a library for the Adafruit RGB 16x2 LCD Shield 

!!! Adapted for Spark Core by Paul Kourany, Nov 2014 !!!

Pick one up at the Adafruit shop! ---------> 
http://http://www.adafruit.com/products/714 

This new Adafruit shield makes it easy to use a 16x2 Character LCD. We 
really like the range of LCDs we stock in the shop, such as our classic 
blue & white as well as the fancy RGB negative and RGB positive. 
Unfortunately, these LCDs do require quite a few digital pins, 6 to 
control the LCD and then perhaps another 3 to control the RGB backlight 
for a total of 9 pins. That's half of the pins available on a classic 
Arduino! 

With this in mind, we wanted to make it easier for people to get these 
LCD into their projects so we devised a shield that lets you control a 
16x2 Character LCD, up to 3 backlight pins AND 5 keypad pins using only 
the two I2C pins on the Arduino! The best part is you don't really lose 
those two pins either, since you can stick i2c-based sensors, RTCs, etc 
and have them share the I2C bus. This is a super slick way to add a 
display without all the wiring hassle. 

Spark Core
----------
No pull-up resistors are required for I2C as they are included on the
shield.

An extra example app (interrupt.ino) has been added which demonstrates
MCP23017 interrupts.  For this example to work, a wire must be soldered
to pin 20 (INTA) of the MCP23017 and connected to pin D3 of the Spark Core
since it is 5V tolerant.
