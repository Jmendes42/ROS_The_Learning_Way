#ifndef BATTERYINFO_H
#define BATTERYINFO_H

#include <iostream>
#include <ros/ros.h>
#include <challenge_msgs/BatteryStatus.h>

class Battery
{
	public:
		challenge_msgs::BatteryStatus	msg;
		ros::Publisher			pub;

		void	battery_info(int percentage, bool status,
				std::string warn);
};

void	Battery::battery_info(int percentage, bool status,
		std::string warn)
{
	msg.battery_percentage = percentage;
	msg.battery_on = status;
	msg.warn_message = warn;
}

#endif
