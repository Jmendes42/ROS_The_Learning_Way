#ifndef MOVE_H
#define MOVE_H

#include <sstream>
#include <ros/ros.h>
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"
    
ros::Publisher velocity_publisher;
ros::Subscriber pose_subscriber;

class Motion {
    public:
        static void    move(double speed, double distance, bool isForward);
};

#endif
