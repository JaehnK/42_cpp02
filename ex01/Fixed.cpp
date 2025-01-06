#include "Fixed.hpp"

const int	Fixed::fBits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	fixedPoint = num << fBits;
	std::cout << "Int constructor called: " <<  std::endl;
}

Fixed::Fixed(const float num)
{
	fixedPoint = roundf(num * (1 << fBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	if (this != &f)
	{
		this->fixedPoint = f.getFixedPoint();
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
}

int		Fixed::getFixedPoint(void) const
{
	return (this->fixedPoint);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixedPoint / (1 << fBits));
}

int		Fixed::toInt(void) const
{
	return (this->fixedPoint >> fBits);
}

std::ostream& operator<< (std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}






