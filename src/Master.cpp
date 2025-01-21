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
			
		}
		handelEvent(event, window, deltaTime);
	}
}

void Master::handelEvent(sf::Event& event, sf::RenderWindow& window, sf::Time& deltaTime)
{
	switch (m_status)
	{
	case MENU:
		m_menu.eventHandler(event, window, m_status);
		m_menu.drawNDisplay(window);


		break;
	case PLAYING:
		m_game.handelEvent(event, deltaTime , m_status);
		m_game.screenDrawNDisplay(window);
		break;
	case GAMEOVER:
		break;
	default:
		break;
	}


}