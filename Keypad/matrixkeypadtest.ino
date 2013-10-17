#include <Keypad.h>

// Example grabbed from http://playground.arduino.cc/Main/KeypadTutorial
/*  Basic test of keypad library using old API
 *
 */
#include <Keypad.h>

const byte ROWS = 6; // Four rows
const byte COLS = 4; // six columns
// Define the Keymap
// letting X=CAN; !=BS; ?=ENT
char keys[ROWS][COLS] = {
  {'C','8','4','0'},
  {'D','9','5','1'},
  {'E','A','6','2'},
  {'F','B','7','3'},
  {'X','<','>','!'},
  {'*','^','v','?'}
};
// Connect keypad ROW0-3 to these Arduino pins.
byte colPins[COLS] = { 36, 38, 40, 42 };
// Connect keypad COL0-5 to these Arduino pins.
byte rowPins[ROWS] = { 32,30,28,26,24,22 }; 

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#define ledpin 13

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char key = kpd.getKey();

  if(key)  // Check for a valid key.
  {
        Serial.println(key);
  }
}
