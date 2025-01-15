#include "Board.h"

Board::Board()
{
	//addObject(PLAYER, sf::Vector2f(50, 200));
}

Board::Board(std::ifstream& file) {
	loadFromFile(file);
}

void Board::draw(sf::RenderWindow& window)
{
	m_player.draw(window);
	for (auto& object : m_board)
	{
		object->draw(window);
	}
}

void Board::update()
{
	for (auto& object : m_board)
	{
		if (auto movingObject = dynamic_cast<MovingObject*>(object.get()))
		{
			movingObject->move();
		}
	}
}

Player& Board::getPlayer()
{
	return m_player;
}

void Board::addObject(ObjectType type, sf::Vector2f location)
{
	switch (type)
	{
	case PLAYER:
		m_player = Player(location);
		break;
	case GUARD:
		m_board.push_back(std::make_unique <Guard>(location));

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
	for (int rowIndex = 0; rowIndex < lines.size(); rowIndex++)
	{
		for (int colIndex = 0; colIndex < lines[rowIndex].length(); colIndex++)
		{
			auto location = rowColToLocation(rowIndex, colIndex);
			addObject(ObjectType(lines[rowIndex][colIndex]), location);
		}
	}
}

sf::Vector2f Board::rowColToLocation(unsigned int row, unsigned int col) const
{
	return sf::Vector2f(col * ImageDimension.x, row * ImageDimension.y);
}