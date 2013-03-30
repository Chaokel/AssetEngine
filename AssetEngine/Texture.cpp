#include "Texture.h"


Texture::Texture(void)
{
	iTexture = NULL;
}

Texture::Texture(std::string filename)
{

}


Texture::~Texture(void)
{

}

Texture::Texture(const Texture& tex)
{
	iTexture = tex.iTexture;
}

Texture& Texture::operator=(const Texture& tex)
{
	iTexture = tex.iTexture;

	return *this;
}

void Texture::Load(std::string filename)
{
	
}