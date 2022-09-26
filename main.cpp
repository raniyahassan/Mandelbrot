#include <iostream>
#include <SFML/Graphics.hpp>
#include <ComplexPlane.h>

using namespace std;
using namespace sf;

int main()

{
    int width = sf::VideoMode::getDesktopMode().width;
    int height = sf::VideoMode::getDesktopMode().height;
    int aspectRatio = width/height; 

    VideoMode VideoWindow(width, height); 
    RenderWindow window(VideoWindow,"Mandelbrot", Style::Default);






    return 0; 
}
