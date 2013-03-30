#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include "IAsset.h"



class Texture:
	public IAsset
{
public:
	Texture(void);
	~Texture(void);

	Texture(const Texture&);
	Texture& operator=(const Texture&);

	virtual void Load();

	unsigned int GetDataPos();
	unsigned int GetWidth();
	unsigned int GetHeight();
	unsigned int GetImageSize();
	unsigned char* GetData();
private:
	// Data read from the header
	unsigned int iDataPos;
	unsigned int iWidth, iHeight;
	unsigned int iImageSize;
	// RGB Data
	unsigned char * cData;
};

