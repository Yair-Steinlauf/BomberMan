#include "Screens.h"

void Screens::drawNDisplay(sf::RenderWindow &window, GameState &status)
{

	window.clear(sf::Color::Black);

	for (auto &buttom : m_Buttoms)
	{
		buttom.second.setFillColor(sf::Color::White);
		window.draw(buttom.second);
	}
	window.draw(m_sfText);
	if (status == GAMEOVER)
	{
		window.draw(m_gameOverImage);
	}
	window.display();
}

void Screens::eventHandler(sf::Event &event, sf::RenderWindow &window, GameState &status)
{
	if (event.type == sf::Event::Closed)
		window.close();
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			sf::Vector2f mousePosition = window.mapPixelToCoords(
				sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
			handleClick(mousePosition, status);
		}
	}
}

sf::Text Screens::createButtom(std::string text, sf::Vector2f location)
{
	sf::Text sfText(text, DataLoader::getP2Font(), 40);
	sfText.setPosition(location);
	return sfText;
}
