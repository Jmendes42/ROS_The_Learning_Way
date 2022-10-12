#!/usr/bin/env python3

import math
import time
import rospy
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist

def move(velocity_publisher, speed, distance, is_forward):
    velocity_message = Twist() # Twist msg to send velocity commands
    # Get current location
    global x, y
    x0 = x # Save the initial location x-coordinate
    y0 = y # Save the initial location y-coordinate

    if is_forward:
        velocity_message.linear.x = abs(speed)
    else:
        velocity_message.linear.x = -abs(speed)

    distance_moved = 0.0
    loop_rate = rospy.Rate(10) # 10Hz

    while True:
        rospy.loginfo("Turtlesim moves forward")
        velocity_publisher.publish(velocity_message)
        loop_rate.sleep()
        distance_moved = abs(math.sqrt(((x - x0) ** 2) + ((y - y0) ** 2))) # Distance equation -> square root of the square distance traveled point (x, y) minus the square initial point (x0, y0)
        print (distance_moved)
        if not distance_moved < distance: # Check if distance_moved is == to distance
            rospy.loginfo("Arrived!")
            break

    # Stop when distance is met
    velocity_message.linear.x = 0
    velocity_publisher.publish(velocity_message)

def poseCallback(pose_message):
    global x
    global y, yaw
    x = pose_message.x
    y = pose_message.y
    yaw = pose_message.theta

