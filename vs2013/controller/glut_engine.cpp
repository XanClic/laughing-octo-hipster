#include <cstdio>
#include <stdexcept>
#include <memory>

#include "GL/freeglut.h"
#include "controller/glut_engine.hpp"
#include "view/demo_window.hpp"


using namespace controller;


static void checkpoint_helper(const char *function, const char *msg)
{
    fprintf(stderr, "%s: checkpoint %s\n", function, msg);
}

#ifdef __GNUC__
#define CHECKPOINT(msg) checkpoint_helper(__PRETTY_FUNCTION__, msg)
#elif defined(_WIN32)
#define CHECKPOINT(msg) checkpoint_helper(__FUNCSIG__, msg)
#else
#define CHECKPOINT(msg) checkpoint_helper(__func__, msg)
#endif


void GlutEngine::init(int &argc, char **argv)
{
    if (instance)
        throw std::logic_error("GlutEngine::init: GlutEngine already initialized");

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInit(&argc, argv);
    // By enabling this, the Window tries to delete itself after the main loop
    // has finished execution. GLUT does not like that.
    // glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

    instance = true;

    CHECKPOINT("post-init");
}


void GlutEngine::run(void)
{
    if (!instance)
        throw std::logic_error("GlutEngine::run: GlutEngine not yet initialized");

    CHECKPOINT("pre-loop");

    std::shared_ptr<view::Window> window(new view::DemoWindow(500, 500, "cpp4cg3-window"));
    glutMainLoop();

    // Only reached if GLUT_ACTION_CONTINUE_EXECUTION has been enabled in init()

    CHECKPOINT("post-loop");
}
