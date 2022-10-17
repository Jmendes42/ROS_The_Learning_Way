#!/usr/bin/env python3

import math
import time
import rospy
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist

def goToGoal(velocityPublisher, xGoal, yGoal):

    global x
    global y, yaw

    velocityMessage = Twist()

    while True:
        # kLinear will set the rithm of the speed and distance calculation
        # Can be any value, very high values make the robot unstable
        kLinear = 0.5

        # Calculate the distance to goal
        distance = abs(math.sqrt(((xGoal - x) ** 2) + ((yGoal - y) ** 2)))

        # Robot speed will be proportional to distance for smoothness
        linearSpeed = distance * kLinear

        kAngular = 4.0

        # Mathematically, atan2 gives the angle between two vectors
        desiredAngleGoal = math.atan2(yGoal - y, xGoal - x)
        angularSpeed = (desiredAngleGoal - yaw) * kAngular

        velocityMessage.linear.x = linearSpeed
        velocityMessage.angular.z = angularSpeed

        velocityPublisher.publish(velocityMessage)
        #print('%.3f'%x)
        print('X = %.3f'%x, ', Y = %.3f'%y, ' distance to goal = %.3f'%distance)

        if distance < 0.1:
            break

# angularSpeedDegree = degrees per seccond

def rotate(velocityPublisher, angularSpeedDegree, relativeSpeedDegree, clockwise):

    velocityMessage = Twist()
    angularSpeed = math.radians(abs(angularSpeedDegree))

    if (clockwise):
        velocityMessage.angular.z = -abs(angularSpeed)
    else:
        velocityMessage.angular.z = abs(angularSpeed)

    loopRate = rospy.Rate(100)
    t0 = rospy.Time.now().to_sec()

    while True:
        rospy.loginfo("Turtlesim Rotates")
        velocityPublisher.publish(velocityMessage)

        t1 = rospy.Time.now().to_sec()
        currentAngleDegree = (t1 - t0) * angularSpeedDegree
        loopRate.sleep()

        if currentAngleDegree > relativeSpeedDegree:
            rospy.loginfo("Reached")
            break

    velocityMessage.angular.z = 0
    velocityPublisher.publish(velocityMessage)

def move(velocityPublisher, speed, distance, forward):
    velocityMessage = Twist() # Twist msg to send velocity commands
    # Get current location
    global x, y
    x0 = x # Save the initial location x-coordinate
    y0 = y # Save the initial location y-coordinate

    if forward:
        velocityMessage.linear.x = abs(speed)
    else:
        velocityMessage.linear.x = -abs(speed)

    distanceMoved = 0.0
    loopRate = rospy.Rate(10) # 10Hz

    while True:
        rospy.loginfo("Turtlesim moves forward")
        velocityPublisher.publish(velocityMessage)
        loopRate.sleep()
        distanceMoved = abs(math.sqrt(((x - x0) ** 2) + ((y - y0) ** 2))) # Distance equation -> square root of the square distance traveled point (x, y) minus the square initial point (x0, y0)
        print (distanceMoved)
        if not distanceMoved < distance: # Check if distanceMoved is == to distance
            rospy.loginfo("Arrived!")
            break

    # Stop when distance is met
    velocityMessage.linear.x = 0
    velocityPublisher.publish(velocityMessage)

def poseCallback(poseMessage):
   global x
   global y, yaw
   x = poseMessage.x
   y = poseMessage.y
   yaw = poseMessage.theta

