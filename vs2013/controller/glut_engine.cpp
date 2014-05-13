#include <cstdio>
#include <stdexcept>
#include <memory>

#include "GL/freeglut.h"
#include "controller/glut_engine.hpp"
#include "view/demo_window.hpp"


using namespace controller;

#ifdef _WIN32
#define CHECKPOINT(msg) fprintf(stderr, "%s: checkpoint " msg "\n", __func__)
#else
#define CHECKPOINT(msg) fprintf(stderr, "%s: checkpoint " msg "\n", __PRETTY_FUNCTION__)
#endif

static bool initialized;


void GlutEngine::init(int &argc, char **argv)
{
    if (initialized) {
        throw std::logic_error("GlutEngine::init: GlutEngine already initialized");
    }

    glutInit(&argc, argv);
    // By enabling this, the Window tries to delete itself after the main loop
    // has finished execution. GLUT does not like that.
    // glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

    initialized = true;

    CHECKPOINT("post-init");
}


void GlutEngine::run(void)
{
    if (!initialized)
        throw std::logic_error("GlutEngine::run: GlutEngine not yet initialized");

    CHECKPOINT("pre-loop");

    std::shared_ptr<view::Window> window(new view::DemoWindow(500, 500, "cpp4cg3-window"));
    glutMainLoop();

    // Only reached if GLUT_ACTION_CONTINUE_EXECUTION has been enabled in init()

    CHECKPOINT("post-loop");
}
