#pragma once

#include <GL/freeglut.h>

class OpenGLFunctions
{
public:
	OpenGLFunctions(int argc, char** argv);
	~OpenGLFunctions(void);

	void BeginMainLoop();
private:
	static void Display();

};

