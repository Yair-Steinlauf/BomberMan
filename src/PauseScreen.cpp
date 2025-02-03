#include "GameOverScreen.h"
#include <string> 
#include "PauseScreen.h"

PauseScreen::PauseScreen()
{
	// יצירת כפתורים
	int y = 50;	
	m_Buttoms.push_back({ RESUME, createButtom("Resume", sf::Vector2f(300, y*4)) });
	m_Buttoms.push_back({ AGAIN, createButtom("Play Again", sf::Vector2f(300, y*5)) });
	m_Buttoms.push_back({ EXIT, createButtom("Exit Game", sf::Vector2f(300, y*6)) });
	m_Buttoms.push_back({ SOUND, createButtom("Sound", sf::Vector2f(300, y*7)) });
	m_Buttoms.push_back({ MUSIC, createButtom("Music", sf::Vector2f(300, y*8)) });
	m_Buttoms.push_back({ S_HELP, createButtom("Help", sf::Vector2f(300, y*9)) });
	
}

void PauseScreen::pauseClicked(int score, sf::Music& backgroundMusic)
{
	bool isPlaying = backgroundMusic.getStatus() == sf::Music::Status::Playing;	
	std::string isMusicPlay = isPlaying ? "ON" : "OFF";
	m_Buttoms[4].second.setString("Music - " + isMusicPlay);

	if (SoundHandle::getInstance().getIsSoundOn()) {
		m_Buttoms[3].second.setString("Sound- ON");
	}
	else {
		m_Buttoms[3].second.setString("Sound- OFF");
	}

	std::string strPoints = "Your score is: " + std::to_string(score);
	m_sfScore = sf::Text(strPoints, DataLoader::getP2Font(), 40);
	m_sfScore.setPosition(sf::Vector2f(300, 50));
}


void PauseScreen::eventHandler(sf::Event& event, sf::RenderWindow& window, GameState& status, sf::Music &backgroundMusic)
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


void PauseScreen::handleClick(sf::Vector2f& mousePos, GameState& status, sf::Music& backgroundMusic)
{

	for (const auto& buttom : m_Buttoms)
	{
		if (buttom.second.getGlobalBounds().contains(mousePos))
		{
			switch (buttom.first)
			{
			
			case RESUME:
				status = PLAYING;
				break;

			case AGAIN:
				status = REMATCH;
				break;
			case EXIT:
				exit(EXIT_SUCCESS);
				//TODO: maybe delete this feture
				break;
			case SOUND:						
				SoundHandle::getInstance().changeSoundMode();				
				break;
			case MUSIC:		
			backgroundMusic.getStatus() == sf::Music::Status::Playing ? backgroundMusic.stop() : backgroundMusic.play();						break;
			case S_HELP:
				status = HELP;
				break;
			default:
				break;
			}
		}
	}

}
