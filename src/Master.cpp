#include "Master.h"



Master::Master()
{
	DataLoader::Init();
}

void Master::run()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HIGTH), "Init Window");
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
			if (event.key.code == sf::Keyboard::Escape)
				m_status = MENU;
			handelEvent(event, window);	
		}
		drawNdisplay(window, deltaTime);
	}
}

void Master::drawNdisplay(sf::RenderWindow& window, sf::Time& deltaTime)
{
	{
		switch (m_status)
		{
		case MENU:
			m_menu.drawNDisplay(window);
			break;
		case PLAYING:
			m_game.drawNDisplay(window, deltaTime);
			break;
		case GAMEOVER:
			//winLose screen
			break;
		default:
			break;
		}

	}
}
void Master::handelEvent(sf::Event& event, sf::RenderWindow& window)
{
	switch (m_status)
	{
	case MENU:
		m_menu.eventHandler(event, window, m_status);
		break;
	case PLAYING:
		m_game.eventHandler(event, m_status);
		break;
	case GAMEOVER:
		//winLose screen
		break;
	default:
		break;
	}


}