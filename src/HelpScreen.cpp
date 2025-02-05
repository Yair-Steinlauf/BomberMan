#include "HelpScreen.h"

HelpScreen::HelpScreen()
{
	loadButtomsVector();
}

void HelpScreen::loadButtomsVector()
{
	std::string strHelp = "In this game you need to get a key and go to the door.\nyou can kill guard by put bomb with space button.\nbut you must run away from the bomb.\nYou have 3 life. but there is gift that give you life. \ngift for life, gift for freez guards, \ngift for extra time and gift for kill one guard. \nIf time over you start the level again.\n press escape for pause game. \ngood luck! and have fun ;)";
	m_sfText = sf::Text(strHelp, DataLoader::getP2Font(), 40);
	m_sfText.setPosition(sf::Vector2f(100, 100));
	m_Buttoms.push_back({BACK, createButtom("Return", sf::Vector2f(700, 0))});
}

void HelpScreen::eventHandler(sf::Event &event, sf::RenderWindow &window, GameState &status)
{
	if (event.type == sf::Event::Closed)
		window.close();
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			sf::Vector2f mousePosition = window.mapPixelToCoords(
				sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
			handleClick(mousePosition, status);
		}
	}
}

void HelpScreen::handleClick(sf::Vector2f &mousePos, GameState &status)
{

	for (const auto &buttom : m_Buttoms)
	{
		if (buttom.second.getGlobalBounds().contains(mousePos))
		{
			switch (buttom.first)
			{
			case BACK:
				status = RETURN;
				break;
			default:
				break;
			}
		}
	}
}
