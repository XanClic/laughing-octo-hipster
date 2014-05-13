#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <cstddef>
#include <string>

namespace view
{

class Window {
public:
    Window(size_t width, size_t height, const std::string &name);
    ~Window(void);

    unsigned width(void) const
    { return _width; }
    unsigned height(void) const
    { return _height; }

    // request window redisplay
    void invalidate(void);

protected:
    virtual bool display(void);
    virtual void reshape(void);
    virtual void keyboard(unsigned char key);

private:
    // make sure this window is the current GLUT window
    void ensureCurrent(void) const;

    static void glutDisplay(void);
    static void glutReshape(int width, int height);
    static void glutKeyboard(unsigned char glut_key, int mouse_x, int mouse_y);

    std::string _name;
    size_t      _width;
    size_t      _height;
    int         _glut_win_id;
}; // Window

} // view::

#endif
