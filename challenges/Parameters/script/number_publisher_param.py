#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int64

if __name__ == '__main__':
    rospy.init_node('number_publisher_param')
    
    pub = rospy.Publisher("/number_publisher_param", Int64, queue_size = 10)
    
    publish_frequency = rospy.get_param("/number_publish_frequency")
    rate = rospy.Rate(publish_frequency)

    number = rospy.get_param("/number_to_publish")
    rospy.set_param("/new_param", "Hello World!")

    while not rospy.is_shutdown():
        msg = Int64()
        msg.data = number
        pub.publish(msg)
        rate.sleep()

    rospy.loginfo("Publisher has stopped")
