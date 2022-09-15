#include <ros/ros.h>
#include <challenge_msgs/LedControl.h>

bool	handle_led_control(challenge_msgs::LedControl::Request &srv,
				challenge_msgs::LedControl::Response &response)
{
	ros::NodeHandle nh;

	if (srv.led_config == 1)
		ROS_INFO("[1,1,1]");
	else if (srv.led_config == 2)
		ROS_INFO("[1,1,0]");
	else
		ROS_INFO("[1,0,0]");
	response.response = true;
	return response.response;
}

int	main(int argc, char **argv)
{
	ros::init(argc, argv, "Led_Panel");

	ros::NodeHandle nh;
	ros::ServiceServer panel = nh.advertiseService("/led_control", handle_led_control);

	ros::spin();
}
