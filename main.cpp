/*
 * main.cpp
 *
 *  Created on: Jan 22, 2016
 *      Author: guy
 */

#include "Fraction.h"
#include <iostream>

/*TODO: write readme*/
/*TODO: document Fraction.cpp*/
using namespace std;

int main()
{
	Fraction f1(1,2);
	cout << Fraction(2,3) + f1 << endl;
	cout << (f1 + 78) << endl;

	//f1 += 0.1;

	f1 += 3;
	cout << f1 << endl;
	cout << f1 - 3 << endl;
	f1 -= 1;
	cout << f1 << "\n" << -f1 << endl;
	f1 *= -1;

	Fraction f2 = f1 * 4;
	Fraction f3 = f1;
	f3 *= 9;

	cout << f2 / f1 << " " << f3 << endl;

	f2 = Fraction(9, -18);
	cout << f2 << "\n" << (f1 > f2) << endl;

	cout << (float)f2;
	//f2 += 0.6;
	//f2 *= 0.7f;

	//f1 /= 0;
	//f2 = Fraction(0, 0);
	//f2 = Fraction(0, 1);
	// f1 /= f2;

	return 0;
}
