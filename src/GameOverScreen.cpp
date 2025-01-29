#include "GameOverScreen.h"
#include <string> 

GameOverScreen::GameOverScreen() 
{
	if (!m_font.loadFromFile("font.ttf")) {
		std::cerr << "Failed to load font!" << std::endl;
	}

	// יצירת כפתורים
	m_Buttoms.push_back({ START, createButtom("Play Again", sf::Vector2f(200, 400)) });
	m_Buttoms.push_back({ EXIT, createButtom("Exit Game", sf::Vector2f(200, 500)) });
	m_Buttoms.push_back({ SOUND, createButtom("Sound", sf::Vector2f(500 , 400))});
	m_Buttoms.push_back({ MUSIC,createButtom("Music", sf::Vector2f(500 , 500)) });
}

void GameOverScreen::setIsVictoryNPoints(bool isVictory, int points)
{
	// יצירת תמונת ניצחון או הפסד
	std::string imagePath = isVictory ? "VICTORY.png" : "DEFEAT.png";

	if (!m_texture.loadFromFile(imagePath)) {
		std::cerr << "Error loading image\n";
		exit(EXIT_FAILURE);
	}
	m_gameOverImage.setTexture(m_texture);
	m_gameOverImage.setScale(0.8f, 0.8f);
	m_gameOverImage.setPosition((800 - m_texture.getSize().x * 0.8f) / 2, 0);

	std::string strPoints = "You get " + std::to_string(points) + " points!";
	m_sfPoints = sf::Text(strPoints, DataLoader::getP2Font(), 40);
	m_sfPoints.setPosition(sf::Vector2f(300, 300));

}


void GameOverScreen::eventHandler(sf::Event& event, sf::RenderWindow& window, GameState& status)
{
	window.setSize(sf::Vector2u(800, 600));
	window.setView(sf::View(sf::FloatRect(0, 0, 800, 600)));
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


void GameOverScreen::handleClick(sf::Vector2f& mousePos, GameState& status)
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
