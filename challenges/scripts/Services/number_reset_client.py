#!/usr/bin/env python3

import rospy
from std_srvs.srv import SetBool

if __name__ == "__main__":
    rospy.init_node("SetBool_reset_counter_client")
    rospy.wait_for_service("/reset_counter")

    try:
        set_bool = rospy.ServiceProxy("/reset_counter", SetBool)
        response = set_bool(True)
    except rospy.ServiceException as e:
        rospy.logwarn("Service failed: " + e)

