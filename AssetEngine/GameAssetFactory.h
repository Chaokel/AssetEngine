#pragma once

#include <string>
#include "IAsset.h"
#include "Texture.h"

class GameAssetFactory
{
public:
	IAsset* Create(std::string type);
};

