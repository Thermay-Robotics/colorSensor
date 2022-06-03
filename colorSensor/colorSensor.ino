#include <ros.h>
#include <std_msgs/Int16MultiArray.h>
#include <Wire.h>                  //include Wire.h to be able to communicate through I2C on Arduino board
#include "Adafruit_TCS34725.h"     //Colour sensor library




//Create colour sensor object declaration 
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);


//Define the ros Node
ros::NodeHandle nh;
//Define the color value
std_msgs::Int16MultiArray colorValues;
//Define the ros topic
ros::Publisher chatter("colorSensorValue", &colorValues);




void startColorSensor(){
  //Start-up colour sensor
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
}




void initRosNode(){
  //Initialize the ros Node
  nh.initNode();
  nh.advertise(chatter);
}




void getColor(){
  uint16_t clear, red, green, blue;

  //Collect raw data from integrated circuit using interrupts
  tcs.setInterrupt(false);      // turn on LED
  delay(50);  // takes 50ms to read 
  tcs.getRawData(&red, &green, &blue, &clear);
  tcs.setInterrupt(true);  // turn off LED

  // Map color values between 0 and 255 depending on the clear value
  float r, g, b;
  r = red; 
  r /= clear;
  g = green; 
  g /= clear;
  b = blue; 
  b /= clear;
  r *= 256; g *= 256; b *= 256;

  //Save the color values
  colorValues.data[0] = min(r, 255);
  colorValues.data[1] = min(g, 255);
  colorValues.data[2] = min(b, 255);
}




void publishColor(){
  //Publish colorValue on a ros topic
  chatter.publish( &colorValues );
  nh.spinOnce(); //Publish only once
}








void setup() {
  Serial.begin(9600);
  Serial.println("Color View Test!");

  startColorSensor();
  initRosNode();
  colorValues.data_length = 3;
}




void loop() {
  getColor();
  publishColor();
  delay(1000);
}
