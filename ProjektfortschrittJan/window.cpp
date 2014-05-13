#include "GL/freeglut.h"
#include "window.h"
#include <string>
#include <cstring>


class Window {

	int _glut_win_id;

	Window(size_t width, size_t height, const std::string& name) {
		glutInitWindowSize(width, height);								// Fenstergrösse festlegen(Breite, Höhe)

		char* cptr = new char[name.size() + 1];
		std::strncpy(cptr, name.c_str(), name.size());

		_glut_win_id = glutCreateWindow(cptr);							// erstellt Fenster mit Titel und speichert ID in winID
	};

	static void glutDisplay() {
		glutDisplayFunc(&Render);										// Funktion zum zeichnen des Bildes
	};

	static void glutReshape(int width, int height) {
		glutReshapeFunc(&Resize);										// Funktion die auf Größenänderungen des Fensers eingeht
	};

	static void glutKeyboard(unsigned char glut_key, int mouse_x, int mouse_y) {
		glutKeyboardFunc(&Keyboard);									// Funktion für Keyboardevents
	};



};