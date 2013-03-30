#pragma once

#include <GL/freeglut.h>
#include "Texture.h"

class OpenGLFunctions
{
public:
	OpenGLFunctions(int argc, char** argv);
	~OpenGLFunctions(void);

	void BeginMainLoop();

	static void DrawTexture(Texture* tex);
private:
	static void Display();

	static Texture* testTexture;
};

