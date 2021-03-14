cmake_minimum_required(VERSION 3.16.0)

project(AutomateTemplate)

#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
find_library(automate-core NAMES libautomate-core.so)

add_executable(main main.cxx)
target_link_libraries(main automate-core)
