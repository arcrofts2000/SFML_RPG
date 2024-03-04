#include "TileMap.h"
#include "../../Engine/System/Assets/AssetManager.h"
#include "../../Engine/Renderer/RenderManager.h"
#include "../../Engine/System/Context/SysContextProvider.h"


TileMap::TileMap()
{}

TileMap::~TileMap()
{
	C_SysContext::Get<RenderManager>()->RemoveRenderObject(this);
}

void TileMap::Initialise()
{

}

void TileMap::Update()
{

}

void TileMap::GetPosition(int& x, int& y)
{

}

bool TileMap::LoadFromSpritesheetDef(SpritesheetDef* pSpritesheetDef, const int* tiles, unsigned int width, unsigned int height)
{
	if (!pSpritesheetDef)
		return false;

	AssetManager* pAssetManager = C_SysContext::Get<AssetManager>();
	m_pTileset = &(pAssetManager->GetTexture(pSpritesheetDef->m_Filename.c_str()));
	std::vector<sf::IntRect> frames;
	for (std::vector<SpritesheetSpriteDef>::iterator iter = pSpritesheetDef->m_pSpriteDefs.begin(); iter != pSpritesheetDef->m_pSpriteDefs.end(); iter++)
	{
		sf::IntRect rect((*iter).m_PosX, (*iter).m_PosY, (*iter).m_Width, (*iter).m_Height);
		frames.push_back(rect);
	}
	int numTiles = 0;
	for (int i = 0; i < width* height; i++)
	{
		int tileNumber = tiles[i];
		if (tileNumber < 0 || tileNumber >= frames.size())continue;
		numTiles++;
	}

	// resize the vertex array to fit the level size
	m_Vertices.setPrimitiveType(sf::Quads);
	m_Vertices.resize(numTiles * 4);
	int quadNum = 0;

	for(unsigned int i = 0; i < width; ++i)
		for(unsigned int j = 0; j < height; ++j)
		{// get the current tile number
			int tileNumber = tiles[i + j * width];
			if(tileNumber < 0 || tileNumber >= frames.size())continue;
			// find its position in the tileset texture
			int tu1 = frames[tileNumber].left;
			int tv1 = frames[tileNumber].top;
			int tu2 = tu1 + frames[tileNumber].width;
			int tv2 = tv1 + frames[tileNumber].height;
			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_Vertices[(quadNum) * 4];
			// define its 4 corners
			quad[0].position =sf::Vector2f(i * frames[tileNumber].width, j * frames[tileNumber].height);
			quad[1].position =sf::Vector2f((i + 1) * frames[tileNumber].width, j * frames[tileNumber].height);
			quad[2].position =sf::Vector2f((i + 1) * frames[tileNumber].width, (j + 1) * frames[tileNumber].height);
			quad[3].position =sf::Vector2f(i * frames[tileNumber].width, (j + 1) * frames[tileNumber].height);
			// define its 4 texture coordinates
			quad[0].texCoords =sf::Vector2f(tu1, tv1);
			quad[1].texCoords =sf::Vector2f(tu2, tv1);
			quad[2].texCoords =sf::Vector2f(tu2, tv2);
			quad[3].texCoords =sf::Vector2f(tu1, tv2);
			quadNum++;
		}
	C_SysContext::Get<RenderManager>()->AddRenderObject(this);

	return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *=getTransform();

	// apply the tileset texture
	states.texture = m_pTileset;

	// draw the vertex array
	target.draw(m_Vertices, states);
}
