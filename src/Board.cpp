#include "Board.h"

Board::Board()
{
}

Board::Board(std::ifstream& file) {
	loadFromFile(file);
}

void Board::draw(sf::RenderWindow& window)
{
	for (auto& object : m_board)
	{
		object->draw(window);
	}
}

void Board::setScale(float scale)
{
	for (auto& object : m_board)
	{
		//object->setScale(scale);
	}
}
void Board::setDirection(const sf::Time& deltaTime)
{
	for (const auto& object : m_board)
	{
		object->act(deltaTime);
	}
}
void Board::collideHandler()
{
	for (auto& object : m_board)
	{
		for (auto& other : m_board)
		{
			if (object == other) continue;
			if (object->intersect(*other))
			{
					object->collide(*other);
				if ((typeid (*other) == typeid(Player) && typeid(*object) == typeid(Guard)))
				{
					tryAgain();
					return;
				}
			}
		}
	}
}
void Board::tryAgain()
{
	for (auto& object : m_board)
	{
		if (MovingObject* current = dynamic_cast<MovingObject*>(object.get()))
		{
			current->moveToStartPos();
		}
	}
}
void Board::update(const sf::Time& deltaTime)
{
	for (auto& object : m_board)
	{
		object->update(deltaTime);
	}
}

Player& Board::getPlayer()
{
	for (const auto& object : m_board)
	{
		if (auto* player = dynamic_cast<Player*>(object.get()))
		{
			return *player;
		}
	}
}

void Board::addObject(ObjectType type, sf::Vector2f location)
{
	switch (type)
	{
	case PLAYER:
		m_board.push_back(std::make_unique <Player>(location));
		break;
	case GUARD:
		m_board.push_back(std::make_unique <Guard>(location));
		break;
	case DOOR: 
		m_board.push_back(std::make_unique<Door>(location));
		break;
	case STONE:
		m_board.push_back(std::make_unique<Stone>(location));
		break;
	case WALL:
		m_board.push_back(std::make_unique<Wall>(location));
		break;
	}
}

std::vector<std::string> Board::fileTo2DString(std::ifstream& file)
{
	std::string line;
	std::vector<std::string> board;
	while (std::getline(file, line)) {
		board.push_back(line);
	}
	file.close();
	return board;
}

void Board::loadFromFile(std::ifstream& file)
{
	std::vector<std::string> lines = fileTo2DString(file);
	m_dimension = sf::Vector2f(lines[0].length() * ImageDimension.x, lines.size() * ImageDimension.y);
	for (int rowIndex = 0; rowIndex < lines.size(); rowIndex++)
	{
		for (int colIndex = 0; colIndex < lines[rowIndex].length(); colIndex++)
		{
			auto location = rowColToLocation(rowIndex, colIndex);
			addObject(ObjectType(lines[rowIndex][colIndex]), location);
		}
	}
	float scaler =1/ std::min(m_dimension.x/WINDOW_WIDTH, m_dimension.y / WINDOW_HIGTH);
	setScale(scaler);
}

sf::Vector2f Board::rowColToLocation(unsigned int row, unsigned int col) const
{
	return sf::Vector2f(col * ImageDimension.x, row * ImageDimension.y);
}

sf::Vector2f Board::getDimension() const
{
	return m_dimension;
}
