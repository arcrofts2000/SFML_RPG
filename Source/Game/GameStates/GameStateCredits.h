#pragma once
#include "../../Engine/System/GameState/GameState.h"
#include "../GameObjects/TextGameObject.h"
#include "../GameObjects/SpriteGameObject.h"
#include "../GameObjects/AnimatedSpriteGameObject.h"
#include "../GameObjects/Player.h"

#include "../../Engine/Input/InputManager.h"
#include "../../Engine/Input/InputDevice.h"
#include "../../Engine/System/Context/SysContextProvider.h"

#include <string>

class GameStateCredits :
	public GameState
{
public:
	GameStateCredits();
	~GameStateCredits();

public:
	virtual void					Initialise() override;
	virtual void					Update() override;
	virtual GameObject*				GetPlayer() override;

	bool							m_pressedEscape;

private:


protected:

	TextGameObject*					m_HUDText;

	InputDevice* pInputDevice;
	InputManager* pInputManager;
};

