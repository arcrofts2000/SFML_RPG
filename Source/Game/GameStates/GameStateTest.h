#pragma once
#include "../../Engine/System/GameState/GameState.h"
#include "../GameObjects/TextGameObject.h"
#include "../GameObjects/SpriteGameObject.h"
#include "../GameObjects/AnimatedSpriteGameObject.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Camera.h"
#include "../GameObjects/Enemy.h"

#include "../../Engine/Input/InputManager.h"
#include "../../Engine/Input/InputDevice.h"
#include "../../Engine/System/Context/SysContextProvider.h"

#include <iostream>

class GameStateTest :
	public GameState
{
public:
									GameStateTest();
									~GameStateTest();

public:
	virtual void					Initialise() override;
	virtual void					Update() override;
	virtual GameObject*				GetPlayer() override;

	bool							m_isPaused;

private:


protected:
	TextGameObject*					m_Text;
	SpriteGameObject*				m_Sprite;
	AnimatedSpriteGameObject*		m_AnimatedSprite;
	Enemy*						    m_Enemy;
	Player*							m_Player;
	Camera*							m_Camera;


	InputDevice* pInputDevice;
	InputManager* pInputManager;




	SpriteGameObject*				m_HUDSpriteTest;
	TextGameObject*					m_HUDTextTest;
};

