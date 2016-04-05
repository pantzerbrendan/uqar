
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

	if (r._denominator != frac.getDenominator())
	{
		r._numerator *= frac.getDenominator();
		r._denominator *= frac.getDenominator();
		r._numerator += (frac.getNumerator() * r._denominator);
	}
	else
	{
		r._numerator += frac.getNumerator();
	}
	r.reduct();
	
	return (r);
}

fraction 	fraction::operator-(const fraction &frac)
{
	fraction r(this->_numerator, this->_denominator);

	if (r._denominator != frac.getDenominator())
	{
		r._numerator *= frac.getDenominator();
		r._denominator *= frac.getDenominator();
		r._numerator -= (frac.getNumerator() * r._denominator);
	}
	else
	{
		r._numerator -= frac.getNumerator();
	}
	r.reduct();
	
	return (r);
}

fraction 	fraction::operator*(const fraction &frac)
{
	fraction r(this->_numerator, this->_denominator);

	r._numerator *= frac.getNumerator();
	r._denominator *= frac.getDenominator();
	r.reduct();
	
	return (r);
}

fraction 	fraction::operator/(const fraction &frac)
{
	fraction r(this->_numerator, this->_denominator);

	r._numerator *= frac.getDenominator();
	r._denominator *= frac.getNumerator();
	r.reduct();
	
	return (r);
}

// increments