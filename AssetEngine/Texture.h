#pragma once

#include <string>
#include "IAsset.h"

class Texture:
	public IAsset
{
public:
	Texture(void);
	Texture(std::string filename);
	~Texture(void);

	Texture(const Texture&);
	Texture& operator=(const Texture&);

	void Load(std::string filename);
private:
	unsigned int iTexture;
};

