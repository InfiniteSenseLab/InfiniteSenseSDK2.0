cmake_minimum_required(VERSION 3.16)

project(net_cam VERSION 1.0)
message(STATUS "System Processor: ${CMAKE_SYSTEM_PROCESSOR}")
if (CMAKE_SYSTEM_PROCESSOR MATCHES "arm" OR CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
    set(PLATFORM_DIR "arm")
    set(MVCAM_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/mvcam/lib/aarch64)
elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64" OR CMAKE_SYSTEM_PROCESSOR MATCHES "amd64")
    set(PLATFORM_DIR "x86")
    set(MVCAM_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/mvcam/lib/x86/64)
else ()
    message(STATUS "Unknown Architecture")
    set(PLATFORM_DIR "Unknown")
endif ()
message(STATUS "Find MVCAM_LIB_DIR : ${MVCAM_LIB_DIR}")
find_package(Threads REQUIRED)
# **************************编译普通节点*****************************
add_executable(${PROJECT_NAME}
        main.cpp
        mv_cam.cpp
        mv_cam.h
)
target_link_directories(${PROJECT_NAME} PRIVATE ${MVCAM_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE
        infinite_sense_core
        MvCameraControl
        Threads::Threads
)
target_include_directories(${PROJECT_NAME} PRIVATE mvcam/include)
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
            mv_cam.cpp
            mv_cam.h
    )
    target_link_directories(${PROJECT_NAME}_ros2 PRIVATE ${MVCAM_LIB_DIR})
    target_include_directories(${PROJECT_NAME}_ros2 PUBLIC mvcam/include ${OpenCV_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME}_ros2
            infinite_sense_core
            ${OpenCV_LIBRARIES}
            MvCameraControl
    )
    set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
    set(CMAKE_INSTALL_RPATH ${MVS_LIBRARIES})
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
            mv_cam.cpp
            mv_cam.h
    )
    add_executable(${PROJECT_NAME}_ros ${SOURCE_FILES})
    target_link_directories(${PROJECT_NAME}_ros PRIVATE ${MVCAM_LIB_DIR})
    target_link_libraries(${PROJECT_NAME}_ros
            infinite_sense_core
            MvCameraControl
            Threads::Threads
            ${catkin_LIBRARIES}
    )
    target_include_directories(${PROJECT_NAME}_ros PRIVATE
            ${catkin_INCLUDE_DIRS} mvcam/include
    )
    target_compile_definitions(${PROJECT_NAME}_ros PUBLIC -DROS_PLATFORM)
endif ()
