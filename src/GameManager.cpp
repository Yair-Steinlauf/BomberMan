#include "GameManager.h"
const sf::Vector2f PADDING(0,30);
GameManagerState GameManager::m_state = Playing;

GameManager::GameManager()
	:m_levels(getLevels()), m_currLevel(0)
{
	m_state = Playing;
	loadNextLevel();
}

void GameManager::restartGame()
{
	m_currLevel = 0;	
	loadNextLevel();
}

bool GameManager::loadNextLevel()
{	
	if (m_currLevel < m_levels.size())
	{
		m_scoreDetail.clear();							
		m_board = loadNewLevel(m_levels[m_currLevel]);
		m_player = &m_board.getPlayer();		

		m_currLevel++;

		return true;
	}
	return false;
}

std::vector<std::string> GameManager::getLevels()
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

void GameManager::eventHandler(sf::Event& event, GameState& status) {
	//player won-> load next level
	if (m_player->won())
	{
		int score = m_player->getScore();
		score += 25; // for finish level
		score += 3 * m_board.getCountGuards(); // for every guards in the game
		if (!this->loadNextLevel()) { //if it last level- gameOver	
			SoundHandle::getInstance().playSound(S_VICTORY);
			status = GAMEOVER;				
			//restartGame();
		}		
		else {
			SoundHandle::getInstance().playSound(S_LEVEL_UP);
		}
		
		m_player->setScore(score);
	}
	if (m_player->getLife() <= 0 || m_timer <= sf::seconds(0))
	{
		//restartGame();				
		SoundHandle::getInstance().playSound(S_DEFEAT);
		status = GAMEOVER;
	}
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Space) {
			m_board.addObject(BOMB, m_player->getLocation());
		}
		else {
			m_player->setDirection(eventToDirection(event)); // Handle other key presses
		}
	}
	else if (event.type == sf::Event::KeyReleased) {
		if (event.key.code != sf::Keyboard::Space) { // Only reset direction if not space
			m_player->setDirection(DEFAULT);
		}
	}
	if (event.key.code == sf::Keyboard::Escape)

		status = PAUSE;
	if (event.key.code == sf::Keyboard::P)
	{
		if (!this->loadNextLevel())//TODO: for debug, delete
			status = GAMEOVER;
	}

}

int GameManager::getPlayerScore() const
{
	return m_player->getScore();
}

bool GameManager::isWon()
{
	return m_player->won();
}




void GameManager::update(sf::Time& deltaTime)
{
	//if (status == PLAYING) {
	//	//std::cout << m_timer.asSeconds() << std::endl;
	//	
	//	m_board.act(deltaTime);
	//	m_board.collideHandler();//TODO: ask leonead if collide handler need to be member of board/controller
	//	if (m_player->gotExtraTimeGift()) {
	//		m_timer += sf::seconds(15);
	//	}
	//	if (m_player->gotGuardGift()) {
	//		m_board.eraseGuard();
	//	}
	//	bool isFreezGuards = m_player->gotFreezGift(deltaTime) > sf::seconds(0);
	//	//m_board.update(deltaTime, isFreezGuards);
	//	
	//	m_timer -= deltaTime;
	//}
	m_board.act(deltaTime);
	m_board.collideHandler();//TODO: ask leonead if collide handler need to be member of board/controller
	m_board.update(deltaTime );
	//setState(Playing);
	m_timer -= deltaTime;
}

void GameManager::drawNDisplay(sf::RenderWindow& window , sf::Time& deltaTime)
{
	update(deltaTime);
	//TODO: leonid ask how to do good
	window.setSize((sf::Vector2u)m_board.getDimension() + (sf::Vector2u)scoreDetailsSize);
	window.setView(sf::View(sf::FloatRect(0, 0, m_board.getDimension().x,
		m_board.getDimension().y + scoreDetailsSize.y)));
	
	m_scoreDetail[0].setString("Player life: " + std::to_string(m_player->getLife()));
	m_scoreDetail[1].setString("Game timer : " + std::to_string(m_timer.asSeconds()));
	m_scoreDetail[2].setString("Player points : " + std::to_string(m_player->getScore()));
	window.clear();
	
	for (const auto& detail : m_scoreDetail)
	{
		window.draw(detail);
	}
	m_board.draw(window);
	window.display();
}

sf::Text GameManager::createScoreText(std::string text, sf::Vector2f location)
{
	sf::Text sfText(text, DataLoader::getP2Font(), 40);
	sfText.setPosition(location);
	return sfText;
}

Board GameManager::loadNewLevel(const std::string& levelName)
{
	auto level = std::ifstream(levelName);
	if (!level.is_open())
	{
		//TODO:  mabye offer to create new level via editor?
	}
	Board newBoard(level);
	sf::Vector2f startScoreText(0, newBoard.getDimension().y);
	m_scoreDetail.push_back(createScoreText("Player life:", startScoreText + PADDING));
	m_scoreDetail.push_back(createScoreText("Game timer :", startScoreText + PADDING + PADDING));
	m_scoreDetail.push_back(createScoreText("Player points :", startScoreText));
	m_timer = sf::seconds(30);
	return newBoard;
}

Direction GameManager::eventToDirection(sf::Event& event)
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

