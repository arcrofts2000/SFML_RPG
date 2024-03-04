#ifndef _GAME_H
#define _GAME_H

#include "../Engine/Renderer/RenderManager.h"
#include "../Engine/System/Assets/AssetManager.h"
#include "../Engine/Renderer/FrameTimer.h"
#include "../Engine/System/GameState/GameStateManager.h"
#include "../Engine/Audio/AudioManager.h"
#include "../Engine/Input/InputManager.h"
#include "../Engine/Renderer/WindowManager.h"
#include "Input/KeyboardAndMouseInputDevice.h"
#include "GameData/GameDataManager.h"
#include "GameStates/GameStateTest.h"
#include "GameStates/GameStateMainMenu.h"
#include "GameStates/GameStateWin.h"
#include "GameStates/GameStateLose.h"
#include "GameStates/GameStatePause.h"
#include "GameStates/GameStateGameplay.h"
#include "GameStates/GameStateOptions.h"
#include "GameStates/GameStateCredits.h"

class InputDevice;

class Game
{
public:

	Game();
	~Game();

	void Initialise();
	void Run();

	void CheckMenu();

private:

	bool m_bExit;

	GameDataManager m_GameDataManager;
	WindowManager m_WindowManager;	
	FrameTimer m_FrameTimer;
	RenderManager m_RenderManager;
	AssetManager m_AssetManager;

	GameStateManager m_GameStateManager;
	GameStateTest* m_StateTest;
	GameStateMainMenu* m_StateMainMenu;
	GameStateWin* m_StateWin;
	GameStateLose* m_StateLose;
	GameStatePause* m_StatePause;
	GameStateOptions* m_StateOptions;
	GameStateCredits* m_StateCredits;

	GameStateGameplay* m_StateGameplay;

	AudioManager m_AudioManager;
	InputManager m_InputManager;
	InputDevice* m_pInputDevice;
	KeyboardAndMouseInputDevice* m_KBMInput;
};

#endif
