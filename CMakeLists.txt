# Generate the COMPILE COMMANDS, for error not showing in Neovim
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 3.10)

# The name of this project
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

# Set standard
set(CMAKE_CXX_STANDARD 17)

# header file directories
include_directories(/usr/local/include)
include_directories(/opt/homebrew/Cellar/eigen/3.4.0_1/include)

# The name of the gernerated executable
# add_subdirectory(dependencies/lib) # another way of adding executable, but needs another CmakeLists.txt in that dir
file(GLOB_RECURSE MY_SOURCES "dependencies/lib/*.cpp")
add_executable(${ProjectId} ${CMAKE_CURRENT_SOURCE_DIR} main.cpp ${MY_SOURCES})

# find package
# dont how it works yet
find_package(OpenCV REQUIRED)
# linked library
target_link_libraries(${ProjectId} ${OpenCV_LIBRARIES})

# executa process
# execute_process(COMMAND mkdir build
#                 WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
# execute_process(COMMAND cmake ..
#                 COMMAND make .
#                 WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
