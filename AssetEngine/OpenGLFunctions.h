#pragma once

#include <GL/freeglut.h>
#include "Texture.h"
#include "Terrain.h"
#include "Mesh.h"

class OpenGLFunctions
{
public:
	OpenGLFunctions();
	~OpenGLFunctions(void);

	GLuint LoadTexture(Texture* tex);

	void RenderTerrain(Terrain* ter);
private:

};

