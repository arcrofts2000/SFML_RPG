#include "BlitzWeapon.h"
#include "../../Engine/System/GameState/GameState.h"
#include "../../Engine/System/GameState/GameStateManager.h"
#include "../GameData/GameDataManager.h"
#include "../../Engine/System/Context/SysContextProvider.h"
#include "../GameObjects/Bullet.h"
BlitzWeapon::BlitzWeapon()
	:m_MaxAmmo(7)
{

}
BlitzWeapon::~BlitzWeapon()
{

}

void BlitzWeapon::Initialise()
{
	GameDataManager* pGameDataManager = C_SysContext::Get<GameDataManager>();
	sprBlitz = pGameDataManager->GetSpritesheetDef("sprites/weapons/spr_blitz.xml");

	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(0, sprBlitz, "spr_blitz", 10, false);
	m_AnimatedSprite.SetCurrentAnimation(0);
	m_AnimatedSprite.Pause();
	m_Ammo = 7;
}

void BlitzWeapon::Update()
{
	WeaponBase::Update();
}

void BlitzWeapon::Fire()
{
	if (!CanFire())
		return;
	WeaponBase::Fire();

	// Generate Bullet
	Bullet* bullet = new Bullet();
	bullet->Initialise();

	// Create a bullet spawn offset
	sf::Vector2f bulletSpawnOffset(m_BarrelOffsetX, m_BarrelOffsetY);

	// Rotate it to face the correct direction
	sf::Transform transform;
	transform.rotate(m_AnimatedSprite.getRotation());
	transform.scale(m_AnimatedSprite.getScale());
	bulletSpawnOffset = transform.transformPoint(bulletSpawnOffset);

	bullet->SetPosition(m_AnimatedSprite.getPosition().x + bulletSpawnOffset.x, m_AnimatedSprite.getPosition().y + bulletSpawnOffset.y);
	bullet->setRotation(m_AnimatedSprite.getRotation());

	bullet->setScale(m_AnimatedSprite.getScale().x, m_AnimatedSprite.getScale().y);

	GameStateManager* pGameStateManager = C_SysContext::Get<GameStateManager>();
	GameState* pGameState = pGameStateManager->GetCurrentGameState();

	if (pGameState)
		pGameState->AddGameObject(bullet);

	m_Ammo--;

	m_AnimatedSprite.Play();
}

void BlitzWeapon::Reload()
{
	m_Ammo = m_MaxAmmo;
}
