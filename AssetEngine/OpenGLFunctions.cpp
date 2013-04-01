#include "OpenGLFunctions.h"

OpenGLFunctions::OpenGLFunctions(int argc, char** argv)
{
	
}


OpenGLFunctions::~OpenGLFunctions(void)
{
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