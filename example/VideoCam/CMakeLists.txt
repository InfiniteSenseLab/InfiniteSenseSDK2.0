cmake_minimum_required(VERSION 3.16)

project(video_cam VERSION 1.0)
message(STATUS "System Processor: ${CMAKE_SYSTEM_PROCESSOR}")

find_package(Threads REQUIRED)
find_package(OpenCV QUIET)
if(NOT OpenCV_FOUND)
  message(FATAL_ERROR "OpenCV not found! Please install OpenCV and make sure it's visible to CMake.")
endif()

message(STATUS "Found OpenCV version: ${OpenCV_VERSION}")
message(STATUS "OpenCV include dirs: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")

if(OpenCV_FOUND)
# **************************编译普通节点*****************************
add_executable(${PROJECT_NAME}
        main.cpp
        video_cam.cpp
        video_cam.h
)
target_link_directories(${PROJECT_NAME} PRIVATE )
target_link_libraries(${PROJECT_NAME} PRIVATE
        infinite_sense_core
        ${OpenCV_LIBS}
        Threads::Threads
)
target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
set_target_properties(${PROJECT_NAME} PROPERTIES INSTALL_RPATH "$ORIGIN")

# **************************编译ROS2节点*****************************
find_package(rclcpp QUIET)
if (NOT rclcpp_FOUND)
    message(STATUS "rclcpp not found. ROS2 demo will not be built")
else ()
    message(STATUS "rclcpp found. ROS2 demo will be built")
    find_package(ament_cmake REQUIRED)
    find_package(std_msgs REQUIRED)
    find_package(sensor_msgs REQUIRED)
    find_package(image_transport REQUIRED)
    find_package(OpenCV REQUIRED)
    find_package(cv_bridge REQUIRED)
    add_executable(${PROJECT_NAME}_ros2
            main_ros2.cpp
            video_cam.cpp
            video_cam.h
    )
    target_link_directories(${PROJECT_NAME}_ros2 PRIVATE ${OpenCV_LIBS})
    target_include_directories(${PROJECT_NAME}_ros2 PUBLIC ${OpenCV_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME}_ros2
            infinite_sense_core
            ${OpenCV_LIBRARIES}
    )
    set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
    ament_target_dependencies(${PROJECT_NAME}_ros2
            rclcpp
            std_msgs
            sensor_msgs
            image_transport
            OpenCV
            cv_bridge
    )
    install(TARGETS ${PROJECT_NAME}_ros2
            DESTINATION lib/${PROJECT_NAME}
    )
    install(TARGETS infinite_sense_core
            DESTINATION lib/${PROJECT_NAME}
    )
    ament_package()
endif ()

# **************************编译ROS1节点*****************************
find_package(catkin QUIET)
if (NOT catkin_FOUND)
    message(STATUS "catkin not found, ROS1 demo will not be built")
else ()
    message(STATUS "catkin found. ROS1 demo will be built")
    find_package(catkin REQUIRED COMPONENTS
            roscpp
            sensor_msgs
            cv_bridge
            image_transport
            geometry_msgs
    )
    file(GLOB_RECURSE SOURCE_FILES
            main_ros.cpp
            video_cam.cpp
            video_cam.h
    )
    add_executable(${PROJECT_NAME}_ros ${SOURCE_FILES})
    target_link_directories(${PROJECT_NAME}_ros PRIVATE ${OpenCV_LIBS})
    target_link_libraries(${PROJECT_NAME}_ros
            infinite_sense_core
            Threads::Threads
            ${catkin_LIBRARIES}
    )
    target_include_directories(${PROJECT_NAME}_ros PRIVATE
            ${catkin_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS}
    )
    target_compile_definitions(${PROJECT_NAME}_ros PUBLIC -DROS_PLATFORM)
endif ()
endif()