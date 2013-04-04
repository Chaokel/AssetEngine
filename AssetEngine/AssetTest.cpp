#include "OpenGLFunctions.h"
#include "Terrain.h"

OpenGLFunctions* ogl;
Terrain* terrain = new Terrain();
float _angle = 60.0f;

void cleanup()
{
	delete terrain;
}

void Keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 27:
		cleanup();
		exit(0);
	}
}

void Resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(-_angle, 0.0f, 1.0f, 0.0f);

	ogl->RenderTerrain(terrain);

	glutSwapBuffers();
}

void update(int value)
{
	_angle += 1.0f;
	if(_angle > 360)
	{
		_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);

	glutCreateWindow("Terrain");
	ogl = new OpenGLFunctions();

	terrain->SetFile("heightmap.bmp");
	terrain->Load();

	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutReshapeFunc(Resize);
	glutTimerFunc(25, update, 0);

	glutMainLoop();
	return 0;
}