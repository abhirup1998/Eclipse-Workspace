/*
 * ModularExponentiation.cpp
 *
 *  Created on: 28-Oct-2017
 *      Author: abhirup
 */
#include <iostream>
#include <cmath>
using namespace std;

float modexp(unsigned int x, unsigned int y, unsigned int p)
{
	if(x == 0)return 0;
	if((x == 1 || y==0))
		return 1%p;
	unsigned int res=1;
	x = x % p;
	while(y>0)
	{
		if(y & 1)
			res = (res*x)%p;
		x = (x*x)%p;
		y /= 2;
	}
	return res%p;
}
int main()
{
	int x, y, p;
	cin >> x >> y >> p;
	cout << modexp(x,y,p);
	return 0;
}
