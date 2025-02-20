#project name (can be different from directory name)
project(AMAZEGEN)

# source files 
file(GLOB AMAZEGEN_SOURCES "src/*.cpp")

#include directories
include_directories("include")

#create executable or library 
add_executable(amaze ${AMAZEGEN_SOURCES})

# link to other libraries (if needed)
target_link_libraries(amaze PRIVATE SFML::Graphics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -pedantic")
