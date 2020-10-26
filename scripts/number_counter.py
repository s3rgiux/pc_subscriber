#!/usr/bin/env python
import rospy
from std_msgs.msg import Int64

pub = rospy.Publisher('/number_count', Int64, queue_size=1)

def callback_number(data):
    rospy.loginfo("Recibi %i", data.data)
    pub.publish(data)

def listener():
    rospy.init_node('number_counter')
    rospy.Subscriber("/number", Int64, callback_number)
    rospy.spin()

if __name__ == '__main__':
    listener()

