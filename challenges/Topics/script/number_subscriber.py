#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int64

def call_back_number(msg):
    rospy.loginfo(msg)

if __name__ == "__main__":
    rospy.init_node('number_subscriber')

    sub = rospy.Subscriber("/number_counter", Int64, call_back_number)

    rospy.spin()
