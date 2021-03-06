
#ifndef FRACTION_HPP_
#define FRACTION_HPP_

#include <ostream>

typedef unsigned int 	uint;

class fraction
{
private:
	int 		_numerator;
	uint 		_denominator;

public:
	// fraction.cpp
	fraction();
	fraction(int, uint);
	fraction(int);
	fraction(const fraction &);
	~fraction();
	void 		operator=(const fraction &);

	// fration_unary_operators.cpp
	fraction 	operator+();
	fraction 	operator-();
	fraction 	operator~();

	// fraction_binary_operators.cpp # integers (l:4)
	fraction 	operator+(const int);
	fraction 	operator-(const int);
	fraction 	operator*(const int);
	fraction 	operator/(const int);

	// fraction_binary_operators.cpp # object (l:46)
	fraction 	operator+(const fraction &);
	fraction 	operator-(const fraction &);
	fraction 	operator*(const fraction &);
	fraction 	operator/(const fraction &);

	// fraction_binary_operators.cpp # pre/post-increments (l:108)
	fraction 	operator++(); // pre-increment
	fraction 	operator--(); // pre-increment
	fraction 	operator++(int); // post-increment
	fraction 	operator--(int); // post-increment

	// fraction_binary_operators.cpp # compound assignment integers (l:140)
	fraction 	&operator+=(const int);
	fraction 	&operator-=(const int);
	fraction 	&operator*=(const int);
	fraction 	&operator/=(const int);

	// fraction_binary_operators.cpp # compound assignment object (l:170)
	fraction 	&operator+=(const fraction &);
	fraction 	&operator-=(const fraction &);
	fraction 	&operator*=(const fraction &);
	fraction 	&operator/=(const fraction &);

	// fraction_relational_operators
	bool		operator==(const fraction &);
	bool		operator!=(const fraction &);

	// fraction_getseters.cpp
	int 		getNumerator() const;
	uint 		getDenominator() const;
	void		setNumerator(const int);
	void 		setDenominator(const uint);

	void 		reduct();

};

std::ostream &operator<<(std::ostream &, const fraction &);

fraction 	operator+(const int, const fraction &);
fraction 	operator-(const int, const fraction &);
fraction 	operator*(const int, const fraction &);
fraction 	operator/(const int, const fraction &);

#endif /* !FRACTION_HPP_ */