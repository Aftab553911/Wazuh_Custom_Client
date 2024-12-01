# # Minimum CMake version required
# cmake_minimum_required(VERSION 3.10)

# # Project name and version
# project(MyProject VERSION 1.0)

# # Specify C++ standard
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Add include directories (to find the headers in 'include' directory)
# include_directories(${PROJECT_SOURCE_DIR}/include)

# # Add source files
# add_executable(wazuh_client 
#     src/main.cpp
#     src/DataCollector.cpp
#     src/ManagerConnection.cpp
#     src/Logger.cpp
#     src/ConfigParser.cpp
# )

# # Optionally, link external libraries if needed
# # target_link_libraries(wazuh_client SomeLibrary)
cmake_minimum_required(VERSION 3.10)


set(CMAKE_CXX_STANDARD 11)

add_executable(wazuh_client
    
    src/main.cpp
    src/Logger.cpp 
    src/ManagerConnection.cpp
    src/ConfigParser.cpp
    src/DataCollector.cpp
)
project(WazuhClient)
target_include_directories(wazuh_client PRIVATE include)
# Add this to your CMakeLists.txt to link ws2_32.lib
target_link_libraries(wazuh_client ws2_32)

