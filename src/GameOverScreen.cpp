#include "GameOverScreen.h"
#include <string>

GameOverScreen::GameOverScreen()
{
	m_Buttoms.push_back({AGAIN, createButtom("Play Again", sf::Vector2f(200, 400))});
	m_Buttoms.push_back({EXIT, createButtom("Exit Game", sf::Vector2f(200, 500))});
	m_Buttoms.push_back({SOUND, createButtom("Sound", sf::Vector2f(500, 400))});
	m_Buttoms.push_back({MUSIC, createButtom("Music", sf::Vector2f(500, 500))});
	m_Buttoms.push_back({S_HELP, createButtom("Help", sf::Vector2f(700, 450))});
}

void GameOverScreen::setIsVictoryNScore(bool isVictory, int score)
{
	sf::Texture resultTexture = isVictory ? DataLoader::getP2Texture(VICTORY) : DataLoader::getP2Texture(DEFEAT);
	isVictory ? m_gameOverImage.setTexture(DataLoader::getP2Texture(VICTORY))
			  : m_gameOverImage.setTexture(DataLoader::getP2Texture(DEFEAT));
	m_gameOverImage.setScale(0.8f, 0.8f);
	m_gameOverImage.setPosition((800 - resultTexture.getSize().x * 0.8f) / 2, 0);

	std::string strScore = "You get " + std::to_string(score) + " score!";
	m_sfText = sf::Text(strScore, DataLoader::getP2Font(), 40);
	m_sfText.setPosition(sf::Vector2f(300, 300));

	bool isPlaying = SoundHandle::getInstance().m_backgroundMusic.getStatus() == sf::Music::Status::Playing;
	std::string isMusicPlay = isPlaying ? "ON" : "OFF";
	m_Buttoms[3].second.setString("Music - " + isMusicPlay);

	if (SoundHandle::getInstance().getIsSoundOn())
	{
		m_Buttoms[2].second.setString("Sound - ON");
	}
	else
	{
		m_Buttoms[2].second.setString("Sound- OFF");
	}
}

void GameOverScreen::eventHandler(sf::Event &event, sf::RenderWindow &window, GameState &status)
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

void GameOverScreen::handleClick(sf::Vector2f &mousePos, GameState &status)
{

	for (const auto &buttom : m_Buttoms)
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
				break;
			case SOUND:
				SoundHandle::getInstance().changeSoundMode();
				break;
			case MUSIC:
				SoundHandle::getInstance().m_backgroundMusic.getStatus() == sf::Music::Status::Playing ? SoundHandle::getInstance().m_backgroundMusic.stop() : SoundHandle::getInstance().m_backgroundMusic.play();
				break;
			case S_HELP:
				status = HELP;
				break;
			default:
				break;
			}
		}
	}
}
