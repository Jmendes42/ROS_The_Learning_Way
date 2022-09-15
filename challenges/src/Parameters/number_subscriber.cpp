#include <ros/ros.h>
#include <std_msgs/Int64.h>

void	callback_number(const std_msgs::Int64 &msg)
{
	ROS_INFO("Data: %d", (int)msg.data);
}

int	main(int argc, char **argv)
{
	ros::init(argc, argv, "Number_Subscriber");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("/number_counter", 1000, callback_number);

	ros::spin();
}
