#include "GameManager.h"

Controller::Controller()
	:m_levels(getLevels()), m_currLevel(0)
{
	m_board = loadNewLevel(m_levels[m_currLevel]);
}

bool Controller::loadNextLevel()
{
	m_currLevel++;
	if (m_currLevel < m_levels.size())
	{
		m_board = loadNewLevel(m_levels[m_currLevel]);
		return true;
	}
	return false;
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

void Controller::handelEvent(sf::Event& event, sf::Time& deltaTime, GameState& status) {
		//player won-> load next level
	if (m_player->won())
	{
		//if it last level- gameOver
		if (!this->loadNextLevel())
			status = GAMEOVER;
	}
	if (event.type == sf::Event::KeyPressed) {
		m_player->setDirection(eventToDirection(event));
	}
	if (event.type == sf::Event::KeyReleased) {
		m_player->setDirection(DEFAULT);
	}
	if (event.key.code == sf::Keyboard::P)
	{
		if (!this->loadNextLevel())
			status = GAMEOVER;
	}
	update(deltaTime);
	
}


void Controller::update(sf::Time& deltaTime)
{
	m_board.setDirection(deltaTime);
	m_board.collideHandler();//TODO: ask leonead if collide handler need to be member of board/controller
	m_board.update(deltaTime);
}


void Controller::screenDrawNDisplay(sf::RenderWindow& window)
{
	window.setSize((sf::Vector2u)m_board.getDimension());
	window.setView(sf::View(sf::FloatRect(0, 0, m_board.getDimension().x, 
		m_board.getDimension().y)));

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
	Board newBoard(level);
	m_player = &newBoard.getPlayer();

	return newBoard;
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