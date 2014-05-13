#ifndef VIEW__DEMO_WINDOW_HPP
#define VIEW__DEMO_WINDOW_HPP

#include <chrono>

#include "window.hpp"

namespace view
{

class DemoWindow: public Window {
public:
    DemoWindow(size_t width, size_t height, const std::string &name);

private:
    virtual bool display(void) final;
    virtual void reshape(void) final;

    std::chrono::time_point<std::chrono::steady_clock> tp_start;
};

}

#endif
