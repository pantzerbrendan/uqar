
#include "fraction.hpp"

bool		fraction::operator==(const fraction &frac)
{
	if (this->_numerator == frac._numerator
		&& this->_denominator == frac._denominator)
		return (true);
	return (false);
}

bool		fraction::operator!=(const fraction &frac)
{
	return (!(this->operator==(frac)));
}
