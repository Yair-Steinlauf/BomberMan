#include "GameManager.h"
const sf::Vector2f PADDING(0,30);


//----------static init-------------------
bool GameManager::m_removeGuardGift = false;
bool GameManager::m_guardFreeze = false;
bool GameManager::m_guardBombed = false;



GameManager::GameManager()
	:m_levels(getLevels()), m_currLevel(0)
{
	loadNextLevel();
}

void GameManager::restartLevel()
{
	m_currLevel--;	
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
void GameManager::updatePlayer(sf::Event& event)
{

	//if (event.type == sf::Event::KeyPressed) {
		//if(event.key.code != sf::Keyboard::Space)
	if (event.type == sf::Event::KeyPressed &&
		(event.key.code == sf::Keyboard::Up ||
			event.key.code == sf::Keyboard::Down ||
			event.key.code == sf::Keyboard::Right ||
			event.key.code == sf::Keyboard::Left))
		m_player->setDirection(eventToDirection(event)); // Handle other key presses		
	//}

}
void GameManager::eventHandler(sf::Event& event, GameState& status) {

	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Space) {			
				sf::Vector2f bombUp(m_player->getTopLeft().x, m_player->getTopLeft().y + m_player->getSize().y);
				sf::Vector2f bombDown(m_player->getTopLeft().x, m_player->getTopLeft().y - m_player->getSize().y);
				sf::Vector2f bombRight(m_player->getTopLeft().x + m_player->getSize().x, m_player->getTopLeft().y);
				sf::Vector2f bombLeft(m_player->getTopLeft().x - m_player->getSize().x, m_player->getTopLeft().y);
				m_board.addObject(BOMB, bombUp, false); // bomb up						
				m_board.addObject(BOMB, bombDown, false);	// bomb down					
				m_board.addObject(BOMB, bombRight, false);	// bomb right					
				m_board.addObject(BOMB, bombLeft , false);	// bomb left					
				m_board.addObject(BOMB, m_player->getLocation());	// cur location		
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






void GameManager::update(sf::Time& deltaTime, GameState& status)
{
	
	if (m_player->won())
	{
		int score = m_player->getScore();
		score += 25; // for finish level
		score += 3 * m_board.getNumOfGuards(); // for every guards in the game
		if (!this->loadNextLevel()) { //if it last level- gameOver	
			SoundHandle::getInstance().playSound(S_VICTORY);
			status = GAMEOVER;
		}
		else {
			SoundHandle::getInstance().playSound(S_LEVEL_UP);
		}
		m_player->setScore(score);
		m_startLevelScore = score;
	}
	if (m_player->getLife() <= 0) {		
		SoundHandle::getInstance().playSound(S_DEFEAT);
		status = GAMEOVER;
	}
	if (m_timer <= sf::seconds(0))
	{
		restartLevel();
		m_player->setScore(m_startLevelScore);
	}
	
	if (m_player->gotExtraTimeGift()) {
		m_timer += sf::seconds(15);
	}
	if (m_player->gotCollidWithGuard())
	{
		m_board.tryAgain();
	}
	m_guardFreeze = m_player->gotFreezGift(deltaTime) > sf::seconds(0);
	if (m_player->gotGuardGift()) {
		m_removeGuardGift = true;
	}
	
	if (m_guardBombed) {
		m_player->addScore(5);
		m_guardBombed = false;
	}
	m_board.act(deltaTime);
	m_board.collideHandler();//TODO: ask leonead if collide handler need to be member of board/controller

	m_board.update(deltaTime);
	
	//setState(Playing);
	m_timer -= deltaTime;

}

void GameManager::drawNDisplay(sf::RenderWindow& window , sf::Time& deltaTime, GameState& status)
{
	update(deltaTime, status);

	int seconds = static_cast<int>(m_timer.asSeconds());
	m_scoreDetail[0].setString("Player life: " + std::to_string(m_player->getLife()));
	m_scoreDetail[1].setString("Game timer : " + std::to_string(seconds));
	m_scoreDetail[2].setString("Player points: " + std::to_string(m_player->getScore()));
	m_scoreDetail[3].setString("Your in level: " + std::to_string(m_currLevel));
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
	sf::Vector2f startScoreTextLeft(0, WINDOW_HIGTH);	
	sf::Vector2f startScoreTextRight(500, WINDOW_HIGTH);	
	m_scoreDetail.push_back(createScoreText("Player life:", startScoreTextLeft));
	m_scoreDetail.push_back(createScoreText("Game timer:", startScoreTextLeft + PADDING));
	m_scoreDetail.push_back(createScoreText("Player points:", startScoreTextRight));
	m_scoreDetail.push_back(createScoreText("Level:", startScoreTextRight + PADDING));
	m_timer = sf::seconds(90);
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

