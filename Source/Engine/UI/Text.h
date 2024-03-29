#ifndef _TEXT_H
#define _TEXT_H

#include "SFML\Graphics.hpp"

class Text
{
public:

	Text();
	~Text();

	void Initialise(const char* filename, const int x, const int y, const char* text, int psize, sf::Color pcolour, bool isUIObject = false);
	const sf::Text& GetText() { return m_Text; }

private:

	sf::Text m_Text;
	bool m_Initialised;
	bool m_isUIObject;

};

#endif
