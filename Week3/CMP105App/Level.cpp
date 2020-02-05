#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ball.setFillColor(sf::Color::Red);
	ball.setRadius(50);
	ball.setPosition(100, 100);
	speed = 10000;
	right = false;
	bottom = false;

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

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