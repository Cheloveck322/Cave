#include "Point2d.h"
#include <iostream>

Point2d::Point2d(double x = 0.0, double y = 0.0):
    m_x{x}, m_y{y}
{};

Point2d::Point2d():
    m_x{0}, m_y{0}
{};

void Point2d::print()
{
    std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
}