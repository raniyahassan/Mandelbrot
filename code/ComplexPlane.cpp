#include "ComplexPlane.h"
#include <cmath>
#include <complex>
#include <sstream>


ComplexPlane::ComplexPlane(float aspectRatio)
{
    m_aspectRatio = aspectRatio;
    m_view.setSize(BASE_WIDTH, -BASE_HEIGHT * m_aspectRatio);
    m_view.setCenter(0.0, 0.0);
    m_zoomCount = 0;
}

void ComplexPlane::zoomIn()
{
    m_zoomCount++;
    double x = BASE_WIDTH * (pow(BASE_ZOOM, m_zoomCount));
    double y = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);
    m_view.setSize(x, y);
}

void ComplexPlane::zoomOut()
{
    m_zoomCount--;
    double x = BASE_WIDTH * (pow(BASE_ZOOM, m_zoomCount));
    double y = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);
    m_view.setSize(x, y);
}

void ComplexPlane::setCenter(Vector2f coord)
{
    m_view.setCenter(coord); 
}

View ComplexPlane::getView()
{
    return m_view;
}

void ComplexPlane::setMouseLocation(Vector2f coord)
{
    m_mouseLocation = coord; 
}

void ComplexPlane::loadText(Text& text)
{
    text.setCharacterSize(22); 
    text.setFillColor(Color::White);
    text.setString(""); 
    text.setPosition(0,0);

    stringstream centerX1, centerY1, mouseX1, mouseY1; 
    float centerX, centerY, mouseX, mouseY;
    centerX1 << m_view.getCenter().x;
    centerX1 >> centerX;
    centerY1 << m_view.getCenter().y;
    centerY1 >> centerY;
    mouseX1 << m_mouseLocation.x;
    mouseX1 >> mouseX;
    mouseY1 << m_mouseLocation.y;
    mouseY1 >> mouseY;
    
    text.setString("Mandelbrot Set\nCenter: (" + to_string(centerX) + "," + to_string(centerY) + ")\n" + "Cursor: " + "(" + to_string(mouseX) + "," + to_string(mouseY) + ")\n" + "Left Click to Zoom In\nRight Click to Zoom Out\nZoom Count: " + to_string(m_zoomCount));
}


size_t ComplexPlane::countIterations(Vector2f coord)
{
    float a = coord.x;
    float b = coord.y;

    complex<double>c(a,b); 
    complex<double>z(0.0);

    for (size_t i = 0; i < MAX_ITER; i++)
    {
        z = (z*z) + c;
        if (abs(z) > 2.0)
        {
            return i; 
        }
    }
    return MAX_ITER; 
}

void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b)
{
   if (count == MAX_ITER)
    {
        r = 0;
        g = 0;
        b = 0;
    }

    else if (count > 48)
    {
        r = 222-(count%16)*5;
        g = 179-(count%16)*5;
        b = 237;
    }

    else if (count > 33)
    {
        r = 222-(count%16)*5;
        g = 132-(count%16)*5;
        b = 123;
    }

    else if (count > 16)
    {
        r = 185-(count%16)*5;
        g = 92-(count%16)*5;
        b = 80;
    }

    else 
    { 
        r = 255-(count%20)*5;
        g = 192-(count % 20)*10;
        b = 203-(count%16)*10;
    } 

}

