#ifdef _WIN32
#include <tchar.h>
#endif
#include "GL/freeglut.h"

#ifdef _WIN32
int _tmain(int argc, _TCHAR* argv[]) {
#else
int main(int argc, char *argv[]) {
#endif
	glutInit(&argc, argv);
	return 0;
}
