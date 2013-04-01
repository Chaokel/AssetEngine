#pragma once

#include "IAsset.h"
#include <iostream>

class Terrain :
	public IAsset
{
public:
	Terrain(void);
	Terrain(std::string file);
	~Terrain(void);

	virtual void Load();
private:
	// Data read from the header
	unsigned int iDataPos;
	unsigned int iWidth, iHeight;
	unsigned int iImageSize;
	// RGB Data
	unsigned char * cData;
};

