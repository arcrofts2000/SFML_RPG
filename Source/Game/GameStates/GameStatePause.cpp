#include "GameStatePause.h"

//-----------CONSTRUCTOR / DESTRUCTOR-------------------------

//////////////////////////////
// Constructor for the Class
//////////////////////////////
GameStatePause::GameStatePause()
{
	pInputManager = C_SysContext::Get<InputManager>();
	pInputDevice = pInputManager->GetInputDevice();
	m_isUnPaused = false;
}

//////////////////////////////
// Destructor for the Class
//////////////////////////////
GameStatePause::~GameStatePause()
{
}

//-----------CLASS FUNCTIONS------------------------------------

//////////////////////////////
// Initialise the Game State
//////////////////////////////
void GameStatePause::Initialise()
{

	// Create and Initialise HUD Objects
	m_HUDText = new TextGameObject();
	m_HUDText->setText("Pause");
	m_HUDText->setPosition(sf::Vector2f(400, 400));
	m_HUDText->setCharSize(40);
	m_HUDText->setColour(sf::Color::Blue);
	m_HUDText->setUI();
	m_HUDText->Initialise();


}

//////////////////////////////
// Update the Game State
//////////////////////////////
void GameStatePause::Update()
{
	if (pInputDevice->GetButtonInput(E_DigitalInput_A).OnPressed()) {
		this->m_isUnPaused = true;
	}

	GameState::Update();
}

//////////////////////////////
// Get Player Implementation (LATER USAGE)
//////////////////////////////
GameObject* GameStatePause::GetPlayer()
{


	return NULL;
}
