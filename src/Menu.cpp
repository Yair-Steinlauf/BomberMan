#include "Menu.h"


Menu::Menu()

{
	loadButtomsVector();

}

void Menu::loadButtomsVector()
{
	m_Buttoms.push_back({ START, createButtom("Start Game", sf::Vector2f(300, 150)) });
	m_Buttoms.push_back({ EXIT, createButtom("Exit Game", sf::Vector2f(300, 250)) });
	m_Buttoms.push_back({ SOUND, createButtom("Sound - ON", sf::Vector2f(300, 350)) });
	m_Buttoms.push_back({ MUSIC,createButtom("Music - ON", sf::Vector2f(300, 450)) });
}




void Menu::eventHandler(sf::Event& event, sf::RenderWindow& window, GameState& status, sf::Music& backgroundMusic)
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

void Menu::handleClick(sf::Vector2f& mousePos, GameState& status, sf::Music& backgroundMusic)
{

	for (const auto& buttom : m_Buttoms)
	{
		if (buttom.second.getGlobalBounds().contains(mousePos))
		{
			switch (buttom.first)
			{
			case START:
				status = PLAYING;
				SoundHandle::getInstance().playSound(S_START_GAME);
				break;
			case EXIT:
				exit(EXIT_SUCCESS);
				//TODO: maybe delete this feture
				break;
			case SOUND:
				if (SoundHandle::getInstance().getIsSoundOn()) {
					m_Buttoms[2].second.setString("Sound - OFF");
				}
				else {
					m_Buttoms[2].second.setString("Sound- ON");
				}
				SoundHandle::getInstance().changeSoundMode();
				break;
			case MUSIC:				
				if (backgroundMusic.getStatus() == sf::Music::Status::Playing) {
					backgroundMusic.stop();
					m_Buttoms[3].second.setString("Music - OFF");
				}
				else {
					backgroundMusic.play();
					m_Buttoms[3].second.setString("Music - ON");
				}				
				break;
			default:
				break;
			}
		}
	}

}

