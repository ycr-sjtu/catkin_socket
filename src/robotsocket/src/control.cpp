#include "robotsocket/robotsocket.h"
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include"turtlesim/Pose.h"
#include"robotsocket/state.h"
#include "sensor_msgs/NavSatFix.h"
#include"nav_msgs/Path.h"

void RobotSocket::forward()
{
    ROS_INFO("forward");
    /* 为这个进程节点创建句柄 */
    ros::NodeHandle n;
    /* 创建发布者对象 */
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000, true);

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

    /* 剩下的时间睡眠 */
    ros::Duration(0.5).sleep();
};

void RobotSocket::back()
{
    ROS_INFO("back");
    /* 为这个进程节点创建句柄 */
    ros::NodeHandle n;
    /* 创建发布者对象 */
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000, true);

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

    /* 剩下的时间睡眠 */
    ros::Duration(0.5).sleep();
};

void RobotSocket::left(){
    ROS_INFO("left"); 
    /* 为这个进程节点创建句柄 */
    ros::NodeHandle n;
    /* 创建发布者对象 */
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000, true);

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

    /* 剩下的时间睡眠 */
    ros::Duration(0.5).sleep();
};

void RobotSocket::right(){
    ROS_INFO("right");
    /* 为这个进程节点创建句柄 */
    ros::NodeHandle n;
    /* 创建发布者对象 */
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000, true);

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

    /* 剩下的时间睡眠 */
    ros::Duration(0.5).sleep();
};
    
// 发布停止msg, state=1停止
void RobotSocket::stop(){
    ROS_INFO("stop");
    ros::NodeHandle n;
    ros::Publisher publish = n.advertise<robotsocket::state>("/state", 10, true);
    robotsocket::state msg;
    msg.state = 1;
    while(publish.getNumSubscribers()<1);
    publish.publish(msg);
    ros::Duration(0.5).sleep();
};

// 发布入库msg, state=2 入库
void RobotSocket::warehouse(){
    ROS_INFO("warehouse");
    ros::NodeHandle n;
    ros::Publisher publish = n.advertise<robotsocket::state>("/state", 10, true);
    robotsocket::state msg;
    msg.state = 2;
    while(publish.getNumSubscribers()<1);
    publish.publish(msg);
    ros::Duration(0.5).sleep();
};

//发布目的地msg, state = 0 作业
void RobotSocket::robot_pub(){
    ROS_INFO("working");
    ros::NodeHandle n;
    ros::Publisher publish = n.advertise<robotsocket::state>("/state", 10, true);
    robotsocket::state msg;
    msg.x = target[0];
    msg.y = target[1];
    msg.state = 0;
    while(publish.getNumSubscribers()<1);
    publish.publish(msg);
    ros::Duration(0.5).sleep();
}

void RobotSocket::subscriberCallback_gps(const sensor_msgs::NavSatFix::ConstPtr& gps){
        // printf("latitude=%.10f, longitude=%.10f\n",gps->latitude,gps->longitude);
        position[2] = gps->longitude;
        position[3] = gps->latitude;
}

void RobotSocket::subscriberCallback_path(const nav_msgs::Path::ConstPtr& path){
        // printf("x=%f, y=%f\n",path->poses.back().pose.position.x,path->poses.back().pose.position.y);
        position[0] = path->poses.back().pose.position.x;
        position[1] = path->poses.back().pose.position.y;
}

void RobotSocket::subscriberCallback_state(const robotsocket::state::ConstPtr& msg){
    // printf("msg : %d\n",msg->state);
    state = msg->state;
    if(state ==1){
        working_signal = false;
    }
}

//订阅x，y，lon，lat, state
void RobotSocket::robot_sub(){
    ros::NodeHandle n;
    ros::Subscriber subscriber = n.subscribe("/fix", 10, &RobotSocket::subscriberCallback_gps,this);
    ros::Subscriber subscriber2 = n.subscribe("/gps_path", 10,&RobotSocket::subscriberCallback_path,this);
    ros::Subscriber subscriber3 = n.subscribe("/state", 10, &RobotSocket::subscriberCallback_state,this);
    ros::Rate loop_rate(10);
    while(working_signal){
        ros::spinOnce();
        loop_rate.sleep();
    }
}
