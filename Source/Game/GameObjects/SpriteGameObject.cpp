#include "SpriteGameObject.h"
#include "../../Engine/System/Context/SysContextProvider.h"
#include "../../Engine/System/GameState/GameState.h"
#include "../../Engine/System/GameState/GameStateManager.h"
//-----------CONSTRUCTOR / DESTRUCTOR-------------------------

SpriteGameObject::SpriteGameObject()
{
	this->m_spriteFile = "";
	this->m_Scale = sf::Vector2f(100,200);
	this->m_isUI = false;
}

SpriteGameObject::~SpriteGameObject()
{
	
}
//-----------CLASS FUNCTIONS------------------------------------


//////////////////////////////
// Initialise the Game Object
//////////////////////////////
void SpriteGameObject::Initialise()
{
	m_Sprite.Initialise(m_spriteFile.c_str(), m_Pos.x, m_Pos.y, m_Scale.x, m_Scale.y, m_isUI);
	m_CollisionRect = m_Sprite.getGlobalBounds();
}

//////////////////////////////
// Update the Game Object
//////////////////////////////
void SpriteGameObject::Update()
{

}

//////////////////////////////
// Get the Position of the Game
// Object and store it in 
// two Reference Parameters
//////////////////////////////
void SpriteGameObject::GetPosition(int& x, int& y)
{
	x = m_Sprite.getPosition().x;
	y = m_Sprite.getPosition().y;
}

//////////////////////////////
// Handle collision with
// Sprite object
//////////////////////////////
void SpriteGameObject::OnCollision(Collider2D* pCollider2D)
{
	GameStateManager* pGameStateManager = C_SysContext::Get<GameStateManager>();
	GameState*	pGameState = pGameStateManager->GetCurrentGameState();
	if (pGameState)
		pGameState->RemoveGameObject(this);
}

//////////////////////////////
// Set the Sprite of the
// Game Object
//////////////////////////////
void SpriteGameObject::setSprite(std::string psprite)
{
	this->m_spriteFile = "sprites/" + psprite;
}


//////////////////////////////
// Set the Position of the
// Game Object
//////////////////////////////
void SpriteGameObject::setPosition(sf::Vector2f ppos)
{
	this->m_Pos = ppos;
}

//////////////////////////////
// Set the Scale of the
// Game Object
//////////////////////////////
void SpriteGameObject::setScale(sf::Vector2f pscale)
{
	this->m_Scale = pscale;
}

//////////////////////////////
// Set if the GameObject is
// a UI element
//////////////////////////////
void SpriteGameObject::setUI()
{
	this->m_isUI = true;
}