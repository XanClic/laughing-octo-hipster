project(03)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} vs2013)

add_executable(03 vs2013/view/demo_window.cpp vs2013/controller/glut_engine.cpp vs2013/cpp4cg3.cpp vs2013/view/window.cpp)
target_link_libraries(03 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

install(TARGETS 03 RUNTIME DESTINATION bin)

SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-function")
