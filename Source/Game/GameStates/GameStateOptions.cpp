#include "GameStateOptions.h"
#include <iostream>

//-----------CONSTRUCTOR / DESTRUCTOR-------------------------

//////////////////////////////
// Constructor for the Class
//////////////////////////////
GameStateOptions::GameStateOptions()
{
	pInputManager = C_SysContext::Get<InputManager>();
	pInputDevice = pInputManager->GetInputDevice();

	m_optionChosen = false;
	m_option = 0;
}

//////////////////////////////
// Destructor for the Class
//////////////////////////////
GameStateOptions::~GameStateOptions()
{
}

//-----------CLASS FUNCTIONS------------------------------------

//////////////////////////////
// Initialise the Game State
//////////////////////////////
void GameStateOptions::Initialise()
{
	// Create and Initialise HUD Objects
	m_HUDText = new TextGameObject();
	m_HUDText->setText("Options Menu\n\nWill have how to play\nand controls on this\nscreen plus options for\n\nCredits\nBack");
	m_HUDText->setPosition(sf::Vector2f(100, 100));
	m_HUDText->setCharSize(40);
	m_HUDText->setColour(sf::Color::Blue);
	m_HUDText->setUI();
	m_HUDText->Initialise();



	std::cout << std::endl;
	std::cout << "Options Menu" << std::endl;
	std::cout << "Option " << this->m_option+1 << ": " << this->m_options[this->m_option] << std::endl;
}

//////////////////////////////
// Update the Game State
//////////////////////////////
void GameStateOptions::Update()
{

	if (pInputDevice->GetButtonInput(E_DigitalInput_X).OnPressed()) {
		std::cout << "Space pressed" << std::endl;
		m_optionChosen = true;
	}

	if (pInputDevice->GetButtonInput(E_DigitalInput_DpadUp).OnPressed()) {
		DecreaseOption();
		std::cout << "Option " << this->m_option+1 << ": " << this->m_options[this->m_option] << std::endl;
	}
	if (pInputDevice->GetButtonInput(E_DigitalInput_DpadDown).OnPressed()) {
		IncreaseOption();
		std::cout << "Option " << this->m_option+1 << ": " << this->m_options[this->m_option] << std::endl;
	}


	GameState::Update();
}

//////////////////////////////
// Get Player Implementation (LATER USAGE)
//////////////////////////////
GameObject* GameStateOptions::GetPlayer()
{


	return NULL;
}

void GameStateOptions::IncreaseOption() {
	this->m_option++;
	if (this->m_option > 1)
		this->m_option = 0;
}

void GameStateOptions::DecreaseOption() {
	this->m_option--;
	if (this->m_option < 0)
		this->m_option = 1;
}