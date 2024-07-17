#include <iostream>
#include <vector>
#include <algorithm>

class Point
{
private:
	int m_x{};
	int m_y{};

public:
	Point(int x, int y)
		: m_x{ x }, m_y{ y }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.m_x << ", " << p.m_y << ')';
	}
};

class Shape 
{
public:
    virtual std::ostream& print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Shape& shape)
    {
        return shape.print(out);
    }

    virtual ~Shape() = default;
};

class Triangle: public Shape
{
private:
    Point m_a;
    Point m_b;
    Point m_c;

public:
    Triangle(const Point& a, const Point& b, const Point& c)
        : m_a { a }, m_b { b }, m_c { c }
    {
    }

    std::ostream& print(std::ostream& out) const override
    {
        return out << "Triangle(" << m_a << ", " << m_b << ", " << m_c << ')';
    }

    virtual ~Triangle() = default;
};

class Circle: public Shape
{
private:
    Point m_centre;
    int m_radius;

public:
    Circle(const Point& centre, int radius) 
        : m_centre { centre }, m_radius { radius }
    {
    }

    std::ostream& print(std::ostream& out) const override
    {
        return out << "Circle(" << m_centre << ", radius " << m_radius << ')';
    } 

    int getRadius() const
    {
        return m_radius;
    }

    virtual ~Circle() = default;
};

int getLargestRadius(const std::vector<Shape*>& v)
{
    int largestRadius{};
    for (const auto element : v)
    {
        if (auto* casted { dynamic_cast<Circle*>(element) })
        {
            largestRadius = std::max(largestRadius, casted->getRadius());
        }   
    }
    return largestRadius;
}

int main()
{
	std::vector<Shape*> v{
	  new Circle{Point{ 1, 2 }, 7},
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3}
	};

	// print each shape in vector v on its own line here
    for ( const auto* element: v)
        std::cout << *element << '\n';

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here
    for (const auto* element: v)
        delete element;

	return 0;
}