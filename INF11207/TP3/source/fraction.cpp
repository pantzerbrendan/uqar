
#include <iostream>
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
	//this->reduct();
}

fraction::fraction(int num)
{
	this->_numerator = num;
	this->_denominator = 1;
}

fraction::fraction(const fraction &frac)
{
	this->_numerator = frac._numerator;
	this->_denominator = frac._denominator;
	//this->reduct();
}

fraction::~fraction()
{
	
}

void 		fraction::operator=(const fraction &frac)
{
	this->_numerator = frac._numerator;
	this->_denominator = frac._denominator;
	//this->reduct();
}

// void 		fraction::reduct()
// {
// 	int 	pgcd = utils::pgcd(this->_numerator, this->_denominator);
// 	this->_numerator /= pgcd;
// 	this->_denominator /= pgcd;
// }

std::ostream	&operator<<(std::ostream &stream, const fraction &f)
{
	stream << f.getNumerator() << "/" << f.getDenominator();
	return (stream);
}