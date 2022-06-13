#!/usr/bin/env python
import rospy 
from std_msgs.msg import Bool

pub = None
doUse = False

def useColorSensor():
    global pub, doUse
    doUse = rospy.get_param("/useColorSensor/doUse")
    pub = rospy.Publisher('do_get_color_value', Bool, queue_size=1) 
    rospy.init_node('do_get_color_value_node', anonymous=True)
    

     

useColorSensor() 
pub.publish(doUse)
