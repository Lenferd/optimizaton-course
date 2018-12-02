set(INCLUDE_DIR ${INCLUDE_DIR} ${CMAKE_CURRENT_LIST_DIR} CACHE INTERNAL "DIRS")
# Application
include_directories(${INCLUDE_DIR})
set(target OptimizationTask)

file(GLOB impl1 impl1.hpp main1.cpp)
add_executable(${target} ${impl1})
# set_target_properties(${target} PROPERTIES LINKER_LANGUAGE CXX)

set(target lib_${target})
file(GLOB hrcs "*.hpp")

add_library(${target} STATIC ${hrcs})
set_target_properties(${target} PROPERTIES LINKER_LANGUAGE CXX)
