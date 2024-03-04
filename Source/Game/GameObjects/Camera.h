#include <SFML\Graphics.hpp>

#include "../../Engine/Core/GameObject.h"

#include "../../Engine/Input/InputManager.h"
#include "../../Engine/Input/InputDevice.h"


class Camera :
	public GameObject
{
public:

							Camera();
							~Camera();

	virtual void			Initialise()					override;
	virtual void			Update()						override;
	virtual void			GetPosition(int& x, int& y)		override;

public:
	virtual void			SetAsCurrentCamera();
	virtual void			RemoveCamera();

	sf::Vector2f			GetCameraPos();
	void					SetCameraPos(sf::Vector2f ppos);

private:
	sf::View				m_View;
	bool					m_Active;

	sf::Vector2f            CameraPos;

	sf::Vector2f			NewPos;

};