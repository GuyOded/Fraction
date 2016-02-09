/*
 * Fraction.h
 *
 *  Created on: Jan 22, 2016
 *      Author: guy
 */

#ifndef FRACTION_H_
#define FRACTION_H_
#include <iostream>

class Fraction {
private:
	int m_num;
	int m_denom;

	static Fraction crossAddition(const Fraction& frac1,
			const Fraction& frac2);
	void crossAdd(const Fraction& frac);

	static Fraction crossSubtraction(const Fraction& frac1,
			const Fraction& frac2);
	void crossSub(const Fraction& frac);

	void reduceFraction();
	/* !@#$#@%#@%#@ READ!!!!!!:
	 * These conversion constructors are
	 * a work around the implicit conversion from
	 * double or float to int. Further explained in readme.
	 */
	Fraction(float f);
	Fraction(double d);
public:
	Fraction(int num, int denum = 1);

	Fraction(const Fraction& f);
	virtual ~Fraction();

	int getNumerator()  const {return m_num;}
	int getDenomerator() const {return m_denom;}
	Fraction getInverse() const;

	friend Fraction operator+(const Fraction& frac1, const Fraction& frac2);
	friend Fraction operator-(const Fraction& frac1, const Fraction& frac2);
	friend std::ostream& operator <<(std::ostream& lhs, const Fraction& rhs);
	friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);
	friend bool operator==(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
	friend bool operator>(const Fraction& lhs, const Fraction& rhs);
	friend bool operator<(const Fraction& lhs, const Fraction& rhs);
	friend bool operator>=(const Fraction& lhs, const Fraction& rhs);
	friend bool operator<=(const Fraction& lhs, const Fraction& rhs);

	Fraction& operator+=(const Fraction& rhs);
	Fraction operator-() const;
	Fraction& operator=(const Fraction& rhs);
	Fraction& operator-=(const Fraction& rhs);
	Fraction& operator/=(const Fraction& rhs);
	Fraction& operator*=(const Fraction& rhs);
	explicit operator float() const;
};

#endif /* FRACTION_H_ */
