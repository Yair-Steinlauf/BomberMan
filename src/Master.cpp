#include "Master.h"

Master::Master()
{
	DataLoader::Init();
}

void Master::run()
{
	SoundHandle::getInstance().m_backgroundMusic.play();
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HIGTH + scoreBoardPadding), "BomberMan");
	window.setFramerateLimit(60u);

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
				m_status = PAUSE;
			handelEvent(event, window);
		}
		if (m_status == PLAYING)
			m_game.updatePlayer(event);
		drawNdisplay(window, deltaTime);
	}
}

void Master::drawNdisplay(sf::RenderWindow &window, sf::Time &deltaTime)
{
	{
		switch (m_status)
		{
		case MENU:
			m_menu.drawNDisplay(window, m_status);
			break;
		case PLAYING:
			m_game.drawNDisplay(window, deltaTime, m_status);
			break;
		case GAMEOVER:
			m_GameOver.setIsVictoryNScore(m_game.isWon(), m_game.getPlayerScore());
			m_GameOver.drawNDisplay(window, m_status);
			break;
		case PAUSE:
			m_pauseScreen.pauseClicked(m_game.getPlayerScore());
			m_pauseScreen.drawNDisplay(window, m_status);
			break;
		case HELP:
			m_helpScreen.drawNDisplay(window, m_status);
			break;
		default:
			break;
		}
	}
}
void Master::handelEvent(sf::Event &event, sf::RenderWindow &window)
{

	switch (m_status)
	{
	case MENU:
		m_lastStatus = MENU;
		m_menu.eventHandler(event, window, m_status);
		break;
	case GAMEOVER:
		m_lastStatus = GAMEOVER;
		m_GameOver.eventHandler(event, window, m_status);
		break;
	case PAUSE:
		m_lastStatus = PAUSE;
		m_pauseScreen.eventHandler(event, window, m_status);
		break;
	case HELP:
		m_helpScreen.eventHandler(event, window, m_status);
		break;
	case RETURN:
		m_status = m_lastStatus;
		break;
	case REMATCH:
		m_game = GameManager();
		m_status = PLAYING;
		break;
	case PLAYING:
		m_game.eventHandler(event, m_status);
		break;
	default:
		break;
	}
}