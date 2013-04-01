#include "Terrain.h"


Terrain::Terrain(void)
{
	iWidth = 0;
	iLength = 0;
	fScale = 255.0f;
	bNormalsComputed = false;
}


Terrain::~Terrain(void)
{
	for(unsigned int i = 0; i < iLength; i++)
	{
		delete[] pHeights[i];
	}

	delete[] pHeights;

	for(unsigned int i = 0; i < iLength; i++)
	{
		delete[] vNormals[i];
	}

	delete[] vNormals;
}

void Terrain::Load()
{
	std::cout << "Loading Terrain" << std::endl;
	Texture* heightmap = new Texture();
	heightmap->SetFile(sFilepath);
	heightmap->Load();

	iWidth = heightmap->GetWidth();
	iLength = heightmap->GetHeight();

	pHeights = new float*[iLength];
	for(int i = 0; i < iLength; i++)
	{
		pHeights[i] = new float[iWidth];
	}

	vNormals = new glm::vec3*[iLength];
	for(int i = 0; i < iLength; i++)
	{
		vNormals[i] = new glm::vec3[iWidth];
	}

	for(int y = 0; y < iLength; y++)
	{
		for(int x = 0; x < iWidth; x++)
		{
			unsigned char color = heightmap->GetData()[3 * (y * iWidth + x)];
			float h = fScale * ((color / 255.0f));
			SetHeight(x, y, h);
		}
	}

	delete heightmap;
	ComputeNormals();
}

unsigned int Terrain::GetWidth()
{
	return iWidth;
}

unsigned int Terrain::GetLength()
{
	return iLength;
}

float Terrain::GetHeight(int x, int z)
{
	return pHeights[z][x];
}

glm::vec3 Terrain::GetNormal(int x, int z)
{
	if(!bNormalsComputed)
	{
		ComputeNormals();
	}

	return vNormals[z][x];
}

void Terrain::SetHeight(int x, int z, float h)
{
	std::cout << "x = " << x << " z = " << z << " h = " << h << std::endl;

	pHeights[z][x] = h;
	bNormalsComputed = false;
}

void Terrain::ComputeNormals()
{

}