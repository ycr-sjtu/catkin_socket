0. 安装依赖
sudo apt-get install ros-melodic-nmea-navsat-driver libgps-dev

1. 
source devel/setup.bash

2. 
roslaunch nmea_navsat_driver gpsStart.launch


---
都写到launch里面了,不需要下面的.
3.使用nmea_navsat_driver驱动中的节点接收话题/nmea_sentence（/nmea_msgs/Sentence格式）并发布/fix话题（/NavSatFix格式）
rosrun nmea_navsat_driver nmea_topic_driver

4.打开gps_viewer和Rviz节点，并在Rviz界面中添加/gps_path数据（可视化）：
rosrun gps_viewer gps_viewer
rosrun rviz rviz

