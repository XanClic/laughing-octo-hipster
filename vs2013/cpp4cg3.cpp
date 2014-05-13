#ifdef _WIN32
#include <tchar.h>
#endif

#include <cstdio>
#include <memory>
#include "controller/glut_engine.hpp"


#ifdef _WIN32
int _tmain(int argc, _TCHAR* argv[]) {
#else
int main(int argc, char *argv[])
{
#endif
    std::shared_ptr<controller::Engine> game_engine(new controller::GlutEngine);

    game_engine->init(argc, argv);
    game_engine->run();

    return 0;
}
