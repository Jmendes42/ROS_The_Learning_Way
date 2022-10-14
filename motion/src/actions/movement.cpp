#include "motion.hpp"

void    Motion::_move(double speed, double distance, bool isForward) {

	double			t0;
	double			t1;
        geometry_msgs::Twist	vel_msg;
        ros::Rate		loop_rate(10);
        double			current_distance = 0.0;

        if (isForward)
                vel_msg.linear.x = abs(speed);
        else
                vel_msg.linear.x = -abs(speed);
        vel_msg.linear.y = 0;
        vel_msg.linear.z = 0;

        t0 = ros::Time::now().toSec();
        while (current_distance < distance) {
                ROS_INFO("Turtlesim goes forward!");
                _velocity_publisher.publish(vel_msg);
                t1 = ros::Time::now().toSec();
                current_distance = (t1-t0) * speed;
//                ros::spinOnce();
                loop_rate.sleep();
        }
        ROS_INFO("Arrived!");
        vel_msg.linear.x = 0;
        _velocity_publisher.publish(vel_msg);
}

  void    Motion::_rotate(double angular_speed, double relative_angle, bool clockwise  ) {

          double                  t0;
          double                  t1;
          geometry_msgs::Twist    vel_msg;
          ros::Rate               loop_rate(100);
          double                  current_angle = 0.0;

          if (clockwise)
                  vel_msg.angular.z = -abs(angular_speed);
          else
                  vel_msg.angular.z = abs(angular_speed);

          t0 = ros::Time::now().toSec();

          while (current_angle < relative_angle) {
                  _velocity_publisher.publish(vel_msg);
                  t1 = ros::Time::now().toSec();
                  current_angle = (t1 - t0) * angular_speed;
                  ros::spinOnce();
                  loop_rate.sleep();
          }
          ROS_INFO("Reached");
          vel_msg.angular.z = 0;
          _velocity_publisher.publish(vel_msg);
  }
