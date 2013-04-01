#pragma once

#include <GL/freeglut.h>
#include <GL/glext.h>
#include "Texture.h"

class OpenGLFunctions
{
public:
	OpenGLFunctions();
	~OpenGLFunctions(void);

	GLuint LoadTexture(Texture* tex);
private:

};

