cmake_minimum_required(VERSION 2.8.3)
project(eufs_teleop)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  ackermann_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES turtletold
  CATKIN_DEPENDS geometry_msgs roscpp rosmsgs rospy
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(include 
  ${catkin_INCLUDE_DIRS}
)

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
add_executable(talk src/talk.cpp)
target_link_libraries(talk ${catkin_LIBRARIES})

