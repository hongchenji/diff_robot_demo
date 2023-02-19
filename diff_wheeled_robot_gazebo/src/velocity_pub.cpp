#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sstream>

float linear_x;
float linear_y;
float linear_z;

float angular_x;
float angular_y;
float angular_z;

/*
int getParam(ros::NodeHandle nh)
{
    nh.param<float>("/velocity_pub/linear_x", linear_x, 0.0);
    nh.param<float>("/velocity_pub/linear_y", linear_y, 0.0);
    nh.param<float>("/velocity_pub/linear_z", linear_z, 0.0);
    nh.param<float>("/velocity_pub/angular_x", angular_x, 0.0);
    nh.param<float>("/velocity_pub/angular_y", angular_y, 0.0);
    nh.param<float>("/velocity_pub/angular_z", angular_z, 0.0);
    ROS_INFO("velocity_value: x:%f y:%f z:%freceived!", linear_x, linear_y, linear_z);
    return 1;
}
*/

int main(int argc, char **argv){
    ros::init(argc, argv, "velocity_pub");
    ros::NodeHandle node;
    node.getParam("/velocity_pub/linear_x", linear_x);
    node.getParam("/velocity_pub/linear_y", linear_y);
    node.getParam("/velocity_pub/linear_z", linear_z);
    node.getParam("/velocity_pub/angular_x", angular_x);
    node.getParam("/velocity_pub/angular_y", angular_y);
    node.getParam("/velocity_pub/angular_z", angular_z);

    ros::Publisher velocity_pub = node.advertise<geometry_msgs::Twist>("cmd_vel", 1);
    ros::Rate loop_rate(10);
    while (ros::ok()){
        geometry_msgs::Twist velocity_msg;
        velocity_msg.linear.x = linear_x;
        velocity_msg.linear.y = linear_y;
        velocity_msg.linear.z = linear_z;

        velocity_msg.angular.x = angular_x;
        velocity_msg.angular.y = angular_y;
        velocity_msg.angular.z = angular_z;

        velocity_pub.publish(velocity_msg);
        ROS_INFO("velocity: x= %f y=%f z=%f published!", velocity_msg.linear.x,velocity_msg.linear.y,velocity_msg.linear.z);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}