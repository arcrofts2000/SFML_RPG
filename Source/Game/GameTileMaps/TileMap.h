#pragma once
#include <SFML\Graphics.hpp>
#include "../../Engine/Core/GameObject.h"
#include "../GameData/SpritesheetDef.h"


class TileMap :
	public GameObject,
	public sf::Drawable,
	public sf::Transformable
{
public:

							TileMap();
							~TileMap();

	virtual void			Initialise()					override;
	virtual void			Update()						override;
	virtual void			GetPosition(int& x, int& y)		override;
	
	bool					LoadFromSpritesheetDef(SpritesheetDef* pSpritesheetDef, const int* tiles, unsigned int width, unsigned int height);

private:

	virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	sf::VertexArray			m_Vertices;
	sf::Texture*			m_pTileset;

};

