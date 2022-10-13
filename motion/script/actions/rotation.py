#!/usr/bin/env python3

import math
import time
import rospy
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist

# angular_speed_degree = degrees per seccond

def rotate(velocity_publisher, angular_speed_degree, relative_angle_degree, clockwise):

    velocity_message = Twist()
    angular_speed = math.radians(abs(angular_speed_degree))

    if (clockwise):
        velocity_message.angular.z = -abs(angular_speed)
    else:
        velocity_message.angular.z = abs(angular_speed)

    loop_rate = rospy.Rate(100)
    t0 = rospy.Time.now().to_sec()

    while True:
        rospy.loginfo("Turtlesim Rotates")
        velocity_publisher.publish(velocity_message)

        t1 = rospy.Time.now().to_sec()
        current_angle_degree = (t1 - t0) * angular_speed_degree
        loop_rate.sleep()

        if current_angle_degree > relative_angle_degree:
            rospy.loginfo("Reached")
            break

    velocity_message.angular.z = 0
    velocity_publisher.publish(velocity_message)

