#include <SFML/Graphics.hpp>
#include "setting.h"
#include "snake.h"
#include "draw.h"
#include "iostream"

using namespace sf;
using namespace setting;
int main()
{
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "snake");
    CircleShape headShape(TILE_SIZE/2, 10);
    CircleShape bodyShape(TILE_SIZE/2, 10);
    Snake snake(FIRST_LENGTH, FIRST_HEAD_POS);
    Draw draw;

    headShape.setFillColor(Color::Green);
    bodyShape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        snake.move();
        window.clear(Color::Blue); 
        draw.drawSnake(snake, &window, &headShape, &bodyShape);
        window.display();
    }

    return 0;
}