#pragma once

#include "../../Engine/Renderer/AnimatedSprite.h"
#include "../../Engine/Core/GameObject.h"

#include "../../Engine/Input/InputManager.h"
#include "../../Engine/Input/InputDevice.h"

class AnimatedSpriteGameObject : public GameObject
{
public:
										AnimatedSpriteGameObject();
										~AnimatedSpriteGameObject();

public:
	virtual void						Initialise() override;
	virtual void						Update() override;
	virtual void						GetPosition(int& x, int& y) override;

public:
	void								setSpritesheet(std::string psprite);
	void								setOrigin(sf::Vector2f porigin);
	void								addFrames(int pframes, int pwidth, int pheight);
	void								setCurrentAnimation(int pcurranim);

	void								setPosition(sf::Vector2f ppos);
	void								movePosition(sf::Vector2f ppos);

	void								setColour(sf::Color pcolour);

	void								setScale(sf::Vector2f pscale);
	void								changeScale(sf::Vector2f pscale);

	void								setRotation(float pangle);
	void								Rotate(float pangle);

private:
	AnimatedSprite						m_AnimatedSprite;

protected:
	InputDevice* pInputDevice;
	InputManager* pInputManager;

	int									m_CurrAnim;

	int									m_lastFrameLoaded;

	int									m_SpriteID;
	std::string							m_SpritesheetFile;
	std::vector<sf::IntRect>			m_Frames;
	std::vector<sf::Vector2f>			m_Origin;
	int									m_FPS;
	bool								m_Loop;

	sf::Vector2f						m_Pos;
	sf::Vector2f						m_PosToMove;
	sf::Color							m_Colour;
	float								m_Rot;
	float								m_RotToMove;
	sf::Vector2f						m_Scale;
	sf::Vector2f						m_ScaleToSet;

	// Movement
	sf::Vector2f tdown = sf::Vector2f(0.0f, 1.0f);
	sf::Vector2f tup = sf::Vector2f(0.0f, -1.0f);
	sf::Vector2f tright = sf::Vector2f(1.0f, 0.0f);
	sf::Vector2f tleft = sf::Vector2f(-1.0f, 0.0f);
	
};
