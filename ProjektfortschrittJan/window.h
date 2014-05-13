#include <iostream>

namespace view {
	class Window {

		public:
			Window(std::size_t width, std::size_t height, const std::string& name);
			~Window();

			unsigned int width() const;
			unsigned int height() const;
			// request window redisplay
			void invalidate();

		protected:
			virtual bool display();
			virtual void reshape();
			virtual void keyboard();

		private:
			// make sure this Window is the current GLUT Window
			void ensureCurrent() const;

			static void glutDisplay();
			static void glutReshape(int width, int height);
			static void glutKeyboard(unsigned char glut_key, int mouse_x, int mouse_y);

			std::string _name;
			std::size_t _width;
			std::size_t _height;
			int _glut_win_id;
	};
}

void Render() {
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);									// legt die Hintergrundfarbe fest
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);						// Löschung des Hintergrundes des Fensters [GL_COLOR_BUFFER_BIT = Art: Color und Pixel-Buffer löschen | 
	glutSwapBuffers();														// Pufferaustausch
};

void Resize(int width, int height) {
	glViewport(0, 0, width, height);										// Anpassung des Viewports
};

void Keyboard(unsigned char key, int x, int y) {
	if (key == 'q') { glutDestroyWindow((int)glutGetWindow); }				// Abfrage der Taste und Zerstörung des Fensters mit ID = winID
};