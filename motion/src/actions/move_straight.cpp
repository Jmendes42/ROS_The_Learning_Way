#include "motion.hpp"

void    Motion::move(double speed, double distance, bool isForward)
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
        while (current_distance < distance) {;
                ROS_INFO("Turtlesim goes forward!");
                velocity_publisher.publish(vel_msg);
                double t1 = ros::Time::now().toSec();
                current_distance = speed * (t1-t0);
                ros::spinOnce();
                loop_rate.sleep();
        }
        ROS_INFO("Arrived!");
        vel_msg.linear.x = 0;
        velocity_publisher.publish(vel_msg);
}
