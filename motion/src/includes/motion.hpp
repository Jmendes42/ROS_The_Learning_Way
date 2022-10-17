#ifndef MOVE_H
#define MOVE_H

#include <math.h>
#include <sstream>
#include <ros/ros.h>
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"
    
class Motion {

	turtlesim::Pose	_turtlesimPose;
    ros::Subscriber	_poseSubscriber;
	ros::Publisher	_velocityPublisher;

	double			_getDistance(const double&, const double&, const double&, const double&);

	public:
		void				_move(double, double, bool);
		void				_rotate(double, double, bool);
		void				_goToGoal(const turtlesim::Pose&, const double&);

		turtlesim::Pose&	_getPose();
		ros::Subscriber&	_getSubscriber();
		void				_publisherSet(ros::NodeHandle&);
		void				_poseCallback(const turtlesim::Pose&);
};

void	Motion::_poseCallback(const turtlesim::Pose &poseMessage) {
	_turtlesimPose.x = poseMessage.x;
	_turtlesimPose.y = poseMessage.y;
	_turtlesimPose.theta = poseMessage.theta;
}

void	Motion::_publisherSet(ros::NodeHandle &nh) {
	_velocityPublisher = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
}

double	Motion::_getDistance(const double &Y, const double &y, const double &X, const double &x) {
	return  sqrt(pow((Y - y), 2) + pow((X -x), 2));
}

turtlesim::Pose&	Motion::_getPose() {
	return _turtlesimPose;
}

ros::Subscriber&    Motion::_getSubscriber() {
    return _poseSubscriber;
}

#endif
