/*
 * fraction.cpp
 *
 *  Created on: Jan 22, 2016
 *      Author: guy
 */

#include "Fraction.h"
#include <iostream>
#include <stdexcept>
#include <cmath>


/**
 * Fraction(int num, int denum = 1)
 *
 * @param num
 * @param denom
 */
Fraction::Fraction(int num, int denom)
{
	if(denom == 0)
	{
		throw std::overflow_error("Division by zero exception");
	}
	/* if the denominator is negative pass the minus sign to
	 * the numerator: -1        1
	 * 				  --- ---> ---
	 * 				  -1        1
	 *
	 * 				   1       -1
	 * 				  --- ---> ---
	 * 				  -1        1
	 */
	if(denom < 0)
	{
		denom *= -1;
		num *= -1;
	}

	m_num = num;
	m_denom = denom;
	this->reduceFraction();
}

/**
 * Fraction(const Fraction& f)
 *
 * a copy constructor.
 *
 * @param f-instance to copy
 */
Fraction::Fraction(const Fraction& f)
{
	this->m_num = f.m_num;
	this->m_denom = f.m_denom;
}

Fraction::~Fraction() {
	// TODO Auto-generated destructor stub
}


/**
 * static Fraction crossAddition(const Fraction& frac1,
 *			const Fraction& frac2)
 * adds the given fractions using cross multiplication
 *
 * @param frac1
 * @param frac2
 * @return a new fraction that is the addition of the parameters
 */
Fraction Fraction::crossAddition(const Fraction& frac1, const Fraction& frac2)
{
	int new_num = frac1.m_num * frac2.m_denom;
	new_num += frac1.m_denom * frac2.m_num;

	int new_denum = frac1.m_denom* frac2.m_denom;

	return Fraction(new_num, new_denum);
}

/**
 * static Fraction crossSubtraction(const Fraction& frac1,
 *			const Fraction& frac2);
 *
 * same as crossAddition except it subtracts
 *
 * @param frac1
 * @param frac2
 * @return a new fraction that is the subtraction of the given parameters
 */
Fraction Fraction::crossSubtraction(const Fraction& frac1, const Fraction& frac2)
{
	int new_num = frac1.m_num * frac2.m_denom;
	new_num -= frac1.m_denom * frac2.m_num;

	int new_denum = frac1.m_denom* frac2.m_denom;

	return Fraction(new_num, new_denum);
}

/**
 * void crossAdd(const Fraction& frac)
 *
 * same as crossAddition but changes the instance
 * that called it
 *
 * @param frac- the fraction that is added
 */
void Fraction::crossAdd(const Fraction& frac)
{
	this->m_num *= frac.m_denom;
	this->m_num += this->m_denom * frac.m_num;

	this->m_denom *= frac.m_denom;
}

/**
 * void crossSub(const Fraction& frac)
 *
 * same as crossSubstraction but changes the instance
 * that called it
 *
 * @param frac
 */
void Fraction::crossSub(const Fraction& frac)
{
	this->m_num *= frac.m_denom;
	this->m_num -= this->m_denom * frac.m_num;

	this->m_denom *= frac.m_denom;
}

/**
 * void reduceFraction()
 *
 * Reduce the fraction as in 4/6 ---> 2/3
 */
void Fraction::reduceFraction()
{
	if(m_num == 0)
	{
		m_denom = 1;
		return;
	}
	if(m_num == m_denom)
	{
		m_num = 1, m_denom = 1;
		return;
	}

	int min = std::abs(m_num) > m_denom ? m_denom : std::abs(m_num);
	for(; min > 0; min--)
	{
		if((m_num % min == 0) && (m_denom % min == 0))
		{
			m_num /= min;
			m_denom /= min;
			return;
		}
	}
}

/**
 * Fraction getInverse() const
 *
 * Inverses the fraction as in- 1/2 ---> 2/1
 *
 * @return a new copy of the inverse fraction
 */
Fraction Fraction::getInverse() const
{
	return Fraction(this->m_denom, this->m_num);
}


/**
 * friend std::ostream& operator <<(std::ostream& lhs, const Fraction& rhs)
 *
 * overload insertion operator so Fraction type can be printed
 * to an output stream
 *
 * @param lhs-reference to output stream
 * @param rhs-the inserted fraction
 * @return a reference to the left hand operand
 */
std::ostream& operator<<(std::ostream& lhs, const Fraction& rhs)
{
	lhs << rhs.m_num << '/' << rhs.m_denom;
	return lhs;
}

/**
 * friend Fraction operator+(const Fraction& frac1, const Fraction& frac2)
 *
 * overload binary operator  +: frac1 + frac2
 *
 * @param frac1
 * @param frac2
 * @return
 */
Fraction operator+(const Fraction& lhs, const Fraction& rhs)
{
	Fraction result = Fraction::crossAddition(lhs, rhs);
	result.reduceFraction();
	return result;
}

/**
 * friend Fraction operator-(const Fraction& frac1, const Fraction& frac2)
 *
 * overload of the binary operator -: lhs - rhs
 *
 * @param lhs-left hand operand
 * @param rhs-right hand operand
 * @return a new result that is the reduced version of the subtraction
 */
Fraction operator-(const Fraction& lhs, const Fraction& rhs)
{
	Fraction result = Fraction::crossSubtraction(lhs, rhs);
	result.reduceFraction();
	return result;
}

/**
 * friend Fraction operator/(const Fraction& lhs, const Fraction& rhs)
 *
 * overload division operator: 1/2 / 2/1 = 1/2 * 1/2 = 1/4
 * @param lhs-left hand fraction
 * @param rhs-right hand fraction
 * @return a new instance of fraction that is the result of the division
 */
Fraction operator/(const Fraction& lhs, const Fraction& rhs)
{
	return lhs * rhs.getInverse();
}

/**
 * friend Fraction operator*(const Fraction& lhs, const Fraction& rhs)
 *
 * operator of multiplication operator
 *
 * @param lhs-left hand operand
 * @param rhs-right hand operand
 * @return a new fraction-result
 */
Fraction operator*(const Fraction& lhs, const Fraction& rhs)
{
	/* note that calling reduce fraction is not needed
	 * as it is called within the constructor */
	Fraction result(lhs.m_num * rhs.m_num, lhs.m_denom * rhs.m_denom);
	/* if the denominator is negative pass the minus sign to
	 * the numerator: -1        1
	 * 				  --- ---> ---
	 * 				  -1        1
	 *
	 * 				   1       -1
	 * 				  --- ---> ---
	 * 				  -1        1
	 */
	if(result.m_denom < 0)
	{
		result.m_num *=  -1;
		result.m_denom *= -1;
	}
	return result;
}

/**
 * Fraction& operator+=(const Fraction& rhs)
 *
 * Addition assignment overload
 * @param rhs-the added fraction
 * @return a reference to the current instance
 */
Fraction& Fraction::operator+=(const Fraction& rhs)
{
	this->crossAdd(rhs);
	this->reduceFraction();

	return *this;
}

/**
 * Fraction& operator-=(const Fraction& rhs)
 *
 * Subtraction assignment overload
 * @param rhs-the substructed fraction
 * @return a reference to this instance to allow chaining
 */
Fraction& Fraction::operator-=(const Fraction& rhs)
{
	this->crossSub(rhs);
	this->reduceFraction();

	return *this;
}

/**
 * Fraction& operator*=(const Fraction& rhs)
 *
 * overloading of multiplication assignment operator
 *
 * @param rhs-right hand side of the equation
 * @return a reference to this instance to allow chaining
 */
Fraction& Fraction::operator*=(const Fraction& rhs)
{
	this->m_num *= rhs.m_num;
	this->m_denom *= rhs.m_denom;
	/* if the denominator is negative pass the minus sign to
	 * the numerator: -1        1
	 * 				  --- ---> ---
	 * 				  -1        1
	 *
	 * 				   1       -1
	 * 				  --- ---> ---
	 * 				  -1        1
	 */
	if(this->m_denom < 0)
	{
		this->m_num *=  -1;
		this->m_denom *= -1;
	}
	this->reduceFraction();
	return *this;
}

/**
 * Fraction& operator/=(const Fraction& rhs)
 *
 * division assignment operator
 *
 * @param rhs-right hand operand
 * @return a reference to this instance to allow chaining
 */
Fraction& Fraction::operator/=(const Fraction& rhs)
{
	*this *= rhs.getInverse();
	return *this;
}

/**
 * Fraction operator-() const
 *
 * overload unary negation operator -: fraction = 1/2
 * 									   -fraction = -1/2
 * Note that the function doesn't change the operand and returns
 * a new instance
 *
 * @return
 */
Fraction Fraction::operator-() const
{
	return Fraction(-1*this->m_num, this->m_denom);
}


/**
 * friend bool operator==(const Fraction& lhs, const Fraction& rhs)
 *
 * overload of equality operator ==
 * Fractions are considered equal if their numerators and denumerators
 * are equal. Note that all the fractions will always be there
 * most reduced version: 4/6-->2/3
 *
 * @param lhs-left hand fraction
 * @param rhs-right hand fraction
 * @return true if the fractions are equal or false if they aren't
 */
bool operator==(const Fraction& lhs, const Fraction& rhs)
{
	return (lhs.m_num == rhs.m_num) && (lhs.m_denom == rhs.m_denom);
}

/**
 * friend bool operator>(const Fraction& lhs, const Fraction& rhs)
 *
 * @param lhs-left hand operand
 * @param rhs-right hand operand
 * @return true if lhs is greater than rhs or false otherwise
 */
bool operator>(const Fraction& lhs, const Fraction& rhs)
{
	return (lhs.m_num * rhs.m_denom) > (rhs.m_num * lhs.m_denom);
}

/**
 * friend bool operator<(const Fraction& lhs, const Fraction& rhs)
 *
 * @param lhs-left hand operand
 * @param rhs-right hand operand
 * @return true if rhs is greater than lhs or false otherwise
 */
bool operator<(const Fraction& lhs, const Fraction& rhs)
{
	return rhs > lhs;
}

/**
 * friend bool operator<(const Fraction& lhs, const Fraction& rhs)
 *
 * @param lhs-left hand operand
 * @param rhs-right hand operand
 * @return true if lhs is greater than or equals to rhs or false otherwise
*/
bool operator>=(const Fraction& lhs, const Fraction& rhs)
{
	return rhs > lhs || rhs == lhs;
}

/**
 * friend bool operator<(const Fraction& lhs, const Fraction& rhs)
 *
 * @param lhs-left hand operand
 * @param rhs-right hand operand
 * @return true if rhs is greater than or equals to lhs or false otherwise
*/
bool operator<=(const Fraction& lhs, const Fraction& rhs)
{
	return rhs >= lhs;
}

/**
 * Fraction& operator=(const Fraction& rhs)
 *
 * overload the assignment operator to return a copy
 *
 * @param rhs-the right hand operand- the one that is copied
 * @return a copy of the right hand operand
 */
Fraction& Fraction::operator=(const Fraction& rhs)
{
	/*return a copy by calling the copy constructor*/
	this->m_num = rhs.m_num;
	this->m_denom = rhs.m_denom;
	return *this;
}

/**
 * explicit float operator float() const
 *
 * converts a Fraction to float - explicit to avoid ambiguity
 *
 * @return the ratio represented as a decimal fraction with
 * 		   the precision of a single floating point
 */
Fraction::operator float() const
{
	return (float)this->m_num / this->m_denom;
}
