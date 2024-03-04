#include "GameStateTest.h"
#include "../GameTileMaps/TileMap.h"
#include "../../Engine/System/Context/SysContextProvider.h"


//-----------CONSTRUCTOR / DESTRUCTOR-------------------------

//////////////////////////////
// Constructor for the Class
//////////////////////////////
GameStateTest::GameStateTest():GameState()
{
	pInputManager = C_SysContext::Get<InputManager>();
	pInputDevice = pInputManager->GetInputDevice();
	this->m_isPaused = false;
}

//////////////////////////////
// Destructor for the Class
//////////////////////////////
GameStateTest::~GameStateTest()
{

}

//-----------CLASS FUNCTIONS------------------------------------

//////////////////////////////
// Initialise the Game State
//////////////////////////////
void GameStateTest::Initialise()
{
	// tile map for dasert level
	const int desertLevel0[] =
	{
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
	};

	const int desertLevel1[]
	{
		17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
		17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
		17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
		17, 2, 4, 6, 8, 13, 23, 4, 6, 8, 10, 17, 22, 6, 8, 17,
		17,  3,  5,  7,   9, 10,  2,  5,  7,  9, 11, 15, 24,  7,  9, 17,
		24, -1, -1, -1,  -1, 11,  3, -1, -1, -1, -1,  2,  4, -1, -1, 13,
		22, -1, -1, -1,  -1, -1, -1, -1, -1, -1, -1,  3,  5, -1, -1, 17,
		23, -1, -1, -1,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 15,
		24, -1, -1, -1,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 14,
		22, -1, -1, -1,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 17,
		23, -1, -1, -1,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 15,
		24, -1, -1, -1,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 13,
		22, -1, -1, -1,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 14,
		23, -1, -1, -1,  -1, -1, -1, -1, -1, -1, 12, 21, -1, -1, -1, 17,
		23, -1, -1, -1,  -1, -1, -1, -1, -1, 12, 17, 20, 21, -1, -1, 13,
		17, 16, 17, 18,  17, 19, 20, 17, 18, 17, 17, 17, 17, 16, 18, 17,
	};

	GameDataManager* pGameDataManager = C_SysContext::Get<GameDataManager>();
	SpritesheetDef* pSpritsheetDef = pGameDataManager->GetSpritesheetDef("backgrounds/bg_desert.xml");

	TileMap* pTileMap = new TileMap();
	pTileMap->Initialise();
	pTileMap->LoadFromSpritesheetDef(pSpritsheetDef, desertLevel0, 16, 16);
	m_GameObjects.push_back(pTileMap);

	TileMap* pTileMap1 = new TileMap();
	pTileMap1->Initialise();
	pTileMap1->LoadFromSpritesheetDef(pSpritsheetDef, desertLevel1, 16, 16);
	m_GameObjects.push_back(pTileMap1);

	m_Camera = new Camera();
	m_Camera->Initialise();
	m_GameObjects.push_back(m_Camera);
	
	

	// Create and Initialise Objects

	// Create and Initialise HUD Objects
	m_HUDSpriteTest = new SpriteGameObject();
	m_HUDSpriteTest->setSprite("spr_hud_face_raff_0.png");
	m_HUDSpriteTest->setScale(sf::Vector2f(1, 1));
	m_HUDSpriteTest->setPosition(sf::Vector2f(20, 660));
	m_HUDSpriteTest->setUI();
	m_HUDSpriteTest->Initialise();

	m_HUDTextTest = new TextGameObject();
	m_HUDTextTest->setText("HUD Test Text");
	m_HUDTextTest->setPosition(sf::Vector2f(120, 710));
	m_HUDTextTest->setCharSize(30);
	m_HUDTextTest->setColour(sf::Color::Blue);
	m_HUDTextTest->setUI();
	m_HUDTextTest->Initialise();

	m_Player = new Player();
	m_Player->SetPlayer("spr_biu");
	m_Player->Initialise();

	m_Enemy = new Enemy();
	m_Enemy->SetEnemy("spr_turtle2", 10, 200, false);
	m_Enemy->Initialise();
	// Add Objects to Array
	// Do not add an HUD elements
	m_GameObjects.push_back(m_Player);
	m_GameObjects.push_back(m_Enemy);


}

//////////////////////////////
// Update the Game State
//////////////////////////////
void GameStateTest::Update()
{
	m_Camera->SetCameraPos(m_Player->GetWorldPos());

	if (pInputDevice->GetButtonInput(E_DigitalInput_A).OnPressed()) {
		this->m_isPaused = true;
	}

	GameState::Update();
}

//////////////////////////////
// Get Player Implementation (LATER USAGE)
//////////////////////////////
GameObject* GameStateTest::GetPlayer()
{

	return NULL;
}