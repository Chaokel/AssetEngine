#include "Texture.h"


Texture::Texture(void)
{
	iDataPos = 0;
	iWidth = 0; iHeight = 0;
	iImageSize = 0;
	cData = NULL;
}

Texture::~Texture(void)
{
	delete [] cData;
	cData = NULL;
}

Texture::Texture(const Texture& tex)
{
	
}

Texture& Texture::operator=(const Texture& tex)
{
	

	return *this;
}

void Texture::Load()
{
	unsigned char header[64];
	FILE * file = fopen(sFilepath.c_str(), "rb");

	if(!file)
	{
		// TODO throw error cannot open
		std::cout << "ERROR" << std::endl;
	}

	if(fread(header, 1, 54, file) != 54)
	{
		// TODO throw error
		// not a correct BMP file
		std::cout << "ERROR" << std::endl;
	}

	// BMP files always begin with BM
	if(header[0] != 'B' || header[1] != 'M')
	{
		std::cout << "ERROR" << std::endl;
		// TODO throw error
		// not a correct BMP file
	}

	// Make sure this is a 24bpp file
	if( *(int*)&(header[0x1E]) != 0)
	{
		std::cout << "ERROR" << std::endl;
		// TODO throw error
		// not a correct BMP file
	}
	if( *(int*)&(header[0x1C]) != 24)
	{
		std::cout << "ERROR" << std::endl;
		// TODO throw error
		// not a correct BMP file
	}

	iDataPos = *(int*)&(header[0x0A]);
	iImageSize = *(int*)&(header[0x22]);
	iWidth = *(int*)&(header[0x12]);
	iHeight = *(int*)&(header[0x16]);

	if(iImageSize == 0) 
		iImageSize = iWidth * iHeight * 3;
	if(iDataPos == 0)
		iDataPos = 54;

	cData = new unsigned char[iImageSize];

	fread(cData, 1, iImageSize, file);
	fclose(file);

	std::cout << "Texture loaded" << std::endl;
}

unsigned int Texture::GetDataPos()
{
	return iDataPos;
}

unsigned int Texture::GetWidth()
{
	return iWidth;
}

unsigned int Texture::GetHeight()
{
	return iHeight;
}

unsigned int Texture::GetImageSize()
{
	return iImageSize;
}

unsigned char* Texture::GetData()
{
	return cData;
}