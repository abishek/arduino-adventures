### Getting Started

Line followers are perhaps the easiest robots for getting started. In this repo, you'll see a quick example using an Arduino Uno. YOu'll need to edit the code a little to ensure it works for you. Most of the things to edit are the delay settings which will define how the motors respond to the stimulus.

### Wiring

The line follower sensors have a digital output and are connected to arduino uno pins 2, 3 and 4. They are powered off of the 3.3V and GND pins of the uno.

The motor driver uses the 5V and GND for the logic reference and the Arduino Vin for the power supply. In my case, I just use 4 AA batteries (6V tops) to power the entire bot. The left motor is connected to OUT3 and OUT4 of the L298A board. Right motor is connected to OUT1 and OUT2. The IN1, IN2, IN3 and IN4 are connected to arduino pins 5, 6, 9 and 10. I'll check in a wiring schematic soon.

The code is pretty straight forward and self explanatory. And yea, I haven't written C in a long time and it surely shows in the code ;-)

The chassis has been lying around for about 2 years now. So yeah, just put this together on that one. But perhaps getting a chassis for this build is not worth it. I'll have a next build where I don't plan to use a OTS chassis. Hopefully, that gives good ideas.

### References:

[Instructable link for L298A usage] (https://www.instructables.com/id/How-to-use-the-L298-Motor-Driver-Module-Arduino-Tu/)

### Parts:


* [Line Follower Sensor](https://www.sgbotic.com/index.php?dispatch=products.view&product_id=2780)
* [Magician Chassis] (https://www.sgbotic.com/index.php?dispatch=products.view&product_id=2151)
* [L298A Driver] (https://www.sgbotic.com/index.php?dispatch=products.view&product_id=2579)
