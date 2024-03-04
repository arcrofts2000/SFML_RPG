#include "Sprite.h"
#include "../System/Assets/AssetManager.h"
#include "../System/Context/SysContextProvider.h"
#include "RenderManager.h"

Sprite::Sprite()
	:m_bInitialised(false)
	,m_isUIObject(false)
{
}

Sprite::~Sprite()
{
	if (m_isUIObject) {
		C_SysContext::Get<RenderManager>()->RemoveUIRenderObject(this);
	}
	else {
		C_SysContext::Get<RenderManager>()->RemoveRenderObject(this);
	}
	
}

void Sprite::Initialise(const char* filename, const int x, const int y, const int sizeX, const int sizeY, bool isUIObject)
{
	AssetManager* pAssetManager = C_SysContext::Get<AssetManager>();
	setTexture(pAssetManager->GetTexture(filename));
	setPosition(sf::Vector2f(x, y));
	setScale(sf::Vector2f(sizeX, sizeY));
	m_bInitialised = true;
	m_isUIObject = isUIObject;
	
	if (m_isUIObject) {
		C_SysContext::Get<RenderManager>()->AddUIRenderObject(this);
	}
	else {
		C_SysContext::Get<RenderManager>()->AddRenderObject(this);
	}
	
}
