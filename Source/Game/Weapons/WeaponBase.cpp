#include "WeaponBase.h"

#include "../../Engine/System/Context/SysContextProvider.h"

WeaponBase::WeaponBase()
{
	this->m_Ammo = 5;
	this->m_fireRate = 1;
	this->m_fireTimer = 1;
}

WeaponBase::~WeaponBase()
{

}
///////////////////////////
// Set the time until the 
// weapon can be fired again
///////////////////////////
void WeaponBase::Fire()
{
	if (m_fireRate > 0.0f)
	{
		m_fireTimer = 1.0f / m_fireRate;
	}
}

void WeaponBase::Update()
{
	m_AnimatedSprite.Animate();
	if (m_AnimatedSprite.AnimationFinished())
	{
		m_AnimatedSprite.SetCurrentAnimation(0);
		m_AnimatedSprite.Pause();
	}
	if (m_fireTimer >= 0.0f)
	{
		FrameTimer* pFrameTimer = C_SysContext::Get<FrameTimer>();
		m_fireTimer -= pFrameTimer->DeltaTime();
	}
}

bool WeaponBase::CanFire()
{
	if (m_Ammo > 0)
	{
		return m_fireTimer <= 0.0f;
	}
	return false;
}

void WeaponBase::SetPosition(int pposX, int pposY)
{
	m_AnimatedSprite.setPosition(sf::Vector2f(pposX, pposY));
}

void WeaponBase::SetScale(float pScaleX, float pScaleY)
{
	m_AnimatedSprite.setScale(sf::Vector2f(pScaleX, pScaleY));
}

void WeaponBase::SetRotation(float pangle)
{
	m_AnimatedSprite.setRotation(pangle);
}

sf::Vector2f WeaponBase::GetPosition()
{
	return m_AnimatedSprite.getPosition();
}