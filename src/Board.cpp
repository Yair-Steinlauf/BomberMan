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
void Board::act(const sf::Time& deltaTime)
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
			}
		}
	}
}
Player& Board::getPlayer()
{
	return *m_player;
}
void Board::tryAgain()
{
	for (auto& object : m_board)
	{
		object->moveToStartPos();
	}
}
unsigned int Board::getNumOfGuards()
{
	return m_numOfGuards;
}
void Board::update(const sf::Time& deltaTime)
{
	for (auto& object : m_board)
	{
		object->update(deltaTime);
	}

	std::erase_if(m_board, [](const std::unique_ptr<GameObject>& current) {
		return !current->isActive();
		});
}






void Board::addObject(ObjectType type, sf::Vector2f location)
{
	auto scale = scalerCalc();
	switch (type)
	{
	case PLAYER:
		m_board.push_back(std::make_unique<Player>(location, scale));
		m_player = dynamic_cast<Player*>(m_board.back().get());
		break;
	case GUARD:
		m_numOfGuards++;
		m_board.push_back(std::make_unique<Guard>(location, scale));
		break;
	case DOOR:
		m_board.push_back(std::make_unique<Door>(location, scale));
		break;
	case STONE:
		m_board.push_back(std::make_unique<Stone>(location, scale));
		break;
	case WALL:
		m_board.push_back(std::make_unique<Wall>(location, scale));
		break;
	case LIFEGIFT:
		m_board.push_back(std::make_unique<LifeGift>(location, scale));
		break;
	case KEY:
		m_board.push_back(std::make_unique<Key>(location, scale));
		break;
	case BOMB:		
		m_board.push_back(std::make_unique<Bomb>(location, scale));		
		break;
	case GUARDGIFT:
		m_board.push_back(std::make_unique<GuardGift>(location, scale));
		break;
	case FREEZGIFT:
		m_board.push_back(std::make_unique<FreezGift>(location, scale));
		break;
	case EXTRATIMEGIFT:
		m_board.push_back(std::make_unique<ExtraTimeGift>(location, scale));
		break;
	}
	//m_board.back().get()->setScale(scalerCalc());
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
	m_dimension = sf::Vector2f(lines[0].length(), lines.size());
	for (int rowIndex = 0; rowIndex < lines.size(); rowIndex++)
	{
		for (int colIndex = 0; colIndex < lines[rowIndex].length(); colIndex++)
		{
			auto location = rowColToLocation(rowIndex, colIndex);
			addObject(ObjectType(lines[rowIndex][colIndex]), location);
		}
	}
}
float Board::scalerCalc()const
{
	float factorX = (WINDOW_WIDTH / m_dimension.x) / ImageDimension.x;
	float factorY = (WINDOW_HIGTH / m_dimension.y) / ImageDimension.y;
	return std::min(factorX, factorY);
}

sf::Vector2f Board::rowColToLocation(unsigned int row, unsigned int col) const
{
	auto scaler = scalerCalc();
	return sf::Vector2f(col * ImageDimension.x *scaler, row * ImageDimension.y*scaler);
}

sf::Vector2f Board::getDimension() const
{
	//sf::Vector2f boardDim()
	return m_dimension;
}
