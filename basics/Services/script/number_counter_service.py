#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int64
from std_srvs.srv import SetBool

counter = 0
pub = None

def callback_reset_counter(req):
    if req.data:
        global counter
        counter = 0
        return True, "Counter has been reset"
    return False, "Counter has not been reset"

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
    reset_service = rospy.Service("/reset_counter", SetBool, callback_reset_counter)

    rate = rospy.Rate(2)

    rospy.spin()
