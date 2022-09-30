#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <SFML/Graphics.hpp>

const unsigned int MAX_ITER = 64; // this will keep it from being too slow
const float BASE_WIDTH = 4.0;
const float BASE_HEIGHT = 4.0;
const float BASE_ZOOM = 0.5;

class ComplexPlane
{
public:
    ComplexPlane(float Aspect ratio); //constructor takes aspect ratio
    void zoomIn();
    void zoomOut();
    void setCenter(Vector2f coordinate);
    View getView();
    void setMouseLocation(Vector2f coordinate);
    void loadText(Text&); //don't fully understand this one?
    size_t countIterations(Vector2f coordinate); //positive unsigned int
    void iterationsToRGB(size_t count, Unit8& r, Unit8& g, Unit8& b); //what is Unit8? google it


private:
    Vector2f m_mouseLocation;
    View m_view;
    int m_ZoomCount;
    float m_aspectRatio;
};

#endif HEADERFILE_H