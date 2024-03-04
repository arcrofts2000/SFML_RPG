#pragma once
#include "../GameObjects/AnimatedSpriteGameObject.h"
#include "../../Engine/Renderer/FrameTimer.h"


class WeaponBase
{
public:
						WeaponBase();
	virtual 			~WeaponBase();

public:
	virtual void		Initialise() = 0;
	virtual void		Fire();
	virtual void		Reload() = 0;
	virtual void		Update();

public:
	bool				CanFire();
	void				SetPosition(int pposX, int pposY);
	void				SetScale(float pScaleX, float pScaleY);
	void				SetRotation(float pangle);

	sf::Vector2f		GetPosition();

	int					m_Ammo;

	//Member Variables
protected:
	
	float				m_fireRate;
	float				m_fireTimer;
	AnimatedSprite		m_AnimatedSprite;
};

