set(target PerformanceTests)

file(GLOB srcs "*.cpp")

add_executable(${target} ${srcs})
target_link_libraries(${target} benchmark benchmark_main lib_OptimizationTask)
