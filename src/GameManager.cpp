#include "GameManager.h"

GameManager::GameManager()
	:m_levels(loadLevels("Playlist.txt")),
	m_board(Board(m_levels[0]))
{}

void GameManager::run()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "BomberMan");
	sf::Clock clock;

	while (window.isOpen())
	{
		window.clear();
		m_board.draw(window);
		window.display();
		sf::Event event;
		sf::Time deltaTime = clock.restart();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		m_board.update(event, deltaTime);

	}

	
}

std::vector<std::string> GameManager::loadLevels(std::string fileName)
{
	auto file = std::ifstream(fileName);
	std::string line;
	std::vector<std::string> levels;
	while (std::getline(file, line))
	{
		levels.push_back(line);
	}
	return levels;
}
