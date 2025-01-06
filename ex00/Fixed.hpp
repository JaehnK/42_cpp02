#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int 				integer;
		static const int	fBits;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &f);
		Fixed& operator=(const Fixed &f);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif

