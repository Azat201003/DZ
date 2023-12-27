#include <SFML/Graphics.hpp>
#include "setting.h"
#include <queue>
#include <vector>

using namespace std;
using namespace sf;
using namespace instrument;
#pragma once
class Snake
{
public:
	Snake(int length, Position headPosition);
	void move();
	void directionalMovement(vector<Keyboard::Key> keys, Position aVelocity);
	Position getPos();
	queue<Position> getBody();
private:
	Position headPos;
	queue<Position> body;
	int length;
	Position velocity;
	float speed = 0.001f;
};

