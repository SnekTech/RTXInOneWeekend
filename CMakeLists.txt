cmake_minimum_required(VERSION 3.0.0)
project(RTXInOneWeekend VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(src)

# add_executable(RTXInOneWeekend main.cpp)
# target_link_libraries(RTXInOneWeekend PRIVATE rtx)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
