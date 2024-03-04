#include "Enemy.h"
#include "../../Engine/System/Context/SysContextProvider.h"
Enemy::Enemy()
	:m_loop(true)
	, m_FPS(12)
{
	pInputManager = C_SysContext::Get<InputManager>();
	pInputDevice = pInputManager->GetInputDevice(); 
	
	this->m_isIdle = true;
	this->m_isFlying = false;
	this->m_isDashing = false;
	this->m_isDead = false;
	this->m_isMeleeing = false;
	this->m_isWalking = false;

	this->m_EOffset_X = 10;
	this->m_EOffset_Y = 10;
}

Enemy::~Enemy()
{
	delete(m_EnemyWeapon);
}

void Enemy::Initialise()
{
	m_EnemyWeapon = new BlitzWeapon();
	m_EnemyWeapon->Initialise();
	m_EnemyWeapon->SetScale(1, 1);

	pGameDataManager = C_SysContext::Get<GameDataManager>();
 	pSpriteSheetDef = pGameDataManager->GetSpritesheetDef(m_SpritesheetFile.c_str()); 

	m_AnimatedSprite.setScale(sf::Vector2f(1, 1));
	m_AnimatedSprite.setPosition(sf::Vector2f(200, 200));

	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(En_Animation_Idle, pSpriteSheetDef, (m_SpriteName + "_idle").c_str(), m_FPS, m_Loop);
	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(En_Animation_Walking, pSpriteSheetDef, (m_SpriteName + "_walking").c_str(), m_FPS, m_Loop);
	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(En_Animation_Hit, pSpriteSheetDef, (m_SpriteName + "_hit").c_str(), m_FPS, m_Loop);
	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(En_Animation_Melee, pSpriteSheetDef, (m_SpriteName + "_melee").c_str(), m_FPS, false);
	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(En_Animation_Shoot, pSpriteSheetDef, (m_SpriteName + "_shoot").c_str(), m_FPS, false);
	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(En_Animation_Flying, pSpriteSheetDef, (m_SpriteName + "_Flying").c_str(), m_FPS, m_Loop);

	m_AnimatedSprite.SetCurrentAnimation(En_Animation_Idle);

}

void Enemy::Update()
{
	tmovement = sf::Vector2f(0, 0);
	m_EnemyWeapon->SetPosition(m_AnimatedSprite.getPosition().x + m_EOffset_X *
		m_AnimatedSprite.getScale().x, m_AnimatedSprite.getPosition().y + m_EOffset_Y *
		m_AnimatedSprite.getScale().y);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) { tmovement.y -= 2.0; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) { tmovement.y += 2.0; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) { tmovement.x -= 2.0; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) { tmovement.x += 2.0; }
	m_AnimatedSprite.move(tmovement);
	
}

void Enemy::GetPosition(int& x, int& y)
{
	x = this->m_AnimatedSprite.getPosition().x;
	y = this->m_AnimatedSprite.getPosition().y;
}

void Enemy::SetEnemy(std::string pSpriteSheetDef, int pHealth, int pScore, bool AIOn)
{
	this->m_SpritesheetFile = "sprites/characters/"+ pSpriteSheetDef + ".xml";
    this->m_SpriteName = pSpriteSheetDef;
	this->m_health = pHealth;
	this->m_Score = pScore;
}
///////////////////
// Sets the local detection
// areas for the Enemy which allow
// them to react to the player
//////////////////
/*void Enemy::setDetectionAreas(sf::Vector2f psight, sf::Vector2f pShortRange)
{
	
}*/

////////////////////
// For when the Enemy
// decides to use melee attack
///////////////////
void Enemy::Melee()
{
	m_AnimatedSprite.SetCurrentAnimation(En_Animation_Melee);

}

void Enemy::Shoot()
{
	m_EnemyWeapon->Fire();

}
void Enemy::Move()
{
	
}

int Enemy::getScore()
{
	return m_Score;
}

int Enemy::getHealth()
{
	return m_health;
}







