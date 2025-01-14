#include "Board.h"

Board::Board(std::string& fileName)
{
	auto level = std::ifstream(fileName);
	auto board = fileToString(level);
	m_dimension.x = ImageDimension.x * board[0].length();
	m_dimension.y = ImageDimension.y * board.size();
	sf::Vector2f location;
	for (int rowIndex = 0; rowIndex < board.size(); rowIndex++)
	{
		for (int colIndex = 0; colIndex < board[0].length(); colIndex++)
		{
			//if (board[rowIndex][colIndex] == PLAYER)
			//{
			//	m_player = Player(location);
			//}
			if (board[rowIndex][colIndex] != ' ')
			{
				location = rowColToLocation(rowIndex, colIndex);
				addObject(charToObjectType(board[rowIndex][colIndex]), location);
			}
		}
	}
}

void Board::draw(sf::RenderWindow& window) const
{
	for (const auto& object : m_objects)
	{
		object->draw(window);
	}
}

void Board::update(const sf::Event& event, const sf::Time& deltaTime)
{
	for (const auto& object : m_objects)
	{
		object->move(deltaTime, event);
	}
}


ObjectType Board::charToObjectType(const char& a) const
{
	return ObjectType(a);
}

std::vector<std::string> Board::fileToString(std::ifstream& file)const
{
	std::string line;
	std::vector<std::string> board;
	while (std::getline(file, line)) {
		board.push_back(line);
	}
	return board;
}

sf::Vector2f Board::getDimension() const
{
	return m_dimension;
}

sf::Vector2f Board::rowColToLocation(unsigned int row, unsigned int col) const
{
	return sf::Vector2f(col * ImageDimension.x, row * ImageDimension.y);
}

void Board::addObject(ObjectType type, sf::Vector2f location)
{
	std::unique_ptr<GameObject> object;
	switch (type)
	{
	case PLAYER:
		object = std::make_unique<Player>(location);
		break;
	case GUARD:
		object = std::make_unique<Guard>(location);
		break;
		//TODO: add case for other objects
	//case DOOR:
	//	object = std::make_unique<Door>(location);
	//	break;
	//case WALL:
	//	object = std::make_unique<Player>(location);
	//	break;
	//case STONE:
	//	object = std::make_unique<Player>(location);
	//	break;
	//case GIFT:
	//	object = std::make_unique<Player>(location);
	//	break;
	default:
		break;
	}
	m_objects.push_back(object);

}
