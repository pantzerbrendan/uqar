
#include "fraction.hpp"

fraction 	fraction::operator+()
{
	return (fraction(this->_numerator, this->_denominator));
}

fraction 	fraction::operator-()
{
	this->_numerator = -this->_numerator;
	//this->reduct();
	return (fraction(this->_numerator, this->_denominator));
}

fraction 	fraction::operator~()
{
	this->_numerator = ~this->_numerator;
	this->_denominator = ~this->_denominator;
	//this->reduct();
	return (fraction(this->_numerator, this->_denominator));
}
