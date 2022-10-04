#include <sstream>
#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"

ros::Publisher velocity_publisher;
ros::Subscriber pose_subscriber;


void	move(double speed, double distance, bool isForward)
{
	geometry_msgs::Twist vel_msg;

	if (isForward)
		vel_msg.linear.x = abs(speed);
	else
		vel_msg.linear.x = -abs(speed);
	vel_msg.linear.y = 0;
	vel_msg.linear.z = 0;

	double t0 = ros::Time::now().toSec();
	double current_distance = 0.0;
	ros::Rate loop_rate(100);
	do {
		ROS_INFO("Turtlesim goes forward!");
		velocity_publisher.publish(vel_msg);
		double t1 = ros::Time::now().toSec();
		current_distance = speed * (t1-t0);
		ros::spinOnce();
		loop_rate.sleep();
	} while (current_distance < distance);
	ROS_INFO("Arrived!");
	vel_msg.linear.x = 0;
	velocity_publisher.publish(vel_msg);
}

void	poseCallback(const turtlesim::Pose &turtlesim_pose)
{
}

int	main(int argc, char **argv)
{
	ros::init(argc, argv, "turtlesim_move");
	ros::NodeHandle nh;

	velocity_publisher = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
	pose_subscriber = nh.subscribe("/turtle1/pose", 10, poseCallback);

	move(2.0, 2.5, true);
}
