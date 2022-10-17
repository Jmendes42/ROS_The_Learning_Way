#include "motion.hpp"

void	Motion::_goToGoal(const turtlesim::Pose &goalPose, const double &distanceTolerance) {

	geometry_msgs::Twist	velMsg;
	double					distance;
	double					desiredAngle;
	ros::Rate				loopRate(100);
	double					kLinear = 0.5;
	double					kAngular = 4.0;

	distance = _getDistance(_turtlesimPose.x, _turtlesimPose.y, goalPose.x, goalPose.y);

	while (distance > distanceTolerance) {
		ROS_INFO("LOOP %.2f, %.2f, %.2f", distance, _getPose().x, _turtlesimPose.y);
		distance = _getDistance(goalPose.y, _turtlesimPose.y, goalPose.x, _turtlesimPose.x);
		velMsg.linear.x = distance * kLinear;
		desiredAngle = atan2(goalPose.y - _turtlesimPose.y, goalPose.x - _turtlesimPose.x);
		velMsg.angular.z = (desiredAngle - _turtlesimPose.theta) * kAngular;

		_velocityPublisher.publish(velMsg);
		ros::spinOnce();
		loopRate.sleep();
	}

	velMsg.linear.x = 0;
	velMsg.angular.z = 0;
	_velocityPublisher.publish(velMsg);
	ROS_INFO("Reached Goal!");
}

void	Motion::_move(double speed, double distance, bool isForward) {

	double					t0;
	double					t1;
	geometry_msgs::Twist	velMsg;
	ros::Rate				loopRate(10);
	double					currentDistance = 0.0;

	if (isForward)
		velMsg.linear.x = abs(speed);
	else
		velMsg.linear.x = -abs(speed);
	velMsg.linear.y = 0;
	velMsg.linear.z = 0;

	t0 = ros::Time::now().toSec();
	while (currentDistance < distance) {
		ROS_INFO("Turtlesim goes forward!");
		_velocityPublisher.publish(velMsg);
		t1 = ros::Time::now().toSec();
		currentDistance = (t1-t0) * speed;
		ros::spinOnce();
		loopRate.sleep();
	}

	ROS_INFO("Arrived!");
	velMsg.linear.x = 0;
	_velocityPublisher.publish(velMsg);
}

  void    Motion::_rotate(double angularSpeed, double relativeAngle, bool clockwise  ) {

	double					t0;
	double					t1;
	geometry_msgs::Twist	velMsg;
	ros::Rate				loopRate(100);
	double					currentAngle = 0.0;

	if (clockwise)
		velMsg.angular.z = -abs(angularSpeed);
	else
		velMsg.angular.z = abs(angularSpeed);

	 t0 = ros::Time::now().toSec();

	 while (currentAngle < relativeAngle) {
		_velocityPublisher.publish(velMsg);
		t1 = ros::Time::now().toSec();
		currentAngle = (t1 - t0) * angularSpeed;
		ros::spinOnce();
		loopRate.sleep();
	}
	ROS_INFO("Reached");
	velMsg.angular.z = 0;
	_velocityPublisher.publish(velMsg);
  }
