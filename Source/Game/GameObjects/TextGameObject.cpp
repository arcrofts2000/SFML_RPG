#include "TextGameObject.h"

//-----------CONSTRUCTOR / DESTRUCTOR-------------------------

//////////////////////////////
// Constructor for the Class
//////////////////////////////
TextGameObject::TextGameObject()
{
	this->m_Font = "fonts/8-BIT WONDER.TTF";
	this->m_Colour = sf::Color::Blue;
	this->m_CharSize = 32;
	this->m_TextStr = "Hello World";
	this->m_isUI = false;
}

//////////////////////////////
// Destructor for the Class
//////////////////////////////
TextGameObject::~TextGameObject()
{

}

//-----------CLASS FUNCTIONS------------------------------------

//////////////////////////////
// Initialise the Game Object
//////////////////////////////
void TextGameObject::Initialise()
{
	this->m_Text.Initialise(m_Font.c_str(), m_Pos.x, m_Pos.y, m_TextStr.c_str(), m_CharSize, m_Colour, m_isUI);
}

//////////////////////////////
// Update the Game Object
//////////////////////////////
void TextGameObject::Update()
{

}

//////////////////////////////
// Get the Position of the Game
// Object and store it in 
// two Reference Parameters
//////////////////////////////
void TextGameObject::GetPosition(int& x, int& y)
{
	x = m_Text.GetText().getPosition().x;
	y = m_Text.GetText().getPosition().y;
}

//////////////////////////////
// Set the Position of the Text
//////////////////////////////
void TextGameObject::setPosition(sf::Vector2f ppos)
{
	this->m_Pos = ppos;
}

//////////////////////////////
// Set the Font of the Text
//////////////////////////////
void TextGameObject::setFont(std::string pfont)
{
	this->m_Font = pfont;
}

//////////////////////////////
// Set the Colour of the Text
//////////////////////////////
void TextGameObject::setColour(sf::Color pcolour)
{
	this->m_Colour = pcolour;
}

//////////////////////////////
// Set the Character Size 
// of the Text
//////////////////////////////
void TextGameObject::setCharSize(int psize)
{
	this->m_CharSize = psize;
}

//////////////////////////////
// Set the Message of the Text
//////////////////////////////
void TextGameObject::setText(std::string ptext)
{
	this->m_TextStr = ptext;
}

//////////////////////////////
// Set if the GameObject is
// a UI element
//////////////////////////////
void TextGameObject::setUI()
{
	this->m_isUI = true;
}