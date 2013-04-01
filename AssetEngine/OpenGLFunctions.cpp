#include "OpenGLFunctions.h"

OpenGLFunctions::OpenGLFunctions()
{
}


OpenGLFunctions::~OpenGLFunctions(void)
{
}


GLuint OpenGLFunctions::LoadTexture(Texture* tex)
{
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
		0,                            //0 for now
		GL_RGB,                       //Format OpenGL uses for image
		tex->GetWidth(), tex->GetHeight(),  //Width and height
		0,                            //The border of the image
		GL_BGR, //GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
		//as unsigned numbers
		tex->GetData());               //The actual pixel data
	return textureId; //Returns the id of the texture
}