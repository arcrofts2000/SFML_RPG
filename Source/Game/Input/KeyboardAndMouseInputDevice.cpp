#include "KeyboardAndMouseInputDevice.h"

#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"

KeyboardAndMouseInputDevice::KeyboardAndMouseInputDevice()
{
	
}

KeyboardAndMouseInputDevice::~KeyboardAndMouseInputDevice()
{
	
}

void KeyboardAndMouseInputDevice::ProcessInputs()
{
	m_DigitalInputs[E_DigitalInput_DpadDown].SetPressed			(    sf::Keyboard::isKeyPressed(sf::Keyboard::S)	  );
	m_DigitalInputs[E_DigitalInput_DpadUp].SetPressed			(    sf::Keyboard::isKeyPressed(sf::Keyboard::W)	  );
	m_DigitalInputs[E_DigitalInput_DpadLeft].SetPressed			(    sf::Keyboard::isKeyPressed(sf::Keyboard::A)	  );
	m_DigitalInputs[E_DigitalInput_DpadRight].SetPressed		(    sf::Keyboard::isKeyPressed(sf::Keyboard::D)	  );
	m_DigitalInputs[E_DigitalInput_B].SetPressed				(    sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) );
	m_DigitalInputs[E_DigitalInput_X].SetPressed				(    sf::Keyboard::isKeyPressed(sf::Keyboard::Space)  );
	m_DigitalInputs[E_DigitalInput_RightShoulder].SetPressed	(	 sf::Mouse::isButtonPressed(sf::Mouse::Left)	  );
	m_DigitalInputs[E_DigitalInput_Y].SetPressed				(    sf::Keyboard::isKeyPressed(sf::Keyboard::E)	  );
	m_DigitalInputs[E_DigitalInput_A].SetPressed				(	 sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) );
}
