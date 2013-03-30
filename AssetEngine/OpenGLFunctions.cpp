#include "OpenGLFunctions.h"


OpenGLFunctions::OpenGLFunctions(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH | GLUT_RGBA);
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Asset Engine Tester");

	glutDisplayFunc(OpenGLFunctions::Display);
}


OpenGLFunctions::~OpenGLFunctions(void)
{
}

void OpenGLFunctions::BeginMainLoop()
{
	glutMainLoop();
}

void OpenGLFunctions::Display()
{


	glutSwapBuffers();
}