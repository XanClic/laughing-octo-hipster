#include "eingine.h"
#include <iostream>
#include "GL/freeglut.h"



namespace controller {

	class GlutEngine : public controller::Engine {

	private:
		int instance = 0;

	public:

		void init(int argc, char* argv[]) {
			if (instance == 0) {
				instance = 1;
				glutInit(&argc, argv);
				glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, 0);
				printf("GlutEngine::init: checkpoint\n");
			}
			else {
				throw std::logic_error("");
			}
		}

		void run() {
			if (instance != 0) {
				printf("GlutEngine::run: checkpoint\n");
				glutMainLoop();
			}
			else {
				throw std::logic_error("");
			}
		}
	};

}