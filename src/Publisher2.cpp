#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Header.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv,  "publish_node_2");
    ros::NodeHandle nh;
    ros::Publisher chatter = nh.advertise<std_msgs::Header>("/Topic/number_2", 1);
    ros::Rate rate(2);

    while (ros::ok())
    {
        
        #if 0 
        std_msgs::String msg; 
        msg.data = "This is topic number_2";
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