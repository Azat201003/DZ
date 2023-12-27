#include "draw.h"
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

using namespace std;
using namespace instrument;
using namespace setting;
using namespace sf;
void Draw::drawSnake(Snake &snake, RenderWindow *window, Shape *headShape, Shape *bodyShape)
{
	queue<Position> snakeBody = snake.getBody();

	headShape->setPosition((int)snakeBody.back().x * TILE_SIZE,
						   (int)snakeBody.back().y * TILE_SIZE);
	window->draw(*headShape);

	for (int i = 0; i < snake.getBody().size() - 1; i++) {
		bodyShape->setPosition((int)snakeBody.front().x * TILE_SIZE,
							   (int)snakeBody.front().y * TILE_SIZE);
		snakeBody.pop();
		window->draw(*bodyShape);
	}
}
