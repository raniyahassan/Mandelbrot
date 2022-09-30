#include<SFML/Graphics.hpp> //not sure if we actually need to include this because we're including the header file
#include "ComplexPlane.h"
#include <cstdlib> //for abs value
#include <complex>
#include <iostream>
#include <cmath> //we need the power function :(


using namespace std;
using namespace sf;


int main()
{
    ComplexPlane::ComplexPlane (float aspectRatio)
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
}