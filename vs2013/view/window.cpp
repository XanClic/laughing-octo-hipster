#include <cstdlib>

#include "GL/freeglut.h"
#include "window.hpp" //#include "view/window.hpp"


using namespace view;


Window::Window(size_t width, size_t height, const std::string &name):
    _name(name),
    _width(width),
    _height(height)
{
    glutInitWindowSize(width, height);
    _glut_win_id = glutCreateWindow(name.c_str());

    glutDisplayFunc(&glutDisplay);
    glutReshapeFunc(&glutReshape);
    glutKeyboardFunc(&glutKeyboard);

    glViewport(0, 0, width, height);

    glutSetWindowData(this);
}

Window::~Window(void)
{
    glutDestroyWindow(_glut_win_id);
}


void Window::invalidate(void)
{
    display();
}


bool Window::display(void)
{
    return false;
}

void Window::reshape(void)
{
}

void Window::keyboard(unsigned char key)
{
    if (key == 'q')
        glutLeaveMainLoop();
}


void Window::ensureCurrent(void) const
{
    glutSetWindow(_glut_win_id);
}


void Window::glutDisplay(void)
{
    Window *inst = reinterpret_cast<Window *>(glutGetWindowData());
    bool redisplay = false;

    if (inst && (inst->_glut_win_id == glutGetWindow()))
        redisplay = inst->display();

    glutSwapBuffers();

    if (redisplay)
        glutPostRedisplay();
}

void Window::glutReshape(int width, int height)
{
    Window *inst = reinterpret_cast<Window *>(glutGetWindowData());

    if (inst && (inst->_glut_win_id == glutGetWindow())) {
        inst->_width = width;
        inst->_height = height;

        glViewport(0, 0, width, height);

        inst->reshape();
    }
}

void Window::glutKeyboard(unsigned char key, int x, int y)
{
    Window *inst = reinterpret_cast<Window *>(glutGetWindowData());

    if (inst && (inst->_glut_win_id == glutGetWindow()))
        inst->keyboard(key);
}
