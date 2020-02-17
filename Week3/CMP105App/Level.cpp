#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	bounds = window->getSize();

	// initialise game objects
	ball.setFillColor(sf::Color::Red);
	ball.setRadius(50);
	ball.setPosition(100, 100);
	player.setFillColor(sf::Color::Blue);
	player.setOutlineColor(sf::Color::Black);
	player.setOutlineThickness(-2);
	player.setSize(sf::Vector2f(30, 30));
	player.setPosition(bounds.x/2, bounds.y/2);

	speed = 1000;
	right = false;
	bottom = false;

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W) && (player.getPosition().y > 0)) {
		//input->setKeyUp(sf::Keyboard::W);
		player.move(0, -speed*dt);
	}

	if (input->isKeyDown(sf::Keyboard::A) && ( player.getPosition().x > 0)) {
		//input->setKeyUp(sf::Keyboard::A);
		player.move(-speed*dt, 0);
	}

	if (input->isKeyDown(sf::Keyboard::S) && (player.getPosition().y < bounds.y - 30)) {
		//input->setKeyUp(sf::Keyboard::S);
		player.move(0, speed * dt);
	}

	if (input->isKeyDown(sf::Keyboard::D) && (player.getPosition().x < bounds.x - 30)) {
		//input->setKeyUp(sf::Keyboard::D);
		player.move(speed * dt, 0);
	}
}

// Update game objects
void Level::update(float dt)
{	
	bounds = window->getSize();
	if (ball.getPosition().x > bounds.x - 100) {
		right = true;
	}
	else if (ball.getPosition().x < 0) {
		right = false;
	}

	if (ball.getPosition().y > bounds.y - 100) {
		bottom = true;
	}
	else if (ball.getPosition().y < 0) {
		bottom = false;
	}

	if (right == false) {
		ball.move(speed * dt, 0);
	}
	else {
		ball.move(-speed * dt, 0);
	}

	if (bottom == false) {
		ball.move(0, speed * dt);
	}
	else {
		ball.move(0, -speed * dt);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball);
	window->draw(player);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}