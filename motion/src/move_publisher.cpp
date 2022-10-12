#include "motion.hpp"

void	poseCallback(const turtlesim::Pose &turtlesim_pose)
{
}

int	main(int argc, char **argv)
{
	Motion motion;
	ros::init(argc, argv, "turtlesim_move");
	ros::NodeHandle nh;

	motion._publisherSet(nh);
	motion._getSubscriber() = nh.subscribe("/turtle1/pose", 10, poseCallback);

	motion._move(2.0, 2.5, true);
}
