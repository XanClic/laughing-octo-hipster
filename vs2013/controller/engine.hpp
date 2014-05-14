#ifndef CONTROLLER__ENGINE_HPP
#define CONTROLLER__ENGINE_HPP

namespace controller
{

class Engine {
public:
    virtual void init(int &argc, char **argv) = 0; // = 0 bedeutet soviel wie abstract, also dass es keine Implementation gibt
    virtual void run(void) = 0;
};

}

#endif
