#pragma once
#include "../../Engine/Input/InputDevice.h"

class KeyboardAndMouseInputDevice :
	public InputDevice
{
public:
	KeyboardAndMouseInputDevice();
	~KeyboardAndMouseInputDevice();

public:
	virtual void ProcessInputs();

private:


};

