#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixedPoint;
		static const int	fBits;

	public:
		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed(const Fixed &f);
		Fixed& operator = (const Fixed &f);
		
		friend std::ostream& operator<< (std::ostream &out, const Fixed &f);

		int		getFixedPoint(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;

};

#endif

