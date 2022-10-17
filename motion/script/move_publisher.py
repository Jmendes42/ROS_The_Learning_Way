#!/usr/bin/env python3

import time
import rospy
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist

import actions.movement as move


if __name__ == '__main__':

    global x
    global y, yam

    try:

        rospy.init_node('turtlesim_motion_pose', anonymous = True)

        cmd_vel_topic = '/turtle1/cmd_vel'
        velocity_publisher = rospy.Publisher(cmd_vel_topic, Twist, queue_size = 10)

        position_topic = '/turtle1/pose'
        pose_subscriber = rospy.Subscriber(position_topic, Pose, move.poseCallback)
        time.sleep(2)

        move.goToGoal(velocity_publisher, 1.0, 3.0)
        move.goToGoal(velocity_publisher, 8.5, 8.3)
        move.goToGoal(velocity_publisher, 2.5, 0.3)


    except rospy.ROSInterruptException:
        rospy.loginfo("Node Terminated")

