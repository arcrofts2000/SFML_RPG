#include "GameStateGameplay.h"

//-----------CONSTRUCTOR / DESTRUCTOR-------------------------

//////////////////////////////
// Constructor for the Class
//////////////////////////////
GameStateGameplay::GameStateGameplay()
{
}

//////////////////////////////
// Destructor for the Class
//////////////////////////////
GameStateGameplay::~GameStateGameplay()
{
}

//-----------CLASS FUNCTIONS------------------------------------

//////////////////////////////
// Initialise the Game State
//////////////////////////////
void GameStateGameplay::Initialise()
{

	// Create and Initialise HUD Objects
	m_HUDText = new TextGameObject();
	m_HUDText->setText("Gameplay");
	m_HUDText->setPosition(sf::Vector2f(400, 400));
	m_HUDText->setCharSize(40);
	m_HUDText->setColour(sf::Color::Blue);
	m_HUDText->setUI();
	m_HUDText->Initialise();


}

//////////////////////////////
// Update the Game State
//////////////////////////////
void GameStateGameplay::Update()
{
	GameState::Update();
}

//////////////////////////////
// Get Player Implementation (LATER USAGE)
//////////////////////////////
GameObject* GameStateGameplay::GetPlayer()
{


	return NULL;
}