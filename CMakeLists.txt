cmake_minimum_required(VERSION 3.16)

project(pose_estimation_in_cplusplus)

set(OpenCV_DIR E:/opencv/build)
find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} src/Main.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS}
