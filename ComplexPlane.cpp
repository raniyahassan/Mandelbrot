//#include<SFML/Graphics.hpp> //not sure if we actually need to include this because we're including the header file
#include "ComplexPlane.h"
//#include <cstdlib> //for abs value
#include <complex>
#include <iostream>
//#include <cmath> //we need the power function :(


using namespace std;
using namespace sf;


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

void ComplexPlane::setMouseLocation(Vector2f coord)
{
    m_mouseLocation = coord; 
}

void ComplexPlane::loadText(Text& text)
{
    stringstream str; 
    Vector2f center = m_view.getCenter(); 
    str << "Mandelbrot Set" << endl;
    str << "Center: (" << center.x << ", " << center.y << ")" << endl; 
    str << "Cursor: (" << m_mouseLocation.x << ", " << m_mouseLocation.y << ")" << endl;
    str << "Left Click to Zoom In" << endl; 
    str << "Right Click to Zoom Out" << endl; 

    string textTransfer; 
    str >> textTransfer; 

    text.setString(textTransfer); 
}

size_t ComplexPlane::countIterations(Vector2f coord)
{
    float a =  coord.x;
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

    else if (count < MAX_ITER && count > 44)
    {
        r = 156;
        g = 220;
        b = 254;
    }

    else if (count < 49 && count > 21)
    {
        r = 79;
        g = 124;
        b = 12; 
    }

    else if (count < 21)
    {
        r = 218;
        g = 112;
        b = 214;
    }
}

