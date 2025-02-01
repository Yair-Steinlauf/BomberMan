#include "GameOverScreen.h"
#include <string> 

GameOverScreen::GameOverScreen() 
{
	if (!m_font.loadFromFile("font.ttf")) {
		std::cerr << "Failed to load font!" << std::endl;
	}

	// יצירת כפתורים
	m_Buttoms.push_back({ AGAIN, createButtom("Play Again", sf::Vector2f(200, 400)) });
	m_Buttoms.push_back({ EXIT, createButtom("Exit Game", sf::Vector2f(200, 500)) });
	m_Buttoms.push_back({ SOUND, createButtom("Sound", sf::Vector2f(500 , 400))});
	m_Buttoms.push_back({ MUSIC,createButtom("Music", sf::Vector2f(500 , 500)) });
}

void GameOverScreen::setIsVictoryNScore(bool isVictory, int score, sf::Music& backgroundMusic)
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

	std::string strScore = "You get " + std::to_string(score) + " score!";
	m_sfScore = sf::Text(strScore, DataLoader::getP2Font(), 40);
	m_sfScore.setPosition(sf::Vector2f(300, 300));

	bool isPlaying = backgroundMusic.getStatus() == sf::Music::Status::Playing;
	std::string isMusicPlay = isPlaying ? "ON" : "OFF";
	m_Buttoms[3].second.setString("Music - " + isMusicPlay);

}


void GameOverScreen::eventHandler(sf::Event& event, sf::RenderWindow& window, GameState& status, sf::Music &backgroundMusic, bool &isMouseClicked)
{

	window.setSize(sf::Vector2u(800, 600));
	window.setView(sf::View(sf::FloatRect(0, 0, 800, 600)));
	if (event.type == sf::Event::Closed)
		window.close();
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2f mousePosition = window.mapPixelToCoords(
				sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
			handleClick(mousePosition, status, backgroundMusic, isMouseClicked);
		}
	}

}


void GameOverScreen::handleClick(sf::Vector2f& mousePos, GameState& status, sf::Music& backgroundMusic, bool& isMouseClicked)
{

	for (const auto& buttom : m_Buttoms)
	{
		if (buttom.second.getGlobalBounds().contains(mousePos))
		{
			switch (buttom.first)
			{
			case AGAIN:
				status = REMATCH;				
				break;
			case EXIT:
				exit(EXIT_SUCCESS);
				//TODO: maybe delete this feture
				break;
			case SOUND:
				//TODO: add music and handel it
				break;
			case MUSIC:
				if (!isMouseClicked) {
					isMouseClicked = true;
					backgroundMusic.getStatus() == sf::Music::Status::Playing ? backgroundMusic.stop() : backgroundMusic.play();
				}
				break;
			default:
				break;
			}
		}
	}

}
