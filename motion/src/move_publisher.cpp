#include "motion.hpp"

void	poseCallback(const turtlesim::Pose &turtlesim_pose)
{
}

int	main(int argc, char **argv)
{
	ros::init(argc, argv, "turtlesim_move");
	ros::NodeHandle nh;

	velocity_publisher = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
	pose_subscriber = nh.subscribe("/turtle1/pose", 10, poseCallback);

	Motion::move(2.0, 2.5, true);
}
