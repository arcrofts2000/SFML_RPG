#pragma once
#include "../../Engine/Core/GameObject.h"
#include "../../Engine/UI/Text.h"

class TextGameObject :
	public GameObject
{
public:
						TextGameObject();
						~TextGameObject();

public:
	virtual void		Initialise() override;
	virtual void		Update() override;
	virtual void		GetPosition(int& x, int& y) override;

public:
	void				setPosition(sf::Vector2f ppos);
	void				setFont(std::string pfont);
	void				setColour(sf::Color pcolour);
	void				setCharSize(int psize);
	void				setText(std::string ptext);
	void				setUI();

protected:
	Text				m_Text;
	sf::Color			m_Colour;
	std::string			m_Font;
	int					m_CharSize;
	std::string			m_TextStr;
	sf::Vector2f		m_Pos;
	bool				m_isUI;

};

