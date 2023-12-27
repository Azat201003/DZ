#include <SFML/Graphics.hpp>
#include "snake.h"
#include "setting.h"

using namespace sf;
using namespace instrument;
Snake::Snake(int length, Position headPosition) {
	Snake::headPos = headPosition;
	Snake::length = length;
	for (int part = 0; part < length; part++) {
		Snake::body.push(headPosition);
	}
}
void Snake::move() {
	Position newHead;
	Position tempVelocity;
	vector<Keyboard::Key> tempKeys;

	tempVelocity.x = 0 * Snake::speed;
	tempVelocity.y = -1 * Snake::speed;
	tempKeys = { Keyboard::W, Keyboard::Up };
	Snake::directionalMovement(tempKeys, tempVelocity);

	tempVelocity.x = 0 * Snake::speed;
	tempVelocity.y = 1 * Snake::speed;
	tempKeys = { Keyboard::S, Keyboard::Down };
	Snake::directionalMovement(tempKeys, tempVelocity);

	tempVelocity.x = -1 * Snake::speed;
	tempVelocity.y = 0 * Snake::speed;
	tempKeys = { Keyboard::A, Keyboard::Left };
	Snake::directionalMovement(tempKeys, tempVelocity);

	tempVelocity.x = 1 * Snake::speed;
	tempVelocity.y = 0 * Snake::speed;
	tempKeys = { Keyboard::D, Keyboard::Right };
	Snake::directionalMovement(tempKeys, tempVelocity);

	newHead.x = Snake::headPos.x + Snake::velocity.x;
	newHead.y = Snake::headPos.y + Snake::velocity.y;
	Snake::headPos = newHead;

	if (Snake::body.back().x + 1 == (int)newHead.x ||
		Snake::body.back().y + 1 == (int)newHead.y ||
		Snake::body.back().x - 1 == (int)newHead.x ||
		Snake::body.back().y - 1 == (int)newHead.y) {
		Snake::body.push(newHead);
		Snake::body.pop();
	}
}

void Snake::directionalMovement(vector<Keyboard::Key> keys, Position aVelocity) {
	for (auto key:keys) {
		if (Keyboard::isKeyPressed(key)) {
			Snake::velocity = aVelocity;
		}
	}
}

Position Snake::getPos() {
	return Snake::headPos;
}

queue<Position> Snake::getBody() {
	return Snake::body;
}
