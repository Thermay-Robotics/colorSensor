# Package for the Adafruit Flora Color Sensor
Contains two packages:
-colorSensor: code to use the Adafruit Flora Color Sensor and send its measure to a ros topic.
-use_color_sensor: code to choose to use and switch ON the sensor or not.



## Package use_color_sensor
#### Use It
To switch ON or OFF the color sensor, lauch use_color_sensor.launch and add a state (true or false). <br>
Parameter to true ==> switch on <br>
Parameter to false ==> switch off
```
roslaunch use_color_sensor use_color_sensor_true.launch state:=true
```

