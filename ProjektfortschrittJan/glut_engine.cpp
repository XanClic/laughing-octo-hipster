#include "eingine.h"
#include <tchar.h>
#include "GL/freeglut.h"
#include <stdio.h>

/* void Render();
void Resize(int width, int height);
void Keyboard(unsigned char key, int x, int y);

int winID;

int _tmain(int argc, _TCHAR* argv[]) {
	glutInit(&argc, argv);											// Initialisiert die GLUT-Bibliothek
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);		// Double-Buffer | Tiefenpuffer | RGB-Farbpuffer
	glutInitWindowSize(640, 480);									// Fenstergrösse festlegen(Breite, Höhe)
	winID = glutCreateWindow("cpp4cg3-Window");						// erstellt Fenster mit Titel und speichert ID in winID

	// GLUT-Funktionen (Callbacks)
	glutDisplayFunc(&Render);										// Funktion zum zeichnen des Bildes
	glutReshapeFunc(&Resize);										// Funktion die auf Größenänderungen des Fensers eingeht
	glutKeyboardFunc(&Keyboard);									// Funktion für Keyboardevents

	glutMainLoop();													// Massage-Loop (Kommunikation mit Betriebssystem)
}

void Render() {
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);							// legt die Hintergrundfarbe fest
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Löschung des Hintergrundes des Fensters [GL_COLOR_BUFFER_BIT = Art: Color und Pixel-Buffer löschen | 
	glutSwapBuffers();												// Pufferaustausch
};

void Resize(int width, int height) {
	glViewport(0, 0, width, height);								// Anpassung des Viewports
};

void Keyboard(unsigned char key, int x, int y) {
	if (key == 'q') { glutDestroyWindow(winID); }					// Abfrage der Taste und Zerstörung des Fensters mit ID = winID
}; */