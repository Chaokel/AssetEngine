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

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);

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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glutSwapBuffers();
}