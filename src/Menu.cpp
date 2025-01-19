#include "Menu.h"


Menu::Menu()
	:m_startGame(false)
{
	m_font = DataLoader::getP2Font();
	sf::Text startGame("Start Game", m_font, 40);
	startGame.setPosition(300, 150);
	m_Buttoms.push_back({ START, startGame });

	sf::Text exitGame("Exit Game", m_font, 40);
	exitGame.setPosition(300, 250);
	m_Buttoms.push_back({ EXIT,exitGame });

	sf::Text sound("Sound", m_font, 40);
	sound.setPosition(300, 350);
	m_Buttoms.push_back({ SOUND,sound });

	sf::Text music("Music", m_font, 40);
	music.setPosition(300, 450);
	m_Buttoms.push_back({ MUSIC,music });
}


void Menu::eventHandler(sf::Event& event, sf::RenderWindow& window, GameState& status)
{

	if (event.type == sf::Event::Closed)
		window.close();
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2f mousePosition = window.mapPixelToCoords(
				sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
			handleClick(mousePosition, status);
		}
	}

}

void Menu::handleClick(sf::Vector2f& mousePos, GameState& status)
{

	for (const auto& buttom : m_Buttoms)
	{
		if (buttom.second.getGlobalBounds().contains(mousePos))
		{
			switch (buttom.first)
			{
			case START:
				status = PLAYING;
				break;
			case EXIT:
				exit(EXIT_SUCCESS);
				//TODO: maybe delete this feture
				break;
			case SOUND:
				//TODO: add music and handel it
				break;
			case MUSIC:
				break;
			default:
				break;
			}
		}
	}

}

void Menu::drawNDisplay(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);

	for (auto& buttom : m_Buttoms)
	{
		buttom.second.setFillColor(sf::Color::White);
		window.draw(buttom.second);
	}
	window.display();
}
