#pragma once
#include "../../Engine/Core/GameObject.h"
#include "../../Engine/Renderer/Sprite.h"
#include "../../Engine/Physics/BoxCollider2D.h"
class SpriteGameObject :
	public GameObject, BoxCollider2D
{
public:
							SpriteGameObject();
							~SpriteGameObject();

public:
	virtual void			Initialise() override;
	virtual void			Update() override;
	virtual void			GetPosition(int& x, int& y) override;
	virtual void			OnCollision(Collider2D* pCollider2D) override;
public:
	void					setSprite(std::string psprite);
	void					setPosition(sf::Vector2f ppos);
	void					setScale(sf::Vector2f pscale);
	void					setUI();

protected:
	Sprite					m_Sprite;
	std::string				m_spriteFile;
	sf::Vector2f			m_Pos;
	sf::Vector2f			m_Scale;
	bool					m_isUI;

};

