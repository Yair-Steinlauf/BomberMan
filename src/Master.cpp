#include "Master.h"



void Master::run()
{
	sf::RenderWindow window(sf::VideoMode(1, 1), "Init Window");
	m_menu.run(window);
	

	m_game.run(window);
}