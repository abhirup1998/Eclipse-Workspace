/*
 * GCD.cpp
 *
 *  Created on: 28-Oct-2017
 *      Author: abhirup
 */
#include <iostream>
#include <cmath>
using namespace std;
int gcd_basic(int a, int b)
{
	int res=0;
	while(a > 1 &&  b > 1)
	{
		if(b % a == 0)
			return a;
		if(a % b == 0)
			return b;
		if(a > b)
		{
			a -= a/b * b;
			res = a;
		}
		else if(b > a)
		{
			b -= b/a * a;
			res = b;
		}
	}
	return res;
}
int gcd_extended_rec(int a, int b, int *x, int *y)
{
	if(a == 0)
	{
		*x=0;
		*y=1;
		return b;
	}
	int x1, y1;
	int gcd = gcd_extended_rec(b%a, a, &x1, &y1);
	*x = y1 - (b/a)*x1;
	*y = x1;
	return gcd;
}
int gcd(int a, int b, int *q)
{
	if(a%b == 0)return b;
	if(b%a == 0)return a;
	int r_prev = max(a,b), r = min(a,b);
	while(r != 0)
	{
		*q = r_prev/r;
		int temp = r;
		r = r_prev%r;
		r_prev = temp;
		cout << "   q "<< *q << endl;
	}
	return r_prev;
}
int main()
{
	int a, b, x, y;
	cin >>  a>> b;
	cout<< gcd_basic(a,b) << endl;
	cout<< gcd_extended_rec(a,b,&x, &y) << endl;
	int q = 0;
	cout << gcd(a, b, &q);
	cout << " q=" << q << endl;
}
