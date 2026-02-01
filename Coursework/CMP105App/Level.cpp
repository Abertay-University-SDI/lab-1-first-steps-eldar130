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
	//snake movement from key board
	if (m_input.isKeyDown(sf::Keyboard::Scancode::D)){
		m_direction = Direction::RIGHT;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::A)) {
		m_direction = Direction::LEFT;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::W)) {
		m_direction = Direction::UP;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::S)) {
		m_direction = Direction::DOWN;
	}
}

// Update game objects
void Level::update(float dt) 
{
	//continues snake movement
	switch (m_direction) {
	case Direction::RIGHT:
		m_player.move({ m_speed * dt, 0.f });
		break;

	case Direction::LEFT:
		m_player.move({ -m_speed * dt, 0.f });
		break;

	case Direction::UP:
		m_player.move({ 0.f, -m_speed * dt });
		break;
	
	case Direction::DOWN:
		m_player.move({ 0.f, m_speed * dt });
		break;
	}

	
	sf::Vector2u window_size = m_window.getSize();
	sf::Vector2f player_pos = m_player.getPosition();
	//reset if collided with wall
	if (player_pos.x < 0 || player_pos.y < 0 ||
		player_pos.x - 2*m_player.getRadius() > window_size.x ||
		player_pos.x - 2*m_player.getRadius() > window_size.y) {
		m_player.setPosition({ 300.f, 300.f });
	}
}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_player);
	endDraw();
}

