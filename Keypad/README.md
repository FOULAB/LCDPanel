Matrix Keypad code
========

Got this working on an Arduino mega.  Note that the 4 rows must be strobed
and the 6 columns read.  Therefore you have to set up the matrix transposed
from what the keypad library expects.

Also, the panels have a buffer internally.  So if you press two keys in the
same column at the same time, the outputs are connected together, and the
fact that one is pulled high and one low... the backlight dims.  Its probably
getting hot inside if you do that.  So dont.  Ideally, switching one input
low, would make the others go to high impedance.  Alternately, could just skip
the buffer and let the Arduino drive the keypad directly.
