#ifndef _RENDER_MANAGER_H
#define _RENDER_MANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>

namespace sf
{
	class Drawable;
	class View;
}

class WindowManager;

class RenderManager
{
public:

	RenderManager();
	~RenderManager();

	void Initialise(const int& windowWidth, const int& windowHeight, const char* windowTitle);
	void Render();

	void AddRenderObject(sf::Drawable* renderObject);
	void RemoveRenderObject(sf::Drawable* renderObject);

	void AddUIRenderObject(sf::Drawable* renderObject);
	void RemoveUIRenderObject(sf::Drawable* renderObject);

	void PushRenderGroup();
	void PopRenderGroup();

private:

	bool m_Initialised;
	WindowManager* m_pWindowManager;

	std::vector<std::vector<sf::Drawable*>> m_RenderObjects;
	std::vector<std::vector<sf::Drawable*>> m_UIRenderObjects;

	sf::View m_UIView;

};

#endif
