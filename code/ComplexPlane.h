#ifndef COMPLEXPLANE
#define COMPLEXPLANE

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <complex>

using namespace std;
using namespace sf; 

const unsigned int MAX_ITER = 64; // this will keep it from being too slow
const float BASE_WIDTH = 4.0;
const float BASE_HEIGHT = 4.0;
const float BASE_ZOOM = 0.5;

class ComplexPlane
{
private:
    Vector2f m_mouseLocation;
    View m_view;
    int m_zoomCount;
    float m_aspectRatio;

public:
    //ComplexPlane();
    //ComplexPlane(int, int, float); 
    ComplexPlane(float aspectRatio); //constructor takes aspect ratio
    void zoomIn();
    void zoomOut();
    void setCenter(Vector2f coordinate);
    View getView();
    void setMouseLocation(Vector2f coordinate);
    void loadText(Text& text); //don't fully understand this one?
    size_t countIterations(Vector2f coordinate); //positive unsigned int
    void iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b); 

};

#endif