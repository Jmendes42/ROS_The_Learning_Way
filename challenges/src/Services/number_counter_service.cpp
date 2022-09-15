#include <ros/ros.h>
#include <std_msgs/Int64.h>
#include <std_srvs/SetBool.h>

int counter = 0;
ros::Publisher pub;

bool	callback_reset_counter(std_srvs::SetBool::Request &request,
				std_srvs::SetBool::Response &response)
{
	if (request.data) {
		counter = 0;
		response.success = true;
		response.message = "Counter has been reset";
	}
	else {
		response.success = false;
		response.message = "Counter has not been reset";
	}
	return true;
}

void	callback_number(const std_msgs::Int64 &msg)
{
	std_msgs::Int64 incremented_message;

	counter += msg.data;
	incremented_message.data = counter;
	pub.publish(incremented_message);
}

int	main(int argc, char **argv)
{
	ros::init(argc, argv, "Number_Counter_Service");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("/number_publisher",
		 1000, callback_number);
	pub = nh.advertise<std_msgs::Int64>("/number_counter", 10);

	ros::ServiceServer reset_service = nh.advertiseService("/reset_counter",
		callback_reset_counter);

	ros::spin();
}
