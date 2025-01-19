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
void Controller::run(sf::RenderWindow& window)
{
	
	
	for (const auto& level : m_levels)
	{
		m_board = loadNewLevel(level);
		window.create(sf::VideoMode(m_board.getDimension().x,
					  m_board.getDimension().y), "BomberMan");
		window.setFramerateLimit(60u);
		Player* player = &m_board.getPlayer();
		sf::Clock clock;
		bool endLevel = false; //TODO: it for load next level
		while (window.isOpen() && !endLevel)
		{
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
					if (event.key.code == sf::Keyboard::P)
					{
						endLevel = true;//TODO: you can choose here to load next level
						break;
					}
				}
			}
			sf::Time deltaTime = clock.restart();
			screenHandler(deltaTime, window);
		}
	}
}

void Controller::screenHandler(sf::Time& deltaTime , sf::RenderWindow& window)
{

	m_board.setDirection(deltaTime);
	m_board.collideHandler();//TODO: ask leonead if collide handler need to be member of board/controller
	m_board.update(deltaTime);
	screenDrawNDisplay(window);
}

void Controller::screenDrawNDisplay(sf::RenderWindow& window)
{
	window.clear();
	m_board.draw(window);
	window.display();

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