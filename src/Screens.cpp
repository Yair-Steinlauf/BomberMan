#include "Screens.h"


void Screens::drawNDisplay(sf::RenderWindow& window, GameState& status)
{

	window.clear(sf::Color::Black);

	for (auto& buttom : m_Buttoms)
	{
		buttom.second.setFillColor(sf::Color::White);
		window.draw(buttom.second);
	}
	window.draw(m_sfScore);
	if (status == GAMEOVER) {
		window.draw(m_gameOverImage);
	}	
	window.display();
}


void Screens::eventHandler(sf::Event& event, sf::RenderWindow& window, GameState& status, sf::Music &backgroundMusic)
{
	window.setSize(sf::Vector2u(800, 600));
	window.setView(sf::View(sf::FloatRect(0, 0, 800, 600)));
	if (event.type == sf::Event::Closed)
		window.close();
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2f mousePosition = window.mapPixelToCoords(
				sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
			handleClick(mousePosition, status, backgroundMusic);
		}
	}

}

sf::Text Screens::createButtom(std::string text, sf::Vector2f location)
{
	sf::Text sfText(text, DataLoader::getP2Font(), 40);
	sfText.setPosition(location);
	return sfText;
}


