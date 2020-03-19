#include "FallBallManager.h"

FallBallManager::FallBallManager()
{
	spawnPoint = sf::Vector2f(rand() % 1200 - 1, -100);
	texture.loadFromFile("gfx/Beach_Ball.png");
	for (int i = 0; i < 21; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));

	}
}

FallBallManager::~FallBallManager()
{

}

void FallBallManager::update(float dt)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			balls[i].update(dt);
		}
		deathCheck();
	}
}

void FallBallManager::spawn()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(0, rand() % 60 - 10);
			balls[i].setPosition(spawnPoint);
			return;
		}
	}
}

void FallBallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().y > 675)
			{
				balls[i].setAlive(false);
			}
		}
	}
}

void FallBallManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
}