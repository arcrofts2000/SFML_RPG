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

class GameStateOptions :
	public GameState
{
public:
	GameStateOptions();
	~GameStateOptions();

public:
	virtual void					Initialise() override;
	virtual void					Update() override;
	virtual GameObject*				GetPlayer() override;


	bool							m_optionChosen;
	int								m_option;

private:


protected:

	TextGameObject*					m_HUDText;

	void IncreaseOption();
	void DecreaseOption();

	std::string m_options[2] = { "Credits","Back" };

	InputDevice* pInputDevice;
	InputManager* pInputManager;
};
