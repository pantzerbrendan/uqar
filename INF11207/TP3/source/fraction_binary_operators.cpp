
#include "fraction.hpp"

// integers
fraction 	fraction::operator+(const int value)
{
	fraction r(this->_numerator, this->_denominator);

	r._numerator += (value * r._denominator);
	r.reduct();
	
	return (r);
}

fraction 	fraction::operator-(const int value)
{
	fraction r(this->_numerator, this->_denominator);

	r._numerator -= (value * r._denominator);
	r.reduct();
	
	return (r);
}

fraction 	fraction::operator*(const int value)
{
	fraction r(this->_numerator, this->_denominator);

	r._numerator *= value;
	r.reduct();
	
	return (r);
}

fraction 	fraction::operator/(const int value)
{
	fraction r(this->_numerator, this->_denominator);

	r._denominator *= value;
	r.reduct();
	
	return (r);
}

// object
fraction 	fraction::operator+(const fraction &frac)
{
	fraction r(this->_numerator, this->_denominator);

	if (r._denominator != frac._denominator)
	{
		r._numerator *= frac._denominator;
		r._denominator *= frac._denominator;
		r._numerator += (frac._numerator * r._denominator);
	}
	else
	{
		r._numerator += frac._numerator;
	}
	r.reduct();
	
	return (r);
}

fraction 	fraction::operator-(const fraction &frac)
{
	fraction r(this->_numerator, this->_denominator);

	if (r._denominator != frac._denominator)
	{
		r._numerator *= frac._denominator;
		r._denominator *= frac._denominator;
		r._numerator -= (frac._numerator * r._denominator);
	}
	else
	{
		r._numerator -= frac._numerator;
	}
	r.reduct();
	
	return (r);
}

fraction 	fraction::operator*(const fraction &frac)
{
	fraction r(this->_numerator, this->_denominator);

	r._numerator *= frac._numerator;
	r._denominator *= frac._denominator;
	r.reduct();
	
	return (r);
}

fraction 	fraction::operator/(const fraction &frac)
{
	fraction r(this->_numerator, this->_denominator);

	r._numerator *= frac._denominator;
	r._denominator *= frac._numerator;
	r.reduct();
	
	return (r);
}

// pre/post-increments

fraction 	fraction::operator++()
{
	this->operator+(1);
	this->reduct();
	return (fraction(this->_numerator, this->_denominator));
}

fraction 	fraction::operator--()
{
	this->operator-(1);
	this->reduct();
	return (fraction(this->_numerator, this->_denominator));
}

fraction 	fraction::operator++(int)
{
	fraction r(this->_numerator, this->_denominator);
	this->operator+(1);
	this->reduct();
	return (r);
}

fraction 	fraction::operator--(int)
{
	fraction r(this->_numerator, this->_denominator);
	this->operator-(1);
	this->reduct();
	return (r);
}

// equal increments integers

fraction 	&fraction::operator+=(const int value)
{
	this->_numerator += (value * this->_denominator);
	this->reduct();
	return *this;
}

fraction 	&fraction::operator-=(const int value)
{
	this->_numerator -= (value * this->_denominator);
	this->reduct();
	return *this;
}

fraction 	&fraction::operator*=(const int value)
{
	this->_numerator *= value;
	this->reduct();
	return *this;
}

fraction 	&fraction::operator/=(const int value)
{
	this->_denominator *= value;
	this->reduct();
	return *this;
}

// equal increments object

fraction 	&fraction::operator+=(const fraction &frac)
{
	if (this->_denominator != frac._denominator)
	{
		this->_numerator *= frac._denominator;
		this->_denominator *= frac._denominator;
		this->_numerator += (frac._numerator * this->_denominator);
	}
	else
	{
		this->_numerator += frac._numerator;
	}
	this->reduct();
	return *this;
}

fraction 	&fraction::operator-=(const fraction &frac)
{
	if (this->_denominator != frac._denominator)
	{
		this->_numerator *= frac._denominator;
		this->_denominator *= frac._denominator;
		this->_numerator -= (frac._numerator * this->_denominator);
	}
	else
	{
		this->_numerator -= frac._numerator;
	}
	this->reduct();
	return *this;
}

fraction 	&fraction::operator*=(const fraction &frac)
{
	this->_numerator *= frac._numerator;
	this->_denominator *= frac._denominator;
	this->reduct();
	return *this;
}

fraction 	&fraction::operator/=(const fraction &frac)
{
	this->_numerator *= frac._denominator;
	this->_denominator *= frac._numerator;
	this->reduct();
	return *this;
}