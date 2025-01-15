#include "Controller.h"

Controller::Controller()
	:m_levels(getLevels())
{
}

std::vector<std::string> Controller::getLevels()
{
	std::ifstream file("playlist.txt");
	std::string line;
	std::vector<std::string> levels;
	while (std::getline(file, line))
	{
		levels.push_back(line);
	}
	return levels;
}
void Controller::run()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "BomberMan");
	for (const auto& level : m_levels)
	{
		auto board = loadNewLevel(level);

		Player* player = &board.getPlayer();
		sf::Clock clock;


		while (window.isOpen())
		{
			window.clear();
			board.draw(window);
			window.display();
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (event.type == sf::Event::KeyPressed) {
					sf::Time deltaTime = clock.restart();
					player->move(deltaTime, event);
				}
			}
			board.update();
		}
	}
}

Board Controller::loadNewLevel(const std::string& levelName)
{
	auto level = std::ifstream(levelName);
	if (!level.is_open())
	{
		//TODO:  mabye offer to create new level via editor?
	}
	return Board(level);
}