# Package for the Adafruit Flora Color Sensor
Contains two packages:
-colorSensor: code to use the Adafruit Flora Color Sensor and send its measure to a ros topic.
-use_color_sensor: code to choose to use and switch ON the sensor or not.

## Package colorSensor
The color values measured are published as an array of int16 containing the red, the green and the blue values. The topic used is named colorSensorValue.
By default the sensor is switched OFF.
#### Use It
To use this code on your computer. 
First upload the code colorSensor.ino, in folder colorSensor, to the the OpenCR board.

the to get the sensor values, run the following lines on your computer. /dev/ttyACM0 is the port where the board is connected, it may change on your computer.
```
roscore

#Start connection between the openCR board and your pc, not needed on the turtlebot
rosrun rosserial_python serial_node.py /dev/ttyACM0

rostopic echo colorSensorValue
```


## Package use_color_sensor
#### Use It
To switch ON or OFF the color sensor, lauch use_color_sensor.launch and add a state (true or false). <br>
Parameter to true ==> switch on <br>
Parameter to false ==> switch off
```
roslaunch use_color_sensor use_color_sensor_true.launch state:=true
```

