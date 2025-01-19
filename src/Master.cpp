#include "Master.h"



void Master::run()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Init Window");
	window.setFramerateLimit(60u);
	m_menu.drawNDisplay(window);
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		sf::Time deltaTime = clock.restart();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		handelEvent(event, window, deltaTime, m_status);
	}
}

void Master::handelEvent(sf::Event& event, sf::RenderWindow& window, sf::Time& deltaTime, GameState& status)
{
	switch (m_status)
	{
	case MENU:
		m_menu.eventHandler(event, window, status);
		m_menu.drawNDisplay(window);

		break;
	case PLAYING:
		m_game.handelEvent(event, deltaTime , status);
		m_game.screenDrawNDisplay(window);
		break;
	case GAMEOVER:
		break;
	default:
		break;
	}


}