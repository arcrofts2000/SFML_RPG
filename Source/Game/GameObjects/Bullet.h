#pragma once
#include "../../Engine/Core/GameObject.h"
#include "../../Engine/Physics/BoxCollider2D.h";
#include "AnimatedSpriteGameObject.h";
#include "../GameData/SpritesheetDef.h";
class Bullet :
	public GameObject, 
	public BoxCollider2D
{
public:
										Bullet();
										~Bullet();

public:
	virtual void						Initialise()									override;
	virtual void						Update()										override;
	virtual void						GetPosition(int& x, int& y)						override;
	virtual void						OnCollision(Collider2D* pCollider2D)			override;

	void								SetPosition(int x, int y);
	void								setRotation(float angle);
	void								setScale(float ScaleX, float ScaleY);

	void								setBullet(std::string pSpriteSheet);
private:

	float								m_velocity;
	float								m_Lifetime;

	std::string							m_SpriteSheetDef;
	std::string							SpriteName;
	
	AnimatedSprite						m_AnimatedSprite;
	SpritesheetDef*						spr_bullet;
};

