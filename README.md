# colorSensor
Code to use the Adafruit Flora Color Sensor and send its measure to a ros topic.
The value is published as an array of int16 containing the red, the green and the blue values. The topic used is named colorSensorValue.


## Use It
To use this code on your computer. 
First upload the code in file colorSensor.ino the the OpenCR card.

Then, run on your computer :
```
roscore

rosrun rosserial_python serial_node.py /dev/ttyACM0

rostopic echo colorSensorValue
```
