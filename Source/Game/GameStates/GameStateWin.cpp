#include "GameStateWin.h"

//-----------CONSTRUCTOR / DESTRUCTOR-------------------------

//////////////////////////////
// Constructor for the Class
//////////////////////////////
GameStateWin::GameStateWin()
{
}

//////////////////////////////
// Destructor for the Class
//////////////////////////////
GameStateWin::~GameStateWin()
{
}

//-----------CLASS FUNCTIONS------------------------------------

//////////////////////////////
// Initialise the Game State
//////////////////////////////
void GameStateWin::Initialise()
{

	// Create and Initialise HUD Objects
	m_HUDText = new TextGameObject();
	m_HUDText->setText("Win");
	m_HUDText->setPosition(sf::Vector2f(400, 400));
	m_HUDText->setCharSize(40);
	m_HUDText->setColour(sf::Color::Blue);
	m_HUDText->setUI();
	m_HUDText->Initialise();


}

//////////////////////////////
// Update the Game State
//////////////////////////////
void GameStateWin::Update()
{
	GameState::Update();
}

//////////////////////////////
// Get Player Implementation (LATER USAGE)
//////////////////////////////
GameObject* GameStateWin::GetPlayer()
{


	return NULL;
}
