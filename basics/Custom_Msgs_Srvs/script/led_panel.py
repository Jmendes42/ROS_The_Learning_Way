#!/usr/bin/env python3

import rospy
from challenge_msgs.srv import LedControl

def callback_led_control(state):
    if state.led_config == 1:
        rospy.loginfo("[1,1,1]")
    if state.led_config == 2:
        rospy.loginfo("[1,1,0]")
    if state.led_config == 3:
        rospy.loginfo("[1,0,0]")
    return True 

if __name__ == "__main__":
    rospy.init_node("led_panel")
    
    rate = rospy.Rate(2)
    panel_led = rospy.Service("/set_led", LedControl, callback_led_control)
    rospy.spin()
