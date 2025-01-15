#include "GameManager.h"
//
//GameManager::GameManager()
//	:
//	m_board()
//{
///*	m_levels = */loadLevels("playlist.txt");
//	std::string levelName = m_levels[0];
//	m_board = Board(levelName);
//	DataLoader::getInstance();
//}
////GameManager::GameManager()
////	: m_levels(loadLevels("playlist.txt")), // Initialize m_levels using initializer list
////	m_board(Board(m_levels[0]))          // Initialize m_board with the first level
////{
////	DataLoader::getInstance(); // Ensure DataLoader singleton is initialized
////}

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
//
///*std::vector<std::string>*/void GameManager::loadLevels(const std::string& fileName)
//{
//	auto file = std::ifstream(fileName);
//	if (file.is_open())
//	{
//		std::string line;
//		while (std::getline(file, line))
//		{
//			m_levels.push_back(line);
//		}
//	}
//
//	//return levels;
//}
//#include "GameManager.h"

GameManager::GameManager()
    : m_levels(loadLevels("playlist.txt")),
    m_board(Board(m_levels[0]))
{
    DataLoader::getInstance();
}


std::vector<std::string> GameManager::loadLevels(const std::string& fileName)
{
    std::vector<std::string> levels;
    std::ifstream file(fileName);

    if (!file.is_open()) {
        throw std::runtime_error("Unable to open level file: " + fileName);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {  // Skip empty lines
            levels.push_back(line);
        }
    }

    if (levels.empty()) {
        throw std::runtime_error("No levels found in file: " + fileName);
    }

    return levels;
}
