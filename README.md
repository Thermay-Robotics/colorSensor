# colorSensor
Code to use the Adafruit Flora Color Sensor and send its measure to a ros topic.
The value is published as an array of int16 containing the red, the green and the blue values. The topic used is named colorSensorValue.


## Use It
To use this code on your computer. 
First upload the code colorSensor.ino, in folder colorSensor, to the the OpenCR board.

the to get the sensor values, run the following lines on your computer. /dev/ttyACM0 is the port where the board is connected, it may change on your computer.
```
roscore

#Start connection between the openCR board and your pc, not needed on the turtlebot
rosrun rosserial_python serial_node.py /dev/ttyACM0

rostopic echo colorSensorValue
```
