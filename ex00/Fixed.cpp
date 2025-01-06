#include "Fixed.hpp"

const int Fixed::fBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	integer = 0;
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
		integer = f.getRawBits();
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return 0;
}

void Fixed::setRawBits(int const raw)
{
	integer = raw;
	std::cout << "setRawBits member function called" << std::endl;
}