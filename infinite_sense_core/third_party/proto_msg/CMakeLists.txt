project(proto_msg)

set(CMAKE_BUILD_TYPE "RelWithDebInfo")

find_package(Protobuf 3.6.1 REQUIRED)

message(STATUS "Protobuf_VERSION: " ${Protobuf_VERSION})
message(STATUS "Protobuf_INCLUDE_DIR: " ${Protobuf_INCLUDE_DIR})

if (NOT MSVC)
  set(PROTO_META_BASE_DIR ${CMAKE_BINARY_DIR}/message)
  if (EXISTS "${CMAKE_BINARY_DIR}/message" AND IS_DIRECTORY "${CMAKE_BINARY_DIR}/message")
    message(STATUS "${PROTO_META_BASE_DIR} Check ok!")
  else ()
    file(MAKE_DIRECTORY ${PROTO_META_BASE_DIR})
  endif ()

  message(STATUS "proto_msg meta files path: ${PROTO_META_BASE_DIR}")

  list(APPEND PROTO_FLAGS -I${CMAKE_CURRENT_SOURCE_DIR})
  file(GLOB_RECURSE MSG_PROTOS ${CMAKE_CURRENT_SOURCE_DIR}/*.proto)

  set(MESSAGE_HDRS "")
  set(MESSAGE_SRC "")

  foreach (msg ${MSG_PROTOS})
       get_filename_component(FIL_WE ${msg} NAME_WE)

    list(APPEND MESSAGE_SRC "${PROTO_META_BASE_DIR}/${FIL_WE}.pb.cc")
    list(APPEND MESSAGE_HDRS "${PROTO_META_BASE_DIR}/${FIL_WE}.pb.h")

    add_custom_command(
        OUTPUT "${PROTO_META_BASE_DIR}/${FIL_WE}.pb.cc"
        "${PROTO_META_BASE_DIR}/${FIL_WE}.pb.h"
        COMMAND ${PROTOBUF_PROTOC_EXECUTABLE} ${PROTO_FLAGS} --cpp_out=${PROTO_META_BASE_DIR} ${msg}
        DEPENDS ${msg}
        COMMENT "Running C++ protocol buffer compiler on ${msg}"
        VERBATIM
    )
  endforeach ()

  set_source_files_properties(${MESSAGE_SRC} ${MESSAGE_HDRS} PROPERTIES GENERATED TRUE)

  add_custom_target(generate_message ALL
      DEPENDS ${MESSAGE_SRC} ${MESSAGE_HDRS}
      COMMENT "generate message target"
      VERBATIM
  )

else ()
  set(PROTO_META_BASE_DIR .)

  file(GLOB_RECURSE MESSAGE_SRC ${PROTO_META_BASE_DIR}/*.pb.cc)
  message(STATUS "MESSAGE_SRC: ${MESSAGE_SRC}")

endif ()

add_library(${PROJECT_NAME} SHARED
    ${MESSAGE_SRC}
)
if (NOT MSVC)
else ()
  target_compile_definitions(${PROJECT_NAME}
      PRIVATE
      RoProtobuf_LIBRARY
  )
endif ()

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PROTO_META_BASE_DIR}
    ${Protobuf_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    ${Protobuf_LIBRARY_RELEASE}
)
message(STATUS "create proto_msg OBJECT")

