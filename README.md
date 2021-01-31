## Manipulate CPU fan speed reported to system making fan run slower. 


**What is this?**
Arduino / ATtiny85 based solution to manipulate the fan speed reported to PC system making fan run slower. 
HP Omen Ryzen are running a little noisy even at low demanding tasks. 
Even if the temp is low, about 40c. 
This circuit is cutting down the fan speed to half (no noise) in low demanding mode with continuing low 40c temp. 
As cooling demand rises, fan will go back to normal operations.

https://www.youtube.com/watch?v=ppQBuBrlFy8

**How does it work?**
The fan speed is controlled by the motherboard/system by a PWM signal to the fan.
Then fan reports back a its current rpm to the system.
On this computer (HP Omen Ryzen 2020) 200Hz (200 rpm per second) is 100% fan speed.
If the CPU temp is rising and the system wants to run fan at 50, itr will adjust the PWM signal until 100Hz is reached from the fan.

The HP Omen has a base fan speed of 80Hz, even during low CPU temp as 40c. This is not loud but still a bit annoying workiing with office task in a silent environment.
I tested disconnecting fan and noticed that the temperature is actually only rising with like two degrees so the fan does not do much when there are limited CPU load.
However you cannot run with the fan disconnected because the system will shut down after some time and the fan is needed when cpu load rises.

So then I decided to make a solution that makes the system think that the fan is running as normal when its actually running at half speed.
The solution is a frequency doubler, if fan output 40 pulses, the ATtiny will send out 80Hz to the PC system.
So now when fan is supposed to run att 80Hz, it actually runs at 40Hz which is silent. When demand rises to 140 Hz, the fan run att 70Hz.
But then going over 160Hz a treshold in the firmware of the ATtiny will bypass the pulses from the fan straight to the system so that the fan can run as normal in full speed. 
This is neccesary for heavy gaming etc.

**How to build**
This is an Arduino project with very simple code and circuit but you need some electronics and soldering skills.
To program, you need an Arduino Uno and use it as a programmer for the ATtiny.
There are numerous guides on the net on how to set this up.
Then you have to cut the dark grey cable beween fan and system and connect to the ATtiny in between.
3.3v power for the ATtiny can be found on the motherboard.
See our YouTube for details on connection points.


