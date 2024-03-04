#pragma once
#include "WeaponBase.h"
#include "../GameData/SpritesheetDef.h"
class BlitzWeapon :
	public WeaponBase
{
public:
								BlitzWeapon();
								~BlitzWeapon();

public:
	virtual void				Initialise()				override;
	virtual void				Fire();
	virtual void				Reload()					override;
	virtual void				Update();

private:
	float						m_BarrelOffsetX;
	float						m_BarrelOffsetY;
	const int					m_MaxAmmo;
	SpritesheetDef*				sprBlitz;

	
};

