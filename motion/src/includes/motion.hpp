#ifndef MOVE_H
#define MOVE_H

#include <sstream>
#include <ros/ros.h>
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"
    

class Motion {
    ros::Subscriber _pose_subscriber;
    ros::Publisher _velocity_publisher;
        public:
            void                _move(double speed, double distance, bool isForward);

            ros::Subscriber&    _getSubscriber();
            void                _publisherSet(ros::NodeHandle &nh);
};

void    Motion::_publisherSet(ros::NodeHandle &nh) {
    _velocity_publisher = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
}

ros::Subscriber&    Motion::_getSubscriber() {
    return _pose_subscriber;
}

#endif
