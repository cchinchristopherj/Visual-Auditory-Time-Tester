Visual Auditory Time Tester
=========================

Electrical Engineering Project (co-authored by Amy Wu)

Abstract
-------------------------

A device for testing reaction times to visual (LED light) and auditory signals (buzzer noise) was made. The reaction times, reasonably assumed to be below 15 seconds, are displayed by two sets of LEDs in binary. The two tests are performed in sequence, with the visual test first and the auditory test second. 

![software_schematic](https://github.com/cchinchristopherj/Visual-Auditory-Time-Tester/blob/master/software_schematic.png)

*Design Schematic for Prototype. Image produced by [Fritzing](http://fritzing.org/home/) open source CAD software.*

Techical Specifications
-------------------------

Requires: Breadboard, Arduino, Resistors, LEDs, Tactile Switch, Speaker, Wires

1.3K resistors were connected in series to the LEDs to avoid LED burnout. 

Included a pull up resistor to correct for button bouncing effects on voltage detected by the Arduino. A 1.3K resistor was used for this purpose 

Visual Test
-------------------------

The [code](https://github.com/cchinchristopherj/Visual-Auditory-Time-Tester/blob/master/arduinocode.ino) allows the Arduino to function as a binary up counter from 0-15. Specifically, the custom function “dectobinary” takes a number as input and uses the built-in Arduino function “bitRead” to read off the binary representation of the number. “dectobinary” then uses four LEDs - counterPin1-counterPin4 to indicates this binary representation. If an LED is on, it represents a 1 and if it is off, it represents a 0. The LSB is taken to be the bottommost LED. The program will count up from 0-15, driving the counterPin LEDs as described, until the button is pushed. When this occurs, the first for loop in the program’s main loop terminates and the counter stops. The state of the LEDs is saved in the four counterPin1State-counterPin4State variables (memory). A different set of LEDs - savePin1-savePin4 are then driven by these memory variables to visually represent the visual reaction time (the time it took for the participant to react to seeing the counter light up). Saving the values of the visual test in this different set of four LEDs allows the counterPin LEDs to once again be used as counters for the subsequent auditory test. 

Auditory Test
-------------------------

The auditory test then begins (after a small delay of 3 seconds). This time, a tone is played through the connected speaker using the Arduino function tone(). Once again, the program counts up from 0-15 in binary, driving the counterPin LEDs as described, until the button is pushed. When the button is pressed, the second for loop in the program’s main loop terminates and the counter stops. The state of the LEDs is saved in the four counterPin1State-counterPin4State variables (memory). counterPin1-counterPin4 are then driven by these memory variables, representing the time it took for the participant to react to the sound being played. By the end of the test, the four counterPins and four savePins are lit, representing the reaction time for the auditory and visual tests, respectively.

![hardware_schematic](https://github.com/cchinchristopherj/Visual-Auditory-Time-Tester/blob/master/hardware_schematic.png)

*Picture of Real Circuit Built in the Lab.*

Additional Notes
-------------------------

The majority of the work in-lab, besides setting up the circuit itself, was debugging the code. Points of debugging included syntactical issues (e.g. counterPin() only takes HIGH or LOW as the second parameter), unnecessary blocks of code, placement of function calls (particularly tone()), placement of delay(), and representing button state in the code (did not realize that the button would be open circuit only for as long as the button was held). Additionally, modifications were also made to the length of the delays included in the code--time indicated in the code were not accurate (indicating 1000ms does not translate into 1000ms when the code ran). 

Video Links
-------------------------

1. [Video 1](https://vimeo.com/215447857) (Normal Speed Implementation)

2. [Video 2](https://vimeo.com/215447788) (Fast Speed Implementation)
