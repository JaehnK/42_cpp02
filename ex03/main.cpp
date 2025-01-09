#include "Fixed.hpp"
#include "Point.hpp"

void printPointers(Point a, Point b, Point c, Point p)
{
	std::cout << "a: ";
	a.printPointer();
	std::cout << "b: ";
	b.printPointer();
	std::cout << "c: ";
	c.printPointer();
	std::cout <<"p: ";
	p.printPointer();
}

void runTests()
{
	{
		Point a(Fixed(0), Fixed(0));
		Point b(Fixed(0), Fixed(3));
		Point c(Fixed(3), Fixed(1));
		Point p(Fixed(1), Fixed(1));

		std::cout << "Test 0 - Basic Test" << std::endl;
		printPointers(a, b, c, p);
		std::cout << "Expected: Point is in Triangle" << std::endl;
		if (bsp(a,b,c,p))
			std::cout << "Point is in Triangle" << std::endl;
		else
			std::cout << "Point is not in Triangle" << std::endl;
	}
    {
        Point a(Fixed(0), Fixed(0));
        Point b(Fixed(0), Fixed(3));
        Point c(Fixed(3), Fixed(1));
        Point p(Fixed(4), Fixed(4));
        
        std::cout << "Test 2 - Outer point" << std::endl;
        printPointers(a, b, c, p);
		std::cout << "Expected: Point is not in Triangle" << std::endl;
        if (bsp(a,b,c,p))
            std::cout << "Result: Point is in Triangle" << std::endl;
        else
            std::cout << "Result: Point is not in Triangle" << std::endl;
        std::cout << "------------------------" << std::endl;
    }
    {
        Point a(Fixed(0), Fixed(0));
        Point b(Fixed(0), Fixed(3));
        Point c(Fixed(3), Fixed(1));
        Point p(Fixed(0), Fixed(1.5f));
        
        std::cout << "Test 3 - Border point" << std::endl;
        printPointers(a, b, c, p);
		std::cout << "Expected: Point is not in Triangle" << std::endl;
        if (bsp(a,b,c,p))
            std::cout << "Result: Point is in Triangle" << std::endl;
        else
            std::cout << "Result: Point is not in Triangle" << std::endl;
        std::cout << "------------------------" << std::endl;
    }
	{
		Point a(Fixed(0), Fixed(0));
		Point b(Fixed(0), Fixed(5));
		Point c(Fixed(5), Fixed(0));
		Point p(Fixed(1), Fixed(1));

		std::cout << "Test 4 " << std::endl;
		printPointers(a, b, c, p);
		std::cout << "Expected: Point is in Triangle" << std::endl;
		if (bsp(a,b,c,p))
			std::cout << "Point is in Triangle" << std::endl;
		else
			std::cout << "Point is not in Triangle" << std::endl;
	}
}


int main( void )
{
	runTests(); // https://www.geogebra.org/classic#graphing)
	return (0);
}