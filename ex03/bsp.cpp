#include "Point.hpp"
#include "Fixed.hpp"

int	GetSign(Point const p1, Point const p2, Point const point)
{
	float ret = (p1.getX() - point.getX()) * (p2.getY() - point.getY()) \
				- (p2.getX() - point.getX()) * (p1.getY() - point.getY());
	if (ret == 0)
		return (2);
	return (ret > 0);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	int s1 = GetSign(a, b ,point);
	int s2 = GetSign(b, c ,point);
	int s3 = GetSign(c, a ,point);

	//std::cout << s1 << std::endl;
	//std::cout << s2 << std::endl;
	//std::cout << s3<< std::endl;

	return ((s1 == s2) && (s2 == s3) && (s3 == s1));
}