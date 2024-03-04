#include "SecondaryWeapon.h"
#include "../../Engine/System/GameState/GameState.h"
#include "../../Engine/System/GameState/GameStateManager.h"
#include "../GameData/GameDataManager.h"
#include "../../Engine/System/Context/SysContextProvider.h"
#include "../GameObjects/Bullet.h"
#include <iostream>

SecondaryWeapon::SecondaryWeapon()
	:m_MaxAmmo(20)
{

}
SecondaryWeapon::~SecondaryWeapon()
{

}

void SecondaryWeapon::Initialise()
{
	GameDataManager* pGameDataManager = C_SysContext::Get<GameDataManager>();
	sprBlitz = pGameDataManager->GetSpritesheetDef("sprites/bullets/spr_bullet.xml");

	m_AnimatedSprite.AddAnimationFromSpriteSheetDef(0, sprBlitz, "spr_bullet", 10, false);
	m_AnimatedSprite.SetCurrentAnimation(0);
	m_AnimatedSprite.Pause();
	m_AnimatedSprite.setColor(sf::Color::Red);
	m_Ammo = 100;
}

void SecondaryWeapon::Update()
{
	WeaponBase::Update();
}

void SecondaryWeapon::Fire()
{
	if (!CanFire())
		return;
	for (int i = 0; i < 1; i++)
	{
		WeaponBase::Fire();

		std::cout << "Weapon Fired" << std::endl;

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
	}

	m_Ammo--;

	m_AnimatedSprite.Play();
}

void SecondaryWeapon::Reload()
{
	m_Ammo = m_MaxAmmo;
}
