#!/usr/bin/env python3

import rospy
from challenge_msgs.msg import BatteryStatus
from challenge_msgs.srv import LedControl

percent = 0

def percent_check():
    if percent == 100:
        return 1
    if percent == 50:
        return 2
    if percent == 0:
        return 3
    return 0

def set_led():
    rospy.wait_for_service("/set_led")
    try:
        service = rospy.ServiceProxy("/set_led", LedControl)
        state = percent_check()
        resp = service(state)
    except rospy.ServiceException as e:
        rospy.logerr(e)

def callback_status(msg):
    global percent
    percent = msg.battery_percentage
    rospy.loginfo(msg.warn_message)
    set_led()

if __name__ == "__main__":
    rospy.init_node("Battery_Status")

    sub = rospy.Subscriber("/battery_node", BatteryStatus, callback_status)
    rate = rospy.Rate(2)

    rospy.spin()
