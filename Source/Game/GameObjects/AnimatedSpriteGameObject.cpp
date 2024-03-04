#include "AnimatedSpriteGameObject.h"

#include "../../Engine/System/Context/SysContextProvider.h"

//-----------CONSTRUCTOR / DESTRUCTOR-------------------------

AnimatedSpriteGameObject::AnimatedSpriteGameObject()
{
	pInputManager = C_SysContext::Get<InputManager>();
	pInputDevice = pInputManager->GetInputDevice();

	this->m_SpriteID = 1;
	this->m_SpritesheetFile = "sprites/spr_pistol_jimmy_0.png";
	this->m_FPS = 10;
	this->m_Loop = true;

	this->m_CurrAnim = 1;

	this->m_Pos = sf::Vector2f(0, 0);
	this->m_PosToMove = sf::Vector2f(0, 0);
	this->m_Rot = 0.0f;
	this->m_RotToMove = 0.0f;
	this->m_Scale = sf::Vector2f(1, 1);
	this->m_ScaleToSet = sf::Vector2f(1, 1);
}

AnimatedSpriteGameObject::~AnimatedSpriteGameObject()
{
	m_Frames.clear();
	m_Origin.clear();
}

//-----------CLASS FUNCTIONS------------------------------------

//////////////////////////////
// Initialise the Game Object
//////////////////////////////
void AnimatedSpriteGameObject::Initialise()
{
	m_AnimatedSprite.AddAnimation(m_SpriteID, m_SpritesheetFile.c_str(), m_Frames, m_Origin, m_FPS, m_Loop);
	m_AnimatedSprite.setColor(m_Colour);
	m_AnimatedSprite.setPosition(m_Pos);
	m_AnimatedSprite.setRotation(m_Rot);
	m_AnimatedSprite.setScale(m_Scale);

	m_AnimatedSprite.SetCurrentAnimation(m_CurrAnim);
}

//////////////////////////////
// Update the Game Object
//////////////////////////////
void AnimatedSpriteGameObject::Update()
{
	m_AnimatedSprite.Animate();
	
	m_AnimatedSprite.rotate(m_RotToMove);
	m_AnimatedSprite.scale(m_ScaleToSet);

	if (pInputDevice->GetButtonInput(E_DigitalInput_DpadDown).IsDown())		{		m_AnimatedSprite.move(tdown);		}
	if (pInputDevice->GetButtonInput(E_DigitalInput_DpadUp).IsDown())		{		m_AnimatedSprite.move(tup);			}
	if (pInputDevice->GetButtonInput(E_DigitalInput_DpadLeft).IsDown())		{		m_AnimatedSprite.move(tleft);		}
	if (pInputDevice->GetButtonInput(E_DigitalInput_DpadRight).IsDown())	{		m_AnimatedSprite.move(tright);		}
	
}

void AnimatedSpriteGameObject::setCurrentAnimation(int pcurranim)
{
	this->m_CurrAnim = pcurranim;
}

//////////////////////////////
// Get the Position of the Game
// Object and store it in 
// two Reference Parameters
//////////////////////////////
void AnimatedSpriteGameObject::GetPosition(int& x, int& y)
{
	x = m_AnimatedSprite.getPosition().x;
	y = m_AnimatedSprite.getPosition().y;
}

//////////////////////////////
// Set the Sprite of the
// Game Object
//////////////////////////////
void AnimatedSpriteGameObject::setSpritesheet(std::string psprite)
{
	this->m_SpritesheetFile = "sprites/" + psprite;
}

//////////////////////////////
// Set the Frame Size of the
// Game Object
//////////////////////////////
void AnimatedSpriteGameObject::setOrigin(sf::Vector2f porigin)
{
	this->m_Origin.push_back(porigin);
}

//////////////////////////////
// Set the Frames of the Game
// Object using sf::IntRect
//////////////////////////////
void AnimatedSpriteGameObject::addFrames(int pframes, int pwidth, int pheight)
{
	sf::IntRect m_FirstRect(0, 0, pwidth, pheight);
	this->m_lastFrameLoaded = m_FirstRect.width;

	sf::Vector2f m_orig(pwidth / 2, pheight / 2);
	this->m_Origin.push_back(m_orig);

	this->m_Frames.push_back(m_FirstRect);
	for (int i = 0; i < pframes; i++)
	{
		sf::IntRect m_NextRect(m_lastFrameLoaded, 0, pwidth, pheight);
		this->m_Frames.push_back(m_NextRect);
		this->m_lastFrameLoaded += pwidth;
		
		sf::Vector2f m_orig(pwidth / 2, pheight / 2);
		this->m_Origin.push_back(m_orig);
	}
}

//////////////////////////////
// Set the Starting Position
// of the Game Object
//////////////////////////////
void AnimatedSpriteGameObject::setPosition(sf::Vector2f ppos)
{
	this->m_Pos = ppos;
}

//////////////////////////////
// Change the Position of
// the Game Object
//////////////////////////////
void AnimatedSpriteGameObject::movePosition(sf::Vector2f ppos)
{
	this->m_PosToMove = ppos;
}

//////////////////////////////
// Set the Starting Colour
// of the Game Object
//////////////////////////////
void AnimatedSpriteGameObject::setColour(sf::Color pcolour)
{
	this->m_Colour = pcolour;
}

//////////////////////////////
// Set the Starting Scale
// of the Game Object
//////////////////////////////
void AnimatedSpriteGameObject::setScale(sf::Vector2f pscale)
{
	this->m_Scale = pscale;
}

//////////////////////////////
// Change the Scale of the
// Game Object
//////////////////////////////
void AnimatedSpriteGameObject::changeScale(sf::Vector2f pscale)
{
	this->m_ScaleToSet = pscale;
}

//////////////////////////////
// Set the Starting Rotation
// of the Game Object
//////////////////////////////
void AnimatedSpriteGameObject::setRotation(float pangle)
{
	this->m_Rot = pangle;
}

//////////////////////////////
// Change the Rotation of
// the Game Object
//////////////////////////////
void AnimatedSpriteGameObject::Rotate(float pangle)
{
	this->m_RotToMove = pangle;
}
