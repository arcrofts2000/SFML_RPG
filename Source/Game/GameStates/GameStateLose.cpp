#include "GameStateLose.h"

//-----------CONSTRUCTOR / DESTRUCTOR-------------------------

//////////////////////////////
// Constructor for the Class
//////////////////////////////
GameStateLose::GameStateLose()
{
}

//////////////////////////////
// Destructor for the Class
//////////////////////////////
GameStateLose::~GameStateLose()
{
}

//-----------CLASS FUNCTIONS------------------------------------

//////////////////////////////
// Initialise the Game State
//////////////////////////////
void GameStateLose::Initialise()
{

	// Create and Initialise HUD Objects
	m_HUDText = new TextGameObject();
	m_HUDText->setText("Lose");
	m_HUDText->setPosition(sf::Vector2f(400, 400));
	m_HUDText->setCharSize(40);
	m_HUDText->setColour(sf::Color::Blue);
	m_HUDText->setUI();
	m_HUDText->Initialise();


}

//////////////////////////////
// Update the Game State
//////////////////////////////
void GameStateLose::Update()
{
	GameState::Update();
}

//////////////////////////////
// Get Player Implementation (LATER USAGE)
//////////////////////////////
GameObject* GameStateLose::GetPlayer()
{


	return NULL;
}
