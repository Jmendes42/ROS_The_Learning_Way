#include <ros/ros.h>
#include <challenge_msgs/LedControl.h>
#include <challenge_msgs/BatteryStatus.h>

void	callback_status(const challenge_msgs::BatteryStatus &msg)
{
	ros::NodeHandle nh;

	ros::ServiceClient client = nh.serviceClient<challenge_msgs::LedControl>("/led_control");
	challenge_msgs::LedControl ledControl;

	if (msg.battery_percentage == 100)
		ledControl.request.led_config = 1;
	else if (msg.battery_percentage == 50)
		ledControl.request.led_config = 2;
	else
		ledControl.request.led_config = 3;

	if (client.call(ledControl))
		ROS_INFO("Battery is at %ld%%", msg.battery_percentage);
	else
		ROS_WARN("Service call failed");
}

int	main(int argc, char **argv)
{
	ros::init(argc, argv, "Battery_Status");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("/battery_node", 1000, callback_status);

	ros::spin();
}
