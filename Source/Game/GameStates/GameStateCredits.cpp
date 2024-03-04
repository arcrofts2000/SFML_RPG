#include "GameStateCredits.h"
#include <iostream>

//-----------CONSTRUCTOR / DESTRUCTOR-------------------------

//////////////////////////////
// Constructor for the Class
//////////////////////////////
GameStateCredits::GameStateCredits()
{
	pInputManager = C_SysContext::Get<InputManager>();
	pInputDevice = pInputManager->GetInputDevice();

	m_pressedEscape = false;
}

//////////////////////////////
// Destructor for the Class
//////////////////////////////
GameStateCredits::~GameStateCredits()
{
}

//-----------CLASS FUNCTIONS------------------------------------

//////////////////////////////
// Initialise the Game State
//////////////////////////////
void GameStateCredits::Initialise()
{
	// Create and Initialise HUD Objects
	m_HUDText = new TextGameObject();
	m_HUDText->setText("Credits\n\nWill have the names of \ngroup members");
	m_HUDText->setPosition(sf::Vector2f(100, 100));
	m_HUDText->setCharSize(40);
	m_HUDText->setColour(sf::Color::Blue);
	m_HUDText->setUI();
	m_HUDText->Initialise();



	std::cout << std::endl;
	std::cout << "Credits " << std::endl;
	std::cout << "Press escape to go back\n" << std::endl;
}

//////////////////////////////
// Update the Game State
//////////////////////////////
void GameStateCredits::Update()
{

	if (pInputDevice->GetButtonInput(E_DigitalInput_A).OnPressed()) {
		this->m_pressedEscape = true;
	}


	GameState::Update();
}

//////////////////////////////
// Get Player Implementation (LATER USAGE)
//////////////////////////////
GameObject* GameStateCredits::GetPlayer()
{


	return NULL;
}
