#include "ros/ros.h"
#include <std_msgs/Int64.h>

class test
{
public:
	test(ros::NodeHandle nh)
	{
	    pub=nh.advertise<std_msgs::Int64>(nh.resolveName("number_count"), 1);
	    sub = nh.subscribe("number", 1, &test::numCallback,this);
	}
	~test(){}

    void numCallback(const std_msgs::Int64& dato)
	{
               ROS_INFO("Recibi %i",dato.data);
	       pub.publish(dato);     
	}
private:
    ros::Subscriber sub;
    ros::Publisher pub;
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "number_counter");
    ros::NodeHandle nh; 

    test test_obj(nh);
	while(ros::ok())
	{
		ros::spinOnce();
	}
    return 0;
}
