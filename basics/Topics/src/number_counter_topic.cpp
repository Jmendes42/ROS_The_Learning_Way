#include <ros/ros.h>
#include <std_msgs/Int64.h>

int counter = 0;
ros::Publisher pub;

void	callback_number(const std_msgs::Int64 &msg)
{
	std_msgs::Int64 incremented_message;

	counter += msg.data;
	incremented_message.data = counter;
	pub.publish(incremented_message);
}

int	main(int argc, char **argv)
{
	ros::init(argc, argv, "Number_Counter_Topic");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("/number_publisher",
		 1000, callback_number);
	pub = nh.advertise<std_msgs::Int64>("/number_counter", 10);

	ros::spin();
}
