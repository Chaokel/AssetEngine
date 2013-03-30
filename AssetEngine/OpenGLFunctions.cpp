#include "OpenGLFunctions.h"

Texture* OpenGLFunctions::testTexture = new Texture();

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

	testTexture->SetFile("testtexture.bmp");
	testTexture->Load();
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

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(1.0, 1.0, -10.0);
	glVertex3f(-1.0, 1.0, -10.0);
	glVertex3f(-1.0, -1.0, -10.0);
	glVertex3f(1.0, -1.0, -10.0);
	glEnd();
	DrawTexture(testTexture);

	glutSwapBuffers();
}

void OpenGLFunctions::DrawTexture(Texture* tex)
{
	GLuint textureID;
	glGenTextures(1, &textureID);

	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex->GetWidth(), tex->GetHeight(),
		0, GL_RGB, GL_UNSIGNED_BYTE, tex->GetData());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}