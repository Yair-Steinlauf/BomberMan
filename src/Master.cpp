#include "Master.h"

Master::Master()
{
	DataLoader::Init();
}

void Master::run()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HIGTH), "Init Window");
	window.setFramerateLimit(60u);


	if (!m_backgroundMusic.openFromFile("background-music.ogg")) {
		std::cerr << "Error loading music!" << std::endl;
		exit(EXIT_FAILURE);
	}
	m_backgroundMusic.setLoop(true);
	m_backgroundMusic.setVolume(100);
	m_backgroundMusic.play();


	sf::Clock clock;
	bool isMouseClicked = false;
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
		// handelEvent(event, window, deltaTime, isMouseClicked);
		// if (event.type == sf::Event::MouseButtonReleased) {
		// 	isMouseClicked = false;
		// } TODO: currect by loop use
	}
		
}

void Master::drawNdisplay(sf::RenderWindow& window, sf::Time& deltaTime)
{
	{
		switch (m_status)
		{
		case MENU:
			m_menu.drawNDisplay(window, m_status);
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
	// TODO: deltaTime limit in gameover,menu,pause to handle problem with click event
	
	switch (m_status)
	{
		if (!isMouseClicked) {
	case MENU:
		m_menu.eventHandler(event, window, m_status, m_backgroundMusic, isMouseClicked);
		// m_menu.drawNDisplay(window, m_status);//TODO: change stat on handle event
		break;

	case GAMEOVER:
		m_GameOver = GameOverScreen();
		m_GameOver.setIsVictoryNScore(m_game.isWon(), m_game.getPlayerScore(), m_backgroundMusic);
		m_GameOver.eventHandler(event, window, m_status, m_backgroundMusic, isMouseClicked);
		m_GameOver.drawNDisplay(window, m_status);
		break;

	case PAUSE:
		m_pauseScreen.pauseClicked(m_game.getPlayerScore(), m_backgroundMusic);
		m_pauseScreen.eventHandler(event, window, m_status, m_backgroundMusic, isMouseClicked);
		m_pauseScreen.drawNDisplay(window, m_status);
		break;

		}
		
	
	case REMATCH:
		m_game = GameManager();
		m_status = PLAYING;

	case PLAYING:
		m_game.eventHandler(event, deltaTime, m_status);
		break;

	default:
		break;
	}


}