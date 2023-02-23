#include "robotsocket/robotsocket.h"
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include"turtlesim/Pose.h"

void RobotSocket::forward()
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

void RobotSocket::back()
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

void RobotSocket::left(){
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

void RobotSocket::right(){
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

void RobotSocket::stop(){
    ROS_INFO("stop");
    ros::NodeHandle n;
    
    // 发布停止msg
    // state=1//停止
};

void RobotSocket::warehouse(){
    ROS_INFO("warehouse");
    // 发布入库msg
    //state=2 //入库
};

void RobotSocket::robot_pub(double target_x,double target_y){
    //发布目的地msg
    //state = 0 // 作业
    cout<<"target_x:"<<target_x<<endl;
	cout<<"target_y:"<<target_y<<endl;
}

float * doPose(const turtlesim::Pose::ConstPtr &p)
{
    ROS_INFO("乌龟位姿信息:x=%.2f,y=%.2f,theta=%.2f,lv=%.2f,av=%.2f",
        p->x,p->y,p->theta,p->linear_velocity,p->angular_velocity);
    float pose[2];
    pose[1]=p->x;
    pose[2]=p->y;
    return pose;
}

void RobotSocket::robot_sub(atomic_bool * working_signal){
    //订阅工作状态，x，y，lon，lat, state
    //if(state==1){working_signal=false}
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe<turtlesim::Pose>("/turtle1/pose",1000,doPose);
    // ros::Subscriber sub = n.subscrib订阅GPS和state
    ros::spin();
    
}