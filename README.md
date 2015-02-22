# arduino


### definitions


#### Components

- **Transducer** - components that change one type of energy into electrical energy, or vice versa.
  - **Sensor** - things that convert other forms of energy into electrical energy.
  - **Actuator** - things that chance electrical energy into other forms of energy.
- **Resister** - component that resists the flow of energy by converting some of the energy to heat.
- **Switch** - component that interrupts the flow of energy, such as a pushbutton
- **Datasheet** - manuals for electrical components

#### Electrical circuits

- **Current** - the amount of electrical charge flowing past a specific point in your circuit, measured in amps (**A**)
- **Voltage** - the difference in energy between one point in a circuit and another, measured in volts (**V**)
- **Resistance** - how much a component resists the flow of electrical energy, measured in ohms (**Ω**)
- **Anode** - positive side, connects to power
- **Cathode** - negative side, connects to ground
- **Series** - components in series come one after the other
- **Ohm's Law** - V = I*R, I = V/R, R = V/I

#### Board

- **Pins A0-A5** - analog pins that report back a value between 0-1023, which maps to a range from 0-5 volts

#### Programming

- **Argument** - information that you pass to functions, goes inside the parenthesis
- **Variable** - a place for storing information in the Arduino's memory. Variables can change.
  - *int* - integer
  - *float* - floating point number, use for numbers that can be expressed with decimals
- **Constants** - similar to variables, but they cannot change.
- **ADC** - Analog to Digital Converter

##### Functions
- ```setup()``` runs once when the Arduino is first powered on
- ```loop()``` runs continuously after the ```setup()``` has completed
- ```pinMode()``` configures the digital pins on the Arduino board to be either inputs or outputs
- ```analogRead()``` checks the voltage level on an analog input, e.g., A0-A5
- ```digitalRead()``` checks the voltage level on a digital input
- ```digitalWrite()``` sends voltage info to a pin, and expects 2 arguments: to which pin to send the info, and the value to set the pin, e.g., ```HIGH``` or ```LOW```
- ```delay()``` stops the Arduino from exceuting anything for a period of time, argument is in milliseconds

##### Methods
- ```Serial.begin()``` opens up a connection between the Arduino and the computer, argument is the the speed at which the arduino will communicate
- ```Serial.print()``` sends information from the Arduino to a connected computer
