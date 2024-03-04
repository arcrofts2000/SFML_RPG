#include "Bullet.h"
#include "../../Engine/Renderer/FrameTimer.h"
#include "../../Engine/System/Context/SysContextProvider.h"
#include "../GameData/GameDataManager.h"
#include "../../Engine/System/GameState/GameState.h"
#include "../../Engine/System/GameState/GameStateManager.h"
#include <iostream>

Bullet::Bullet()
{
	this->m_SpriteSheetDef = "sprites/bullets/spr_bullet.xml";
}

Bullet::~Bullet()
{

}

void Bullet::Initialise()
{
	GameDataManager* pGameDataManager = C_SysContext::Get<GameDataManager>();
	spr_bullet = pGameDataManager->GetSpritesheetDef(m_SpriteSheetDef.c_str());

	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(1, spr_bullet, "spr_bullet", 24, false);
	m_AnimatedSprite.SetCurrentAnimation(1);
	this->m_velocity = 1500.0f;
	this->m_Lifetime = 1.0f;
	this->m_CollisionRect = m_AnimatedSprite.getGlobalBounds();
	std::cout << "Bullet Created \n";
}

void Bullet::Update()
{
	m_AnimatedSprite.Animate();

	// Don't move until we are past the muzzle flash
	if (m_AnimatedSprite.GetCurrentFrame() == 0)
		return;

	// Grab the Frame Timer
	FrameTimer* pFrameTimer = C_SysContext::Get<FrameTimer>();

	// Create a forward vector
	sf::Vector2f movement(1.0f, 0.0f);

	// Modify magnitude based on Velocity
	movement *= (m_velocity * pFrameTimer->DeltaTime());
	
	// Rotate and Scale it to face the correct direction
	sf::Transform transform;
	transform.rotate(m_AnimatedSprite.getRotation());
	transform.scale(m_AnimatedSprite.getScale());
	movement = transform.transformPoint(movement);

	// Transform the bullet position
	m_AnimatedSprite.move(movement);
	
	m_Lifetime -= pFrameTimer->DeltaTime();
	if (m_Lifetime <= 0.0f)
	{
		GameStateManager* pGameStateManager = C_SysContext::Get<GameStateManager>();
		GameState* pGameState = pGameStateManager->GetCurrentGameState();
		// Remove from Game State
		if(pGameState)
			pGameState->RemoveGameObject(this);
	}

	m_CollisionRect = m_AnimatedSprite.getGlobalBounds();
	
	//std::cout << "Pos X: " << m_AnimatedSprite.getPosition().x << "\n Pos Y: " << m_AnimatedSprite.getPosition().y << std::endl;

}

void Bullet::OnCollision(Collider2D* pCollider2D)
{
	GameStateManager* pGameStateManager = C_SysContext::Get<GameStateManager>();
	GameState* pCurrentGameState = pGameStateManager->GetCurrentGameState();

	pCurrentGameState->RemoveGameObject(this);
}

void Bullet::GetPosition(int& x, int& y)
{
	x = m_AnimatedSprite.getPosition().x;
	y = m_AnimatedSprite.getPosition().y;
}

void Bullet::SetPosition(int x, int y)
{
	m_AnimatedSprite.setPosition(x, y);
}

//////////////////////////
// Set the rotation of
// the bullet sprite
//////////////////////////
void Bullet::setRotation(float angle)
{
	m_AnimatedSprite.setRotation(angle);
}
//////////////////////////
// Set the scale of the
// Bullet sprite
//////////////////////////
void Bullet::setScale(float ScaleX, float ScaleY)
{
	m_AnimatedSprite.setScale(sf::Vector2f(ScaleX, ScaleY));
}

///////////////////////////
//Sets the sprite sheet
//for the bullet allow for
//multiple different bullets
///////////////////////////
void Bullet::setBullet(std::string pSpriteSheet)
{
	this->m_SpriteSheetDef = "sprites/bullets/" + pSpriteSheet + ".xml";
	this->SpriteName = pSpriteSheet;
}
