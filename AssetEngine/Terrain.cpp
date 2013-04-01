#include "Terrain.h"


Terrain::Terrain(void)
{
	iWidth = 0;
	iHeight = 0;
}

Terrain::Terrain(std::string file)
{
	sFilepath = file;
}


Terrain::~Terrain(void)
{
}

void Terrain::Load()
{
	unsigned char header[64];
	FILE * file = fopen(sFilepath.c_str(), "rb");

	if(!file)
	{
		// TODO throw error cannot open
		std::cout << "ERROR1" << std::endl;
	}

	if(fread(header, 1, 54, file) != 54)
	{
		// TODO throw error
		// not a correct BMP file
		std::cout << "ERROR2" << std::endl;
	}

	// BMP files always begin with BM
	if(header[0] != 'B' || header[1] != 'M')
	{
		std::cout << "ERROR3" << std::endl;
		// TODO throw error
		// not a correct BMP file
	}

	// Make sure this is a 24bpp file
	if( *(int*)&(header[0x1E]) != 0)
	{
		std::cout << "ERROR4" << std::endl;
		// TODO throw error
		// not a correct BMP file
	}
	if( *(int*)&(header[0x1C]) != 24)
	{
		std::cout << "ERROR5" << std::endl;
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

	for(int i = 0; i < iImageSize; i++)
	{
		
	}
}