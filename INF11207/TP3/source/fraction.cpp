
#include "utils.h"
#include "fraction.hpp"

fraction::fraction()
{
	this->_numerator = 1;
	this->_denominator = 1;
}

fraction::fraction(int num, uint den)
{
	this->_numerator = num;
	this->_denominator = den;
	this->reduct();
}

fraction::fraction(int num)
{
	this->_numerator = num;
	this->_denominator = 1;
}

fraction::fraction(const fraction &frac)
{
	this->_numerator = frac.getNumerator();
	this->_denominator = frac.getDenominator();
	this->reduct();
}

fraction::~fraction()
{
	
}

fraction 	&fraction::operator=(const fraction &frac)
{
	this->_numerator = frac.getNumerator();
	this->_denominator = frac.getDenominator();
	this->reduct();
}

void 		fraction::reduct()
{
	int 	pgcd = utils::pgcd(this->_numerator, this->_denominator);
	this->_numerator /= pgcd;
	this->_denominator /= pgcd;
}