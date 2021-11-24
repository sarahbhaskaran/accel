#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "accel_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block accel/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_accel_geometry_msgs_Twist> Sub_accel_33;

// For Block accel/Publish
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_accel_geometry_msgs_Twist> Pub_accel_32;

void slros_node_init(int argc, char** argv);

#endif
