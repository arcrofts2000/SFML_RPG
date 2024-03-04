#pragma once

#include "AnimatedSpriteGameObject.h"
#include "../GameData/GameDataManager.h"
#include "../../Engine/Input/InputManager.h"
#include "../../Engine/Input/InputDevice.h"
#include "../Weapons/BlitzWeapon.h"
#include "../Weapons/SecondaryWeapon.h"

class Player :  public AnimatedSpriteGameObject
{
public:
									Player();
									~Player();

public:
	virtual void					Initialise()						override;
	virtual void					Update()							override;
	virtual void					GetPosition(int& x, int& y)			override;
	sf::Vector2f					GetWorldPos();

	void							SetPlayer(std::string pSpritesheet);

	int								GetAmmo();
	int								GetMaxHealth();
	int								GetCurrentHealth();

private:
	void							FollowMouse();

	AnimatedSprite					m_AnimatedSprite;
	WeaponBase*						m_pWeapon;

	void							SetWeapon(std::string pWeapon);

	float							m_WeaponOffsetX = 10.0f;
	float							m_WeaponOffsetY = 25.0f;

	GameDataManager*				pGameDataManager;
	SpritesheetDef*					pSpritesheetDef;
	
	// ---------- Enumerator ----------
	enum E_AnimationState
	{
		E_AnimationState_Idle,
		E_AnimationState_Sprint,
		E_AnimationState_Walk,
		E_AnimationState_Dash,
		E_AnimationState_Death,
		E_AnimationState_Hit,
		E_AnimationState_Holo,
		E_AnimationState_Melee,
		E_AnimationState_Teleport_In,
		E_AnimationState_Teleport_Out
	};

	std::string						m_SpritesheetDef;
	std::string						m_SpriteName;
	int								m_FPS;
	bool							m_Loop;
	
	bool							m_isIdle;
	bool							m_isSprinting;
	bool							m_isWalking;
	bool							m_isDashing;
	bool							m_isDead;
	bool							m_isHurt;
	bool							m_isHolo;
	bool							m_isMelee;
	bool							m_isTeleporting;

	sf::Vector2f tmove;

	int m_Health;
	int m_MaxHealth;
	
	int m_Speed;
	int m_AbsoluteSpeed;

	bool m_isPlayerDead;
};

