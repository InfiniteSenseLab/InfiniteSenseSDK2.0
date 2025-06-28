cmake_minimum_required(VERSION 3.16)

project(infinite_sense_core VERSION 0.1.0)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake CACHE INTERNAL "" FORCE)

find_package(ZeroMQ REQUIRED)

set(PROJECT_INSTALL_DIR ${PROJECT_NAME})

add_compile_options(-fPIC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # 确保强制使用指定的标准
set(CMAKE_CXX_EXTENSIONS OFF)       # 禁用编译器特定的扩展（推荐）

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
  set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O3")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
endif ()
# sudo apt-get install protobuf-compiler libprotobuf-dev
add_subdirectory(third_party/proto_msg)
add_subdirectory(third_party/serial)
add_subdirectory(third_party/udp)
add_library(${PROJECT_NAME} SHARED
  src/infinite_sense.cpp
  src/trigger.cpp
  src/usb.cpp
  src/image.cpp
  src/net.cpp
  src/messenger.cpp
  src/ptp.cpp
  src/sensor.cpp
)
target_link_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_INSTALL_RPATH}
    ${ZeroMQ_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    ${ZeroMQ_LIBRARIES}
    serial
    udp
    proto_msg
)

target_include_directories(${PROJECT_NAME} PUBLIC
    include
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    INSTALL_RPATH "$ORIGIN"
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    BUILD_RPATH "$ORIGIN"
)