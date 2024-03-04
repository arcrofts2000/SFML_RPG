#include "Player.h"
#include <iostream>

#include "../../Engine/System/Context/SysContextProvider.h"
#include "../../Engine/Renderer/WindowManager.h"

//-----------CONSTRUCTOR / DESTRUCTOR-------------------------

//////////////////////////////
// Constructor for the Class
//////////////////////////////
Player::Player()
{
	pInputManager = C_SysContext::Get<InputManager>();
	pInputDevice = pInputManager->GetInputDevice();
	
	m_MaxHealth = 3;
	m_Health = m_MaxHealth;
	this->m_isPlayerDead = false;
	this->m_Speed = 3;

	this->m_SpriteName = "spr_biu";
	this->m_SpritesheetDef = "sprites/characters/spr_biu.xml";
	this->m_FPS = 13;
	this->m_Loop = true;


	this->m_isIdle = true;
	this->m_isSprinting = false;
	this->m_isWalking = false;
	this->m_isDashing = false;
	this->m_isDead = false;
	this->m_isHurt = false;
	this->m_isHolo = false;
	this->m_isMelee = false;
	this->m_isTeleporting = false;
}

//////////////////////////////
// Destructor for the Class
//////////////////////////////
Player::~Player()
{
	delete(m_pWeapon);
}

//-----------CLASS FUNCTIONS------------------------------------

//////////////////////////////
// Initialise the Game Object
//////////////////////////////
void Player::Initialise()
{
	// ---------- Setting the Weapon ----------
	m_pWeapon = new BlitzWeapon();
	m_pWeapon->Initialise();
	m_pWeapon->SetScale(1, 1);

	// ---------- Animation Sprite Sheet ----------
	pGameDataManager = C_SysContext::Get<GameDataManager>();
	pSpritesheetDef = pGameDataManager->GetSpritesheetDef(m_SpritesheetDef.c_str());

	// ---------- Scale and Position ----------
	m_AnimatedSprite.setScale(sf::Vector2f(1,1));
	m_AnimatedSprite.setPosition(sf::Vector2f(300,300));

	// ---------- Animation State ----------
	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(E_AnimationState_Idle, pSpritesheetDef, (m_SpriteName+"_idle").c_str(), m_FPS, m_Loop);
	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(E_AnimationState_Sprint, pSpritesheetDef, (m_SpriteName+"_sprint").c_str(), m_FPS, m_Loop);
	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(E_AnimationState_Walk, pSpritesheetDef, (m_SpriteName + "_walk").c_str(), m_FPS, m_Loop);
	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(E_AnimationState_Dash, pSpritesheetDef, (m_SpriteName + "_dash").c_str(), m_FPS, m_Loop);
	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(E_AnimationState_Death, pSpritesheetDef, (m_SpriteName + "_death").c_str(), m_FPS, false);
	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(E_AnimationState_Hit, pSpritesheetDef, (m_SpriteName + "_hit").c_str(), m_FPS, m_Loop);
	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(E_AnimationState_Holo, pSpritesheetDef, (m_SpriteName + "_holo").c_str(), m_FPS, m_Loop);
	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(E_AnimationState_Melee, pSpritesheetDef, (m_SpriteName + "_melee").c_str(), m_FPS, false);
	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(E_AnimationState_Teleport_In, pSpritesheetDef, (m_SpriteName + "_teleport_in").c_str(), m_FPS, m_Loop);
	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(E_AnimationState_Teleport_Out, pSpritesheetDef, (m_SpriteName + "_teleport_out").c_str(), m_FPS, m_Loop);
	
	// ---------- Default Animation ----------
	m_AnimatedSprite.SetCurrentAnimation(E_AnimationState_Idle);
}

//////////////////////////////
// Update the Game Object
//////////////////////////////
void Player::Update()
{
	int x = this->GetWorldPos().x, y = this->GetWorldPos().y;
	tmove = sf::Vector2f(0, 0);

	//std::cout << this->m_Health << " : " << this->m_isPlayerDead<< std::endl;
	
	m_AnimatedSprite.Animate();
	
	if (this->m_Health <= 0)
	{
		this->m_isPlayerDead = true;
		delete this->m_pWeapon;
		this->m_pWeapon = nullptr;
	}

	if (this->m_isPlayerDead && m_AnimatedSprite.GetCurrentAnimation() != E_AnimationState_Death)
	{
		m_AnimatedSprite.SetCurrentAnimation(E_AnimationState_Death);
	}

	// ---------- Weapons and Melee ----------
	if (m_pWeapon)
	{
		m_pWeapon->SetPosition(m_AnimatedSprite.getPosition().x + m_WeaponOffsetX *
			m_AnimatedSprite.getScale().x, m_AnimatedSprite.getPosition().y + m_WeaponOffsetY *
			m_AnimatedSprite.getScale().y);
		m_pWeapon->Update();
	}
	
	if (!this->m_isPlayerDead)
	{
		if (pInputDevice->GetButtonInput(E_DigitalInput_X).OnPressed() && !this->m_isPlayerDead && m_AnimatedSprite.GetCurrentAnimation() != E_AnimationState_Melee) 
		{	
			m_AnimatedSprite.SetCurrentAnimation(E_AnimationState_Melee);
			SetWeapon("Second");
			std::cout << "Secondary Weapon" << std::endl;
		}
		if (m_AnimatedSprite.AnimationFinished() && m_AnimatedSprite.GetCurrentAnimation() == E_AnimationState_Melee) { m_AnimatedSprite.SetCurrentAnimation(E_AnimationState_Idle); }

		this->FollowMouse();

		if (m_AnimatedSprite.GetCurrentAnimation() != E_AnimationState_Melee)
		{
			// ---------- Player Movement and Control System ----------
			// Setting the Movement + Speed, providing the Player is not in Melee
			if (pInputDevice->GetButtonInput(E_DigitalInput_DpadDown).IsDown()) { tmove.y += m_Speed; }
			if (pInputDevice->GetButtonInput(E_DigitalInput_DpadUp).IsDown()) { tmove.y -= m_Speed; }
			if (pInputDevice->GetButtonInput(E_DigitalInput_DpadLeft).IsDown()) { tmove.x -= m_Speed; }
			if (pInputDevice->GetButtonInput(E_DigitalInput_DpadRight).IsDown()) { tmove.x += m_Speed;  }
			if (pInputDevice->GetButtonInput(E_DigitalInput_B).IsDown()) { tmove.x *= 2; tmove.y *= 2; }

			m_AnimatedSprite.move(tmove);

			// Setting the Animation to either Sprint or Walk, providing the animation is not in Melee
			if (this->m_AbsoluteSpeed == m_Speed && m_AnimatedSprite.GetCurrentAnimation() != E_AnimationState_Walk) { m_AnimatedSprite.SetCurrentAnimation(E_AnimationState_Walk); }
			else if (this->m_AbsoluteSpeed > m_Speed && m_AnimatedSprite.GetCurrentAnimation() != E_AnimationState_Sprint) { m_AnimatedSprite.SetCurrentAnimation(E_AnimationState_Sprint); }

			if (pInputDevice->GetButtonInput(E_DigitalInput_RightShoulder).OnPressed()) { m_pWeapon->Fire(); }
			if (pInputDevice->GetButtonInput(E_DigitalInput_Y).OnPressed()) { m_pWeapon->Reload(); }

			// Setting the Animation to Idle
			if (this->m_AbsoluteSpeed == 0 && m_AnimatedSprite.GetCurrentAnimation() != E_AnimationState_Idle)
				m_AnimatedSprite.SetCurrentAnimation(E_AnimationState_Idle);
		}
	}

	m_AbsoluteSpeed = abs(tmove.x) + abs(tmove.y);
	
	
}

//////////////////////////////
// Get the Position of the Game
// Object and store it in 
// two Reference Parameters
//////////////////////////////
void Player::GetPosition(int & x, int & y)
{
	x = m_AnimatedSprite.getPosition().x;
	y = m_AnimatedSprite.getPosition().y;
}

//////////////////////////////
// Set the Spritesheet File as 
// this will allow multiple characters
// Only requires file name.
//////////////////////////////
void Player::SetPlayer(std::string pSpritesheet)
{
	this->m_SpritesheetDef = "sprites/characters/" + pSpritesheet + ".xml";
	this->m_SpriteName = pSpritesheet;
}

sf::Vector2f Player::GetWorldPos()
{
	return m_AnimatedSprite.getPosition();
}

int Player::GetAmmo()
{
	return this->m_pWeapon->m_Ammo;
}

int Player::GetCurrentHealth()
{
	return m_Health;
}

int Player::GetMaxHealth()
{
	return m_MaxHealth;
}

void Player::FollowMouse()
{
	WindowManager* pWindowManager = C_SysContext::Get<WindowManager>();

	sf::Vector2i mousePos = sf::Mouse::getPosition();
	sf::Vector2f screenPos = pWindowManager->GetWindow()->mapPixelToCoords(mousePos);

	float PI = 3.141592f;
	float angle = atan2(screenPos.y - this->m_pWeapon->GetPosition().y, screenPos.x - this->m_pWeapon->GetPosition().x);
	angle = angle * (180 / PI);

	if (angle < 0)
		angle = 360 - (-angle);

	this->m_pWeapon->SetRotation(angle);

	if (angle > 80)
	{
		this->m_AnimatedSprite.setScale(-1, 1);
		this->m_pWeapon->SetScale(1, -1);
	}
	else if (angle < 170)
	{
		this->m_AnimatedSprite.setScale(1, 1);
		this->m_pWeapon->SetScale(1, 1);
	}
}

void Player::SetWeapon(std::string pWeapon)
{
	if (pWeapon == "First")
		m_pWeapon = new BlitzWeapon();
	if (pWeapon == "Second")
		m_pWeapon = new SecondaryWeapon();
	m_pWeapon->Initialise();
	m_pWeapon->SetScale(1, 1);
}

