# colorSensor
Code to use the Adafruit Flora Color Sensor and send its measure to a ros topic.
The value is published as an array of int16 containing the red, the green and the blue values. The topic used is named colorSensorValue.


## Use It
To use this code on your computer. 
First upload the code in file colorSensor.ino the the OpenCR board.

Then, run the following lines on your computer. /dev/ttyACM0 is the port where the board is connected, it may change on your computer.
```
roscore

rosrun rosserial_python serial_node.py /dev/ttyACM0

rostopic echo colorSensorValue
```
