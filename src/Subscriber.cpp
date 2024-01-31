#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace ros::placeholders; 

int main(int argc, char **argv)
{
    ros::init(argc, argv,  "subscribe_node");
    ros::NodeHandle nh;
    ros::Publisher subscriber = nh.subscriber<std_msgs::String>("/Topic/number_1", 1
                                                                std::bind(callback_Function, this, _1));
    ros::Rate rate(10);

    while (ros::ok())
    {
        
        
        
        

        // ros::spinOnce();
        // rate.sleep();
    }
    return 0;
}

void callback_Function(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("Received information %s", msg->data.c_str());
}