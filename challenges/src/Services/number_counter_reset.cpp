#include <ros/ros.h>
#include <std_srvs/SetBool.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Reset_Service");
    ros::NodeHandle nh;

    ros::ServiceClient rst = nh.serviceClient<std_srvs::SetBool>("/reset_counter");
    std_srvs::SetBool reset;
    reset.request.data = true;
    
    if (rst.call(reset))
        ROS_INFO("Counter has been reset");
    else
        ROS_WARN("Counter has not been reset");
}
