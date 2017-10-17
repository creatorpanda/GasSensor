# Smeller
This code was made for the **audiovisual** warning of the sensor owner that something is going wrong with the air he/she is surrounded by. A led blinks meaning that the sensor is armed, waiting to "smell" something bad. When that happens, the first led turns off, the buzzer starts beeping and the other led turns on and stays on until a new, non-dangerous value is input by the sensor. Then it goes back to blinking the first led and the buzzer goes silent. "Smelling" something bad will trigger again the buzzer and the other led and so on. No reset required. (MQ-5 Gas Sensor and other equipment required, duh :P)


**Le wild notes for the MQ5 Sensor** (taken  from [here](http://wiki.seeed.cc/Grove-Gas_Sensor-MQ5/) click for even more info!):

*The Grove - Gas Sensor(MQ5) module is useful for gas leakage detection (in home and industry). It is suitable for detecting H2, LPG, CH4, CO and Alcohol. Due to its high sensitivity and fast response time, measurements can be taken as soon as possible.*

So now you know, let's continue!

**Le wild notes for the setup part**: 

1) Values I entered myself were chosen by studying the values printed while leaking gas from a lighter on the sensor. They can be easily modified. 
 
2) Except for the MQ-5 Gas Sensor and the jumper wires, a **5V buzzer**, **2 LEDs**- one green/blue and one red- and one **110 Ohms 1% resistor** (for the sensor's ground) are required to make the code work at its 100%. The green/blue is the blinking standby led and the red is the one that goes off when the alarm is triggered.  

**WARNING: using a resistor -which from my experience is an obligation or else the sensor keeps sending max value no matter what- will affect the sensor's reading. Using a resistor with different power than i recommended, will affect again the values the sensor sends to the device and as a result, it won't work right, cause then you're gonna have to reevaluate the if statements of the code. Be cautious!!** 


In case you don't know what to do: Click on the green "Clone or Download" button, click "Download Zip". Unzip it and you got the source code file, ready to be uploaded to your device!
