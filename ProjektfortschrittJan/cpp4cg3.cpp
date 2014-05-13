#include "glut_engine.h"
#include <iostream>
#include <memory>

int main(int argc, char** argv) {
	std::shared_ptr<controller::Engine> game_engine(new controller::GlutEngine);
	game_engine -> init(argc, argv);
	game_engine -> run();

	return 0;
}