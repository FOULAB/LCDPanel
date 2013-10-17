#include <Keypad.h>

// Based on multikey example in keypad lib
/*  
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
unsigned long loopCount;
unsigned long startTime;
String msg;

void setup()
{
  Serial.begin(9600);
  loopCount = 0;
  startTime = millis();
  msg = "";
}

void loop()
{
    loopCount++;
    if ( (millis()-startTime)>5000 ) {
        Serial.print("Average loops per second = ");
        Serial.println(loopCount/5);
        startTime = millis();
        loopCount = 0;
    }

    // Fills kpd.key[ ] array with up-to 10 active keys.
    // Returns true if there are ANY active keys.
    if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
            {
                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                    msg = " PRESSED.";
                break;
                    case HOLD:
                    msg = " HOLD.";
                break;
                    case RELEASED:
                    msg = " RELEASED.";
                break;
                    case IDLE:
                    msg = " IDLE.";
                }
                Serial.print("Key ");
                Serial.print(kpd.key[i].kchar);
                Serial.println(msg);
            }
        }
    }
}
