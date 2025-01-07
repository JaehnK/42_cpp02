#include "Fixed.hpp"

const int	Fixed::fBits = 8;

Fixed::Fixed(void)
{
	fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	fixedPoint = num << fBits;
	std::cout << "Int constructor called" <<  std::endl;
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

Fixed	&Fixed::operator = (const Fixed &f)
{
	if (this != &f)
	{
		this->fixedPoint = f.getFixedPoint();
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
}

bool	Fixed::operator > (const Fixed &f) const
{
	return (this->fixedPoint > f.fixedPoint); 
}

bool	Fixed::operator < (const Fixed &f)const
{
	return (this->fixedPoint < f.fixedPoint); 
}

bool	Fixed::operator >= (const Fixed &f) const
{
	return (this->fixedPoint >= f.fixedPoint); 
}

bool	Fixed::operator <= (const Fixed &f) const
{
	return (this->fixedPoint <= f.fixedPoint); 
}

bool	Fixed::operator == (const Fixed &f) const
{
	return (this->fixedPoint == f.fixedPoint); 
}

bool	Fixed::operator != (const Fixed &f) const
{
	return (this->fixedPoint != f.fixedPoint); 
}

Fixed	Fixed::operator + (const Fixed &f) const
{
	Fixed	tmp;
	tmp.fixedPoint = this->fixedPoint + f.fixedPoint;
	return (tmp);
}

Fixed	Fixed::operator - (const Fixed &f) const
{
	Fixed	tmp;
	tmp.fixedPoint = this->fixedPoint - f.fixedPoint;
	return (tmp);
}

Fixed	Fixed::operator * (const Fixed &f) const
{
	Fixed	tmp;
	tmp.fixedPoint = (this->fixedPoint * f.fixedPoint) >> fBits; 
	
	return (tmp);
}

Fixed	Fixed::operator / (const Fixed &f) const
{
	Fixed	tmp;
	tmp.fixedPoint = (this->fixedPoint / f.fixedPoint) >>;
	return (tmp);
}

Fixed	&Fixed::operator ++ ()
{
	fixedPoint++;
	return (*this);
}

Fixed	&Fixed::operator -- ()
{
	fixedPoint--;
	return (*this);
}

const Fixed	Fixed::operator ++ (int)
{
	const Fixed tmp(*this); // 기존 값을 먼저 복사
	fixedPoint++;
	return (tmp);
}

const Fixed	Fixed::operator -- (int)
{
	const Fixed	tmp(*this);
	fixedPoint--;
	return (tmp);
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

