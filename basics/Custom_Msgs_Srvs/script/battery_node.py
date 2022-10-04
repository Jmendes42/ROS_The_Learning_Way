#!/usr/bin/env python3

import rospy
from challenge_msgs.msg import BatteryStatus

def statusPublisher(percent, status, warn, msg, pub):
    msg.battery_percentage = percent
    msg.battery_on = status
    msg.warn_message = warn
    pub.publish(msg)

if __name__ == "__main__":
    rospy.init_node("Battery_Node")
    
    pub = rospy.Publisher("/battery_node", BatteryStatus, queue_size = 10)


    while not rospy.is_shutdown():
        msg = BatteryStatus()
        rospy.sleep(3)
        statusPublisher(100, True, "Battery full", msg, pub)
        rospy.sleep(3)
        statusPublisher(50, True, "Half charge", msg, pub)
        rospy.sleep(3)
        statusPublisher(0, False, "Battery depleted", msg, pub)
