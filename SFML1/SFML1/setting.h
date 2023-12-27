#pragma once
namespace instrument {
	static class Position {
	public:
		Position(int aX, int aY);
		Position();
		float x = 0, y = 0;
	};
}
namespace setting {
	static int WIDTH			= 480;
	static int HEIGHT			= 360;
	static int FIRST_LENGTH		= 5;
	static int TILE_SIZE		= 30;
	static instrument::Position FIRST_HEAD_POS(WIDTH / 2 / TILE_SIZE, HEIGHT / 2 / TILE_SIZE);
}