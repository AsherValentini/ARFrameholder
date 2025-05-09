cmake_minimum_required(VERSION 3.10)

project(ARFrameHolderProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add OpeCV at a later stage 
# find_package(OpenCV REQUIRED)

add_executable(ar_frame_holder
    src/main.cpp
    src/ar_frame_holder.cpp
)
