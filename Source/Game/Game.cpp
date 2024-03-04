#include "Game.h"

#include <windows.h>
#include <iostream>

#include "../Engine/Utils/Utils.h"
#include "../Engine/System/Context/SysContextProvider.h"
#include "../Engine/Input/InputDevice.h"

const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 768;

Game::Game()
	:m_bExit(false)
	,m_pInputDevice(NULL)
{
}

Game::~Game()
{
	SAFE_DELETE_PTR(m_pInputDevice);
}

void Game::Initialise()
{
	C_SysContext::Initialise();

	//setup the game data manager
	m_GameDataManager.Initialise();
	C_SysContext::Set<GameDataManager>(&m_GameDataManager);

	//setup the frame timer
	C_SysContext::Set<FrameTimer>(&m_FrameTimer);

	//setup the window manager
	C_SysContext::Set<WindowManager>(&m_WindowManager);

	//setup the asset manager
	C_SysContext::Set<AssetManager>(&m_AssetManager);

	//setup the renderer
	m_RenderManager.Initialise(WINDOW_WIDTH, WINDOW_HEIGHT, "Project 5110");
	C_SysContext::Set<RenderManager>(&m_RenderManager);

	//setup the audio manager
	C_SysContext::Set<AudioManager>(&m_AudioManager);

	//setup the input manager
	m_InputManager.Initialise();
	C_SysContext::Set<InputManager>(&m_InputManager);
	m_KBMInput = new KeyboardAndMouseInputDevice();
	m_InputManager.SetInputDevice(m_KBMInput);

	//setup the game state manager
	m_GameStateManager.Initialise();
	C_SysContext::Set<GameStateManager>(&m_GameStateManager);

	// Add game states
	m_StateTest = new GameStateTest();
	m_StateMainMenu = new GameStateMainMenu();
	m_StateWin = new GameStateWin();
	m_StateLose = new GameStateLose();
	m_StatePause = new GameStatePause();
	m_StateOptions = new GameStateOptions();
	m_StateCredits = new GameStateCredits();
	
	m_StateGameplay = new GameStateGameplay();

	// Set the default state (Switch parameter state variable to another to change default state)
	m_GameStateManager.QueueGameState(m_StateMainMenu); 
	
}

void Game::Run()
{
	m_FrameTimer.Initialise();

	while (!m_bExit)
	{
		//start of game frame
		m_FrameTimer.StartFrame();
		
		//update Player Input First
		m_InputManager.Update();

		//update the game state
		m_GameStateManager.Update();

		//Check the menu
		this->CheckMenu();
		
		//update the audio manager
		m_AudioManager.Update();

		//render
		m_RenderManager.Render();

		//end of game frame
		m_FrameTimer.EndFrame();	
	}
}

void Game::CheckMenu() {
	
	if (m_GameStateManager.GetCurrentGameState() == m_StateMainMenu) { // MAIN MENU
		if (m_StateMainMenu->m_optionChosen) {
			m_StateMainMenu->m_optionChosen = false;
			//m_GameStateManager.QueuePop();
			if (m_StateMainMenu->m_option == 0)
				m_GameStateManager.QueueGameState(m_StateTest); // Play
			else if (m_StateMainMenu->m_option == 1)
				m_GameStateManager.QueueGameState(m_StateOptions); // Options
			else
				m_GameStateManager.QueuePop(); // Quit
		}
	}
	else if (m_GameStateManager.GetCurrentGameState() == m_StateOptions) { // OPTIONS MENU
		if (m_StateOptions->m_optionChosen) {
			m_StateOptions->m_optionChosen = false;
			
			if (m_StateOptions->m_option == 0)
				m_GameStateManager.QueueGameState(m_StateCredits); // Credits
			else
				m_GameStateManager.QueuePop(); // Back

		}
	}
	else if (m_GameStateManager.GetCurrentGameState() == m_StateTest) { // GAMEPLAY TEST
		if (m_StateTest->m_isPaused) {
			m_GameStateManager.QueueGameState(m_StatePause);
		}
	}
	else if (m_GameStateManager.GetCurrentGameState() == m_StatePause) { // PAUSED MENU
		if (m_StatePause->m_isUnPaused) {
			m_StatePause->m_isUnPaused = false;
			m_StateTest->m_isPaused = false;
			m_GameStateManager.QueuePop();
		}
	}
	else if (m_GameStateManager.GetCurrentGameState() == m_StateCredits) { // CREDITS
		if (m_StateCredits->m_pressedEscape) {
			m_StateCredits->m_pressedEscape = false;
			m_GameStateManager.QueuePop();
		}
	}
}