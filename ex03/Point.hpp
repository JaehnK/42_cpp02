#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"


class Point
{
	private:
		Fixed	x;
		Fixed	y;
	public:
		Point();
		Point(const Fixed &x, const Fixed &y);
		Point(const Point &rhs);
		~Point();
		Point&	operator = (const Point &rhs);

		float	getX(void) const;
		float	getY(void) const;
		void	printPointer(void);
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);


#endif