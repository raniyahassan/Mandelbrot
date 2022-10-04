#include <iostream>
#include <SFML/Graphics.hpp>
#include "ComplexPlane.h"

using namespace std;
using namespace sf; 



int main()
{
    double width = VideoMode::getDesktopMode().width;
    double height = VideoMode::getDesktopMode().height;
    double aspectRatio = height/width; 

    Event event;
    VideoMode VideoWindow(width, height); 
    RenderWindow window(VideoWindow,"Mandelbrot", Style::Default);
    RectangleShape rect(Vector2f{500 , 200}); 
    rect.setFillColor(Color(0,0,0,100)); 

    ComplexPlane complexPlane(aspectRatio);
    Font font; 
    if (!font.loadFromFile("font/VCR_OSD_MONO.ttf")) {cout << "Error loading font!" << endl; }
        
    Text text; 
    text.setFont(font);
    text.setLineSpacing(1.25);

    VertexArray Colors(Points, height*width);

    enum State { CALCULATING, DISPLAYING }; 
    State current = CALCULATING; 
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {window.close();}

            if (event.type == Event::Closed) {window.close();}

            if (event.type == Event::MouseButtonPressed)
            {
                Vector2f point = window.mapPixelToCoords(Mouse::getPosition(window), complexPlane.getView());

                if (event.mouseButton.button == Mouse::Right) {complexPlane.zoomOut();}
                if (event.mouseButton.button == Mouse::Left) {complexPlane.zoomIn();}

                complexPlane.setCenter(point);
                current = CALCULATING;
            }

            if (event.type == Event::MouseMoved)
            {
                Vector2i mousePosition = Vector2i(event.mouseMove.x, event.mouseMove.y); 
                Vector2f position = window.mapPixelToCoords(mousePosition, complexPlane.getView());
                
                complexPlane.setMouseLocation(position);
            }

        }

        if (current == CALCULATING)
        {
            for (int j = 0; j < width; j++)
            {
                for (int i = 0; i < height; i++)
                {
                    Vector2f position = Vector2f((float)j, (float)i);
                    Colors[j + i * width].position = position;

                    Vector2i intPosition = {j,i};

                    Vector2f pixelLocation = window.mapPixelToCoords(intPosition, complexPlane.getView());
                    size_t iterations = complexPlane.countIterations(pixelLocation); 

                    Uint8 r, g, b;
                    complexPlane.iterationsToRGB(iterations, r, g, b); 
                    
                    Colors[j + i * width].color = {r,g,b}; 

                }

                complexPlane.loadText(text); 
                current = DISPLAYING;
            }
        }
    

        if (current == DISPLAYING)
        {
            window.clear();
            window.draw(Colors);
            window.draw(rect); 
            window.draw(text);

            window.display();  
        }
    }

    return 0; 
}
