cmake_minimum_required(VERSION 3.0.2)
project(jetbot_ds4_manual)

find_package(catkin REQUIRED roscpp std_msgs ds4_driver)

catkin_package(CATKIN_DEPENDS roscpp std_msgs ds4_driver)


include_directories(${catkin_INCLUDE_DIRS})

add_executable(${PROJECT_NAME}_controller src/manual_controller.cpp)
add_dependencies(${PROJECT_NAME}_controller ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_controller ${catkin_LIBRARIES})

