// https://medium.com/@wilko.vehreke/more-gpios-for-the-esp8266-with-the-mcp23017-b89f5e15cde3
// https://www.instructables.com/id/Adding-an-MCP23017-IO-Extender-to-Arduino-or-ESP82/

#include <Wire.h>
#include "Adafruit_MCP23017.h"
// Instance of MCP23017 library
Adafruit_MCP23017 mcp0;
Adafruit_MCP23017 mcp1;
void setup() {  
  // Initialize both MCP23017 at address 0x20
  mcp0.begin(0);
  // Initialize both MCP23017 at address 0x21
  mcp1.begin(1);
  
  // Define GPA0 (physical pin 21) as output pin on both MCPs
  mcp0.pinMode(0, OUTPUT);
  mcp1.pinMode(0, OUTPUT);
}
void loop() {
  delay(100);
  
  // Switch one LED on and one off
  mcp0.digitalWrite(0, HIGH);
  mcp1.digitalWrite(0, LOW);
  
  delay(100);
  
  // Reverse the states of the LEDs
  mcp0.digitalWrite(0, LOW);
  mcp1.digitalWrite(0, HIGH);
}
