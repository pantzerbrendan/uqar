
#include <string>
#include "fraction.hpp"

int		fraction::getNumerator() const
{
	return (this->_numerator);
}

uint	fraction::getDenominator() const
{
	return (this->_denominator);
}

void	fraction::setNumerator(const int value)
{
	this->_numerator = value;
	//this->reduct();
}

void	fraction::setDenominator(const uint value)
{
	if (value == 0)
		throw new std::string("error: denominator cannot be equal to 0\nFloating exception");
	this->_denominator = value;
	//this->reduct();
}