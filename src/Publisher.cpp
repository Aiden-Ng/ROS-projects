#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Header.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv,  "publish_node");
    ros::NodeHandle nh;
    ros::Publisher chatter = nh.advertise<std_msgs::Header>("/Topic/number_1", 1);
    ros::Rate rate(1);

    while (ros::ok())
    {
        #if 0
        std_msgs::String msg; 
        msg.data = "This is topic number_1";
        chatter.publish(msg);
        #endif

        std_msgs::Header header;
        header.stamp = ros::Time::now();
        header.frame_id = "Base link" ;
        chatter.publish(header);

        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}