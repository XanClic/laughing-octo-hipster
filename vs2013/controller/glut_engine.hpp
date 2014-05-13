#ifndef CONTROLLER__GLUT_ENGINE_HPP
#define CONTROLLER__GLUT_ENGINE_HPP

#include "controller/engine.hpp"

namespace controller
{

class GlutEngine:
    public Engine
{
public:
    virtual void init(int &argc, char **argv) final;
    virtual void run(void) final;

private:
    bool instance = false;
};

}

#endif
