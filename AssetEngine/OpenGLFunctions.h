#pragma once

#include <GL/freeglut.h>
#include "Texture.h"

class OpenGLFunctions
{
public:
	OpenGLFunctions(int argc, char** argv);
	~OpenGLFunctions(void);

	static void DrawTexture(Texture* tex);
private:

};

