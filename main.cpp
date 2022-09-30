#include <iostream>
#include <SFML/Graphics.hpp>
#include <ComplexPlane.h>

using namespace std;
using namespace sf;

int width = sf::VideoMode::getDesktopMode().width;
int height = sf::VideoMode::getDesktopMode().height;
int aspectRatio = height/width; 

VideoMode VideoWindow(width, height); 
RenderWindow window(VideoWindow,"Mandelbrot", Style::Default);

ComplexPlane complexPlane();
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

            }

            if (event.type == Event::MouseMoved)
            {

            }

            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }
        }
    }





    return 0; 
}
