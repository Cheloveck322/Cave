#ifndef POINT2D_H
#define POINT2D_H

class Point2d
{
private:
    double m_x{};
    double m_y{};
public:
    Point2d(double x, double y);
    Point2d();
    
    void print();
};


#endif 