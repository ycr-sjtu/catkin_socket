#include <ros/ros.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <string.h>
#include <iostream>

#include "robotsocket/harvestingRobotClient.h"
#include "robotsocket/harvest_action.h"
#include "robotsocket/harvest_vel.h"

#define MYPORT 8080	  // 端口号
#define BUF_SIZE 1024 // 数据缓冲区最大长度

char *SERVER_IP = "127.0.0.1";

int recvbuf_length; // 接收数据的长度
int send_length; //发送数据长度

using namespace std;

HarvestingRobotClient harvest;

// 回调函数
void subscriberCallback_harvest_action(const robotsocket::harvest_action::ConstPtr& msg){
		harvest.harvest_state = 1;
		harvest.harvest_push_rod = msg->push_rod;
		harvest.harvest_platform = msg->platform;
		harvest.harvest_conveyor = msg->conveyor;
		harvest.harvest_knife = msg->knife;
		harvest.harvest_shake = msg->shake;
		printf("push_rod=%d, platform=%d, conveyor=%f, knife=%f, shake=%f\n",msg->push_rod,msg->platform,msg->conveyor,msg->knife,msg->shake);
}
void subscriberCallback_harvest_vel(const robotsocket::harvest_vel::ConstPtr& msg){
		harvest.harvest_state = 2;
		harvest.harvest_left_vel = msg->left_vel;
		harvest.harvest_right_vel = msg->right_vel;
		printf("left_vel=%d, right_vel=%d\n",msg->left_vel,msg->right_vel);
}


int main(int argc, char **argv)
{
	//初始化ros节点
	ros::init(argc, argv, "harvestrobot");
	ros::NodeHandle n;

	unsigned char recvbuf[BUF_SIZE];
	char sendbuf[BUF_SIZE];

	/*
	 *@fuc: socket()创建套节字
	 *
	 */
	int socket_cli = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_cli < 0)
	{
		std::cout << "socket() error\n";
		return -1;
	}

	/*
	 *@fuc: 服务器端IP4地址信息,struct关键字可不写
	 *@fuc: 初始化sever地址信息
	 */
	struct sockaddr_in sev_addr;
	memset(&sev_addr, 0, sizeof(sev_addr));
	sev_addr.sin_family = AF_INET;
	sev_addr.sin_port = htons(MYPORT);
	sev_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	std::cout << "connecting..." << std::endl;
	/*
	 *@fuc: 使用connect()函数来配置套节字,建立一个与TCP服务器的连接
	 */
	if (connect(socket_cli, (struct sockaddr *)&sev_addr, sizeof(sev_addr)) < 0)
	{
		std::cout << "connect error" << std::endl;
		return -1;
	}
	else
		std::cout << "connected successfullly!" << std::endl;
	
	// 发送频率10hz
	ros::Rate loop_rate(10);
	ros::Subscriber subscribe_action;
    ros::Subscriber subscribe_vel;
	
	// 打开电源开关
	send(socket_cli, harvest.harvestcmd2_on, sizeof(harvest.harvestcmd2_on), 0);
	ros::Duration(0.1).sleep();

	while(ros::ok()){
		
		// 赋值心跳指令
		for(int i=0;i<13;i++){
			harvest.harvestcmd[i]=harvest.harvestcmd0[i];
		}

		// 回调函数接受ros话题速度、收割机构
		subscribe_action = n.subscribe("/harvest_action", 10, &subscriberCallback_harvest_action);
    	subscribe_vel = n.subscribe("/harvest_vel", 10, &subscriberCallback_harvest_vel);
		
		// 如果接受到收割机构控制指令1、如果接受到速度指令2
		if(harvest.harvest_state == 1){
			// 控制推杆
			if(harvest.harvest_push_rod==0){
				send(socket_cli, harvest.harvestcmd1_stop, sizeof(harvest.harvestcmd1_stop), 0);
				ros::Duration(0.1).sleep();
			}else if(harvest.harvest_push_rod==1){
				send(socket_cli, harvest.harvestcmd1_long, sizeof(harvest.harvestcmd1_long), 0);
				ros::Duration(0.1).sleep();
			}else if(harvest.harvest_push_rod==2){
				send(socket_cli, harvest.harvestcmd1_short, sizeof(harvest.harvestcmd1_short), 0);
				ros::Duration(0.1).sleep();
			}
			// 控制平台
			if(harvest.harvest_platform==1){
				send(socket_cli, harvest.harvestcmd3_up, sizeof(harvest.harvestcmd3_up), 0);
				ros::Duration(0.1).sleep();
			}else if(harvest.harvest_platform==2){
				send(socket_cli, harvest.harvestcmd3_up_stop, sizeof(harvest.harvestcmd3_up_stop), 0);
				ros::Duration(0.1).sleep();
			}else if(harvest.harvest_platform==3){
				send(socket_cli, harvest.harvestcmd4_down, sizeof(harvest.harvestcmd4_down), 0);
				ros::Duration(0.1).sleep();
			}else if(harvest.harvest_platform==4){
				send(socket_cli, harvest.harvestcmd4_down_stop, sizeof(harvest.harvestcmd4_down_stop), 0);
				ros::Duration(0.1).sleep();
			}

			// 控制收割装置
			harvest.harvest_cut_device_cmd(harvest.harvest_knife,harvest.harvest_shake,harvest.harvestcmd);
			send(socket_cli, harvest.harvestcmd, sizeof(harvest.harvestcmd), 0);
			ros::Duration(0.1).sleep();
			//控制传送带
			harvest.harvest_conveyor_cmd(harvest.harvest_conveyor, harvest.harvestcmd);
			send(socket_cli, harvest.harvestcmd, sizeof(harvest.harvestcmd), 0);
			ros::Duration(0.1).sleep();

			harvest.harvest_state = 0;
		}else if(harvest.harvest_state == 2){
			// 控制左右轮
			harvest.harvest_vel_cmd(harvest.harvest_left_vel, harvest.harvest_right_vel, harvest.harvestcmd);
			send(socket_cli, harvest.harvestcmd, sizeof(harvest.harvestcmd), 0);
			ros::Duration(0.1).sleep();
			harvest.harvest_state = 0;
		}

		
		send(socket_cli, harvest.harvestcmd, sizeof(harvest.harvestcmd), 0);
        recvbuf_length = recv(socket_cli, recvbuf, sizeof(recvbuf), 0);
		cout<<"recv: ";
		harvest.display(recvbuf, recvbuf_length);
		cout<<endl;
		// 接受数据，解析数据，rospub
		if(recvbuf_length==94){
			harvest.harvest_pub(recvbuf, recvbuf_length);
		}
		ros::spinOnce(); // 进入回调函数
		loop_rate.sleep();// 配合执行频率，sleep一段时间，然后进入下一个循环。
    }
	/*
	 *@fuc: 关闭连接
	 */
	close(socket_cli);
	return 0;
}