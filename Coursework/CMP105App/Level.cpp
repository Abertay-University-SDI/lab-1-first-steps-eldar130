#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	// initialise game objects
	m_player.setRadius(15.f);
	m_player.setFillColor(sf::Color::Green);
	m_player.setPosition({ 300.f, 300.f });

}

// handle user input
void Level::handleInput(float dt)
{
	if (m_input.isLeftMousePressed())
	{
		std::cout << "left mouse pressed" << std::endl;
	}

}

// Update game objects
void Level::update(float dt)
{
}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_player);
	endDraw();
}

