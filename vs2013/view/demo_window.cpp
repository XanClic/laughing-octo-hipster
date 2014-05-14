#include <chrono>
#include <iostream>

#include "GL/freeglut.h"
#include "demo_window.hpp" //#include "view/demo_window.hpp"

using namespace view;

DemoWindow::DemoWindow(size_t width, size_t height, const std::string &name) :

	Window(width, height, name)
{
#if 0
	glClearColor(0, 1, 0, 1.f);
#else
    glClearColor(.1f, .2f, .3f, 1.f);
#endif
	tp_start = std::chrono::steady_clock::now(); // Startzeit speichern.
	//std::chrono::time_point tp_start = std::chrono::steady_clock::now();
}

bool view::DemoWindow::display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
#if 0
	return false;
#endif

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0., -7., 0., 0., 0., 0., 0., 0., 1.);


	std::chrono::steady_clock::time_point tp_now = std::chrono::steady_clock::now();
    //std::chrono::time_point<std::chrono::steady_clock> tp_now = std::chrono::steady_clock::now(); // VS kann damit nicht umgehen.

	std::chrono::duration<float> time_diff = std::chrono::duration_cast<std::chrono::duration<double>>(tp_now - tp_start); // Um fancy zu sein, std::ratio<5, 360> als zweiten std::chrono::duration tpl Param nutzen.

    glRotatef(time_diff.count() / 5 * 360, 0.f, 0.f, 1.f);
	
    glColor3f(.75f, .75f, .75f);

#if 1
    glBegin(GL_LINES);
    glVertex3i( 1,  1,  1); glVertex3i(-1,  1,  1);
    glVertex3i(-1,  1,  1); glVertex3i(-1,  1, -1);
    glVertex3i(-1,  1, -1); glVertex3i( 1,  1, -1);
    glVertex3i( 1,  1, -1); glVertex3i( 1,  1,  1);

    glVertex3i( 1,  1,  1); glVertex3i( 1, -1,  1);
    glVertex3i(-1,  1,  1); glVertex3i(-1, -1,  1);
    glVertex3i(-1,  1, -1); glVertex3i(-1, -1, -1);
    glVertex3i( 1,  1, -1); glVertex3i( 1, -1, -1);

    glVertex3i( 1, -1,  1); glVertex3i(-1, -1,  1);
    glVertex3i(-1, -1,  1); glVertex3i(-1, -1, -1);
    glVertex3i(-1, -1, -1); glVertex3i( 1, -1, -1);
    glVertex3i( 1, -1, -1); glVertex3i( 1, -1,  1);
    glEnd();
#else
	glutWireCube(2.); //glutWireTeapot(2.);
#endif


    return true;
}

void DemoWindow::reshape(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30., static_cast<double>(width()) / height(), 2.0, 20.0);
}
