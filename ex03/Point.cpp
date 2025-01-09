#include "Fixed.hpp"
#include "Point.hpp"

Point::Point()
{
	this->x = Fixed(0);
	this->y = Fixed(0);
}

Point::Point(const Fixed &x_, const Fixed &y_)
{
	this->x = x_;
	this->y = y_;
}

Point::Point(const Point &rhs)
{
	*this = rhs;
}

Point::~Point()
{

}

Point&	Point::operator = (const Point &rhs)
{
	if (this != &rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
	}
	return *this;
}

float	Point::getX() const
{
	return (x.toFloat());
}

float	Point::getY() const
{
	return (y.toFloat());
}

void	Point::printPointer(void)
{
	std::cout << "x: " << x << " ";
	std::cout << "y: " << y << std::endl;
}


