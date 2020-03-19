#include "Level.h"
#include "Ball.h"
#include "BallManager.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	BeachBall.setInput(in);

	// initialise game objects

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	FallBeachBallManager.spawn();
}

// Update game objects
void Level::update(float dt)
{
	FallBeachBallManager.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	FallBeachBallManager.render(window);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}