#include "includes/BatteryInfo.hpp"

int	main(int argc, char **argv)
{
	Battery info;

	ros::init(argc, argv, "Battery_Node");
	ros::NodeHandle nh;
	info.pub = nh.advertise<challenge_msgs::BatteryStatus>("/battery_node", 10);

	while (ros::ok()) {
		sleep(3);
		info.battery_info(100, true, "Battery full");
		info.pub.publish(info.msg);
		sleep(3);
		info.battery_info(50, true, "Half charge");
		info.pub.publish(info.msg);
		sleep(3);
		info.battery_info(0, false, "Battery depleted");
		info.pub.publish(info.msg);
	}

}
