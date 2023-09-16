// Member functions of the Vector3d class defined here

#include "Vector3d.h" // Vector3d class defined in this file

#include <iostream>


void Vector3d::print() const
{
    std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}