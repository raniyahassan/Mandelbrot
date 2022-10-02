#include <iostream>
#include <SFML/Graphics.hpp>
#include "ComplexPlane.h"

using namespace std;
using namespace sf;

int width = sf::VideoMode::getDesktopMode().width;
int height = sf::VideoMode::getDesktopMode().height;
int aspectRatio = height/width; 

VideoMode VideoWindow(width, height); 
RenderWindow window(VideoWindow,"Mandelbrot", Style::Default);

ComplexPlane complexPlane(aspectRatio);
Font font; 
Text text; 
VertexArray Colors(Points, height*width);

enum State { CALCULATING, DISPLAYING }; 
State current = CALCULATING; 

Event event; 

int main()
{
    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        while (window.pollEvent(event))
        {
            if (event.type == Event::MouseButtonPressed)
            {
                Vector2f point = window.mapPixelToCoords(Mouse::getPosition(window), complexPlane.getView());

                if (event.mouseButton.button == Mouse::Right)
                {
                    complexPlane.zoomOut();
                    complexPlane.setCenter(point);
                }

                if (event.mouseButton.button == Mouse::Left)
                {
                    complexPlane.zoomIn();
                    complexPlane.setCenter(point);
                }

                current = CALCULATING;

            }

            if (event.type == Event::MouseMoved)
            {
                Vector2f point = window.mapPixelToCoords(Mouse::getPosition(window), complexPlane.getView());
                complexPlane.setMouseLocation(point);
            }

            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }
        }

        if (current == CALCULATING)
        {
            for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < height; j++)
                {
                    Colors[j + i * width].position = Vector2f((float)i, (float)j);
                }
            }
        }
    }





    return 0; 
}
