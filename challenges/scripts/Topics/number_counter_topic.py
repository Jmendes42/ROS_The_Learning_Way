#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int64

counter = 0
pub = None

def number_callback(msg):
    global counter
    counter += msg.data
    newMsg = Int64()
    newMsg.data = counter
    pub.publish(newMsg)

if __name__ == '__main__':
    rospy.init_node('number_counter')

    sub = rospy.Subscriber("/number_publisher", Int64, number_callback)
    pub = rospy.Publisher("/number_counter", Int64, queue_size = 10)

    rate = rospy.Rate(2)

    rospy.spin()
