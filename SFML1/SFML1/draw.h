#pragma once
#include <queue>
#include <SFML/Graphics.hpp>
#include "setting.h"
#include "snake.h"
using namespace std;
using namespace instrument;
using namespace sf;
class Draw
{
public:
	void drawSnake(Snake &snake, RenderWindow* window, Shape* headShape, Shape* bodyShape);
};

