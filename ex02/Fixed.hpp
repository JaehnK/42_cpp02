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

		Fixed&	operator = (const Fixed &f);
		bool	operator > (const Fixed &f) const; // 기존 클래스가 값이 변하는 것을 방지
		bool	operator < (const Fixed &f) const;
		bool	operator >= (const Fixed &f) const;
		bool	operator <= (const Fixed &f) const;
		bool	operator == (const Fixed &f) const;
		bool	operator != (const Fixed &f) const;
		
		Fixed	operator + (const Fixed &f) const; // 새로운 객체를 생성 함 (dangling pointer)
		Fixed	operator - (const Fixed &f) const; // 참조 반환은 함수 내 지역 변수를 반환
		Fixed	operator * (const Fixed &f) const; // 따라서 값으로 반환
		Fixed	operator / (const Fixed &f) const;

		Fixed&	operator ++ (); // 전위 연산자 ++fix
		Fixed&	operator -- ();
		const Fixed	operator ++ (int); // 후위 연산자 fix++
		const Fixed	operator -- (int);
		
		friend std::ostream& operator<< (std::ostream &out, const Fixed &f);

		int		getFixedPoint(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;
		
		Fixed	min(Fixed& f1, Fixed& f2);
		Fixed	max(Fixed& f1, Fixed& f2);
		//Fixed	min(const Fixed& f1, const Fixed& f2);
		//Fixed	max(const Fixed& f1, const Fixed& f2);
};

#endif

