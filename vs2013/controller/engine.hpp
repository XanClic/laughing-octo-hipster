#ifndef CONTROLLER__ENGINE_HPP
#define CONTROLLER__ENGINE_HPP

namespace controller
{

class Engine {
public:
    virtual void init(int &argc, char **argv) = 0;
    virtual void run(void) = 0;
};

}

#endif
