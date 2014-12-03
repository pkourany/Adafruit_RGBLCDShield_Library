// Simple Interrupt Example based on https://github.com/pkourany/Adafruit_RGBLCDShield_Library/blob/master/examples/Interrupt/interrupt.ino
// added mcp.readGPIOAB() to reset Interrupt --> only this is functional
 

#include "Adafruit_MCP23017/Adafruit_MCP23017.h" 
 
Adafruit_MCP23017 mcp;
 
byte ledPin=D7;
 
// Interrupts from the MCP will be handled by this PIN
byte SparkIntPin=D3;

volatile uint8_t flashes=0;
 
// Two pins at the MCP (Ports A/B where some buttons have been setup.)
// Buttons connect the pin to grond, and pins are pulled up.
byte mcpPinA=1;		//UP button on shield
byte mcpPinB=2;		//DOWN button on shield

void setup(){
 
  Serial.begin(9600);  
  Serial.println("MCP23007 Interrupt Test");
 
  pinMode(SparkIntPin,INPUT);
  pinMode(ledPin, OUTPUT);  // use the LED as debugging
 
  mcp.begin();      // use default address 0
  
  // We mirror INTA and INTB, so that only one line is required between MCP and Arduino for int reporting
  // The INTA/B will not be Floating 
  // INTs will be signaled with a LOW
  mcp.setupInterrupts(true,false,LOW);
 
  // configuration for a button on port A
  // interrupt will triger when the pin is taken to ground by a pushbutton
  mcp.pinMode(mcpPinA, INPUT);
  mcp.pullUp(mcpPinA, HIGH);  // turn on a 100K pullup internally
  mcp.setupInterruptPin(mcpPinA,CHANGE); 
 
  // similar, but on port B.
  mcp.pinMode(mcpPinB, INPUT);
  mcp.pullUp(mcpPinB, HIGH);  // turn on a 100K pullup internall
  mcp.setupInterruptPin(mcpPinB,CHANGE);
  
   // Spark Interupt 
  attachInterrupt(SparkIntPin, handleInterrupt, FALLING);
  
  //This will clear interrupts on MCP prior to entering main loop
  mcp.readGPIOAB();
   
   
 
}
 
void handleInterrupt(){
    
  Serial.println("Interrupt detected!");
  
  // Get more information from the MCP from the INT
  uint8_t pin=mcp.getLastInterruptPin();
  uint8_t val=mcp.getLastInterruptPinValue();
  
  // We will flash the led 1 or 2 times depending on the PIN that triggered the Interrupt
  // 3 and 4 flases are supposed to be impossible conditions... just for debugging.
  if(pin==mcpPinA) flashes=1;
  if(pin==mcpPinB) flashes=2;
  if(val!=LOW) flashes=3;
 
  //this will clear the MCP interrupt
  mcp.readGPIOAB();

}
 
 /**
 * main routine: show flashes of the interrupt routine
 */
void loop(){
      
    if (flashes > 0) {
        // simulate some output associated to this
        delay(100);
        digitalWrite(ledPin,HIGH);
        delay(100);
        digitalWrite(ledPin,LOW);
        flashes--;
    }
  
}