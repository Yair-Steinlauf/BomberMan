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
		window.create(sf::VideoMode(board.getDimension().x, board.getDimension().y) , "BomberMan");// TODO: change window size to board dimension
		window.setFramerateLimit(60u);
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
					player->setDirection(eventToDirection(event));
				}
				if (event.type == sf::Event::KeyReleased) {
					player->setDirection(DEFAULT);
				}
			}
			sf::Time deltaTime = clock.restart();
			board.update(deltaTime);
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

Direction Controller::eventToDirection(sf::Event& event) 
{
	switch (event.key.code)
	{
	case sf::Keyboard::Up:
		return UP;
		break;
	case sf::Keyboard::Down:
		return DOWN;
		break;
	case sf::Keyboard::Left:
		return LEFT;
		break;
	case sf::Keyboard::Right:
		return RIGHT;
		break;
	default:
		return DEFAULT;
		break;
	}
}