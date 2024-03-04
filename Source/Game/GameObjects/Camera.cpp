#include "Camera.h"
#include "../../Engine/Renderer/WindowManager.h"
#include "../../Engine/System/Assets/AssetManager.h"
#include "../../Engine/Renderer/RenderManager.h"
#include "../../Engine/System/Context/SysContextProvider.h"

Camera::Camera()
{

}

Camera::~Camera()
{
	RemoveCamera();
}

void Camera::Initialise()
{
	WindowManager* pWindowManger = C_SysContext::Get<WindowManager>();

	m_View = pWindowManger->GetWindow()->getDefaultView();

	CameraPos = sf::Vector2f(0, 0);

	m_View.setCenter(CameraPos);

}

void Camera::Update()
{
	m_View.setCenter(GetCameraPos());

	if (m_Active)
	{
		WindowManager* pWindowManager = C_SysContext::Get<WindowManager>();
		pWindowManager->GetWindow()->setView(m_View);
	}
}

sf::Vector2f Camera::GetCameraPos()
{
	return CameraPos;
}

void Camera::SetCameraPos(sf::Vector2f ppos)
{
	CameraPos.x = CameraPos.x - (CameraPos.x - ppos.x);
	CameraPos.y = CameraPos.y - (CameraPos.y - ppos.y);
}

void Camera::GetPosition(int& x, int& y)
{

}


void Camera::SetAsCurrentCamera()
{
	m_Active = true;
	WindowManager* pWindowManager = C_SysContext::Get<WindowManager>();
	pWindowManager->GetWindow()->setView(m_View);
}

void Camera::RemoveCamera()
{
	WindowManager* pWindowManager = C_SysContext::Get<WindowManager>();
	pWindowManager->GetWindow()->setView(pWindowManager->GetWindow()->getDefaultView());
	
	m_Active = false;
}

