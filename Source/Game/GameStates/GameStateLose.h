#pragma once
#include "../../Engine/System/GameState/GameState.h"
#include "../GameObjects/TextGameObject.h"
#include "../GameObjects/SpriteGameObject.h"
#include "../GameObjects/AnimatedSpriteGameObject.h"
#include "../GameObjects/Player.h"

class GameStateLose :
	public GameState
{
public:
									GameStateLose();
									~GameStateLose();

public:
	virtual void					Initialise() override;
	virtual void					Update() override;
	virtual GameObject*				GetPlayer() override;

private:


protected:

	TextGameObject*					m_HUDText;
};

