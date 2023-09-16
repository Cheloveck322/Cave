#include <iostream>

class Point
{
private:
    double m_x {};
    double m_y {};
    double m_z {};

public:
    Point(double x=0.0, double y=0.0, double z=0.0):
        m_x{x}, m_y{y}, m_z{z}
    {
    }

    // Convert a Point into its negative equivalent
    Point operator- () const;

    // Return true if the point is set at the origin
    bool operator! () const;

    Point operator+ () const;

    friend std::ostream& operator<<(std::ostream& out, const Point point);

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }
};

// Convert a Point into its negative equivalent
Point Point::operator- () const
{
    return { -m_x, -m_y, -m_z };
}

// Return true if the point is set at the origin, false otherwise
bool Point::operator! () const
{
    return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
}

Point Point::operator+ () const
{
    return *this;
}

std::ostream& operator<<(std::ostream& out, Point point)
{
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")\n";
    return out;
}

int main()
{
    double x{-123};
    Point point{+x, -1, -1}; // use default constructor to set to (0.0, 0.0, 0.0)

    if (!point)
        std::cout << "point is set at the origin.\n";
    else
        std::cout << "point is not set at the origin.\n";

    std::cout << point;

    return 0;
}