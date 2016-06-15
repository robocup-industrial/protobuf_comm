cmake_minimum_required(VERSION 2.8.7)
project(protobuf_comm)

find_package(Boost 1.46.1 REQUIRED thread system)
find_package(OpenSSL REQUIRED)
find_package(Protobuf REQUIRED)
find_package(catkin REQUIRED)

add_definitions("-std=c++0x")
add_definitions("-DHAVE_LIBCRYPTO")

include_directories(
  ..
  ${Boost_INCLUDE_DIRS}
  ${OPENSSL_INCLUDE_DIR}
  ${PROTOBUF_INCLUDE_DIRS}
)

catkin_package(
  DEPENDS
    Boost
    OpenSSL
    Protobuf
  INCLUDE_DIRS
    ..
    ${Boost_INCLUDE_DIRS}
    ${OPENSSL_INCLUDE_DIR}
    ${PROTOBUF_INCLUDE_DIRS}
  LIBRARIES
    protobuf_comm
)

set(PROTOBUF_COMM_SOURCES
  client.cpp
  crypto.cpp
  message_register.cpp
  peer.cpp
  server.cpp
)
set(PROTOBUF_COMM_HEADERS
  client.h
  crypto.h
  frame_header.h
  message_register.h
  peer.h
  queue_entry.h
  server.h
  version.h
)

add_library(protobuf_comm SHARED ${PROTOBUF_COMM_SOURCES})
target_link_libraries(protobuf_comm ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES} ${PROTOBUF_LIBRARIES})

file(MAKE_DIRECTORY ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_INCLUDE_DESTINATION}/${PROJECT_NAME} )

add_custom_target(${PROJECT_NAME}_copy_headers ALL)

foreach(File ${PROTOBUF_COMM_HEADERS})
  add_custom_command(TARGET ${PROJECT_NAME}_copy_headers POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/${File} ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_INCLUDE_DESTINATION}/${PROJECT_NAME}
  )
endforeach()
 
install(
  TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(FILES ${PROTOBUF_COMM_HEADERS}
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)

