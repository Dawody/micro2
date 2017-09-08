cmake_minimum_required(VERSION 2.8)
project( imageprocessing )
find_package( OpenCV REQUIRED )
add_executable( imageprocessing imageprocessing.cpp)
target_link_libraries(imageprocessing ${OpenCV_LIBS})


