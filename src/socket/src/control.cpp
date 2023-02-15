#include "socket/socket.h"
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

void Socket::forward()
{
    /* 为这个进程节点创建句柄 */
    ros::NodeHandle n;
    /* 创建发布者对象 */
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000, true);
    /* 设定循环的频率为2Hz */
    ros::Rate loop_rate(2);

    /* 要发布的消息: 让乌龟以1.0的线速度前进 */
    geometry_msgs::Twist msg;
    msg.linear.x = 1.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;

    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 0.0;

    // 发布消息
    pub.publish(msg);
    /* 暂无callback函数，直接跳过  */
    ros::spinOnce();
    /* 剩下的时间睡眠，以保证达到2Hz的发布速度 */
    loop_rate.sleep();
};

void Socket::back()
{
    /* 为这个进程节点创建句柄 */
    ros::NodeHandle n;
    /* 创建发布者对象 */
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000, true);
    /* 设定循环的频率为2Hz */
    ros::Rate loop_rate(2);

    /* 要发布的消息: 让乌龟以1.0的线速度后退 */
    geometry_msgs::Twist msg;
    msg.linear.x = -1.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;

    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 0.0;

    // 发布消息
    pub.publish(msg);
    /* 暂无callback函数，直接跳过  */
    ros::spinOnce();
    /* 剩下的时间睡眠，以保证达到2Hz的发布速度 */
    loop_rate.sleep();
};

void Socket::left(){
     /* 为这个进程节点创建句柄 */
    ros::NodeHandle n;
    /* 创建发布者对象 */
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000, true);
    /* 设定循环的频率为2Hz */
    ros::Rate loop_rate(2);

    /* 要发布的消息: 让乌龟以1.0的线速度左转 */
    geometry_msgs::Twist msg;
    msg.linear.x = 0.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;

    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 1.0;

    // 发布消息
    pub.publish(msg);
    /* 暂无callback函数，直接跳过  */
    ros::spinOnce();
    /* 剩下的时间睡眠，以保证达到2Hz的发布速度 */
    loop_rate.sleep();
};

void Socket::right(){
     /* 为这个进程节点创建句柄 */
    ros::NodeHandle n;
    /* 创建发布者对象 */
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000, true);
    /* 设定循环的频率为2Hz */
    ros::Rate loop_rate(2);

    /* 要发布的消息: 让乌龟以1.0的线速度右转 */
    geometry_msgs::Twist msg;
    msg.linear.x = 0.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;

    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = -1.0;

    // 发布消息
    pub.publish(msg);
    /* 暂无callback函数，直接跳过  */
    ros::spinOnce();
    /* 剩下的时间睡眠，以保证达到2Hz的发布速度 */
    loop_rate.sleep();
};

void Socket::stop(){
    ROS_INFO("stop");
    // 发布停止msg
    
};

void Socket::warehouse(){
    ROS_INFO("warehouse");
    // 发布入库msg

};

void Socket::target_pub(double x,double y){
    //发布目的地msg
}