#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "accel";

// For Block accel/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_accel_geometry_msgs_Twist> Sub_accel_33;

// For Block accel/Publish
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_accel_geometry_msgs_Twist> Pub_accel_32;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

