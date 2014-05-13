project(03)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

add_executable(03 vs2013/cpp4cg3.cpp)
target_link_libraries(03 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

install(TARGETS 03 RUNTIME DESTINATION bin)
