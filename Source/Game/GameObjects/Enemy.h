#pragma once
#include "AnimatedSpriteGameObject.h"
#include "../GameData/GameDataManager.h"
#include "../../Engine/Input/InputDevice.h"
#include "../GameData/SpritesheetDef.h"
#include "Player.h"
#include "../Weapons/WeaponsHeaders.h"
class Enemy :
	public AnimatedSpriteGameObject
{
public:
	Enemy();
	~Enemy();
	virtual void Initialise() override;
	virtual void Update() override;
	virtual void GetPosition(int& x, int& y) override;

	void SetEnemy(std::string pSpriteSheetDef, int phealth, int pscore, bool AIOn); //sets the enemy Sprite
	//void setDetectionAreas(sf::Vector2f psight, sf::Vector2f pShortRange); //sets the sight and detection areas around the enemy
	void SetRotation( float angle);
	void SetScale(float ScaleX, float ScaleY);
	void SetPosition(int x, int y);

	void Shoot();
	void Melee();
	void SpottedPlayer(Player pPlayer);
	void Move();
	
	int getHealth();
	int getScore();
	sf::Vector2f getCurrentPos();

private:
	enum En_Animation_State
	{
		En_Animation_Idle,
		En_Animation_Walking,
		En_Animation_Death,
		En_Animation_Melee,
		En_Animation_Shoot,
		En_Animation_Hit,
		En_Animation_Flying
	};
	enum En_Enemy_Weapon
	{
		En_BlitzWeapon
	};
protected:
	AnimatedSprite m_AnimatedSprite;
	WeaponBase* m_EnemyWeapon;
	En_Enemy_Weapon* m_WeaponType;
	GameDataManager* pGameDataManager;
	SpritesheetDef* pSpriteSheetDef;
	
	int animationID;
	int m_FPS;
	bool m_loop;
	
	bool detectsPlayer;

	bool m_isIdle;
	bool m_isWalking;
	bool m_isDead;
	bool m_isMeleeing;
	bool m_isDashing;
	bool m_isFlying;
	
	sf::Vector2f m_sight;
		sf::Vector2f m_shortRange;;

	std::string spriteSheetDef;
	std::string m_SpriteName;
	
	sf::Vector2f dirUp = sf::Vector2f(0.0f, 1.0f);
	sf::Vector2f dirDown = sf::Vector2f(0.0f, -1.0);
	sf::Vector2f dirRight = sf::Vector2f(1.0f, 0.0f);
	sf::Vector2f dirLeft = sf::Vector2f(-1.0f, 0.0f);
	sf::Vector2f m_velocity;
	sf::Vector2f tmovement;
	
	int m_health;
	int m_Score;
	int m_EOffset_X;
	int m_EOffset_Y;
};

