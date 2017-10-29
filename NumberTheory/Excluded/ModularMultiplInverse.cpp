/*
 * MMI.cpp
 *
 *  Created on: 28-Oct-2017
 *      Author: abhirup
 */
#include <iostream>
#include <cmath>
using namespace std;
int mmi_naive(int a, int m)//O(m)
{
	a = a %m;
	for(int i=1; i<=m-1; i++)
		if((a*i)%m == 1)
		{
			return i;
		}
}
int gcd_extended(int a, int b, int *x, int *y)
{
	if(a == 0)
	{
		*x = 0;
		*y = 1;
		return b;
	}
	int x1, y1;
	int gcd = gcd_extended(b%a, a, &x1, &y1);
	*x = y1 - b/a * x1;
	*y = x1;
	return gcd;
}
int mmi_extended(int a, int m)
{
	int x, y;
	int g = gcd_extended(a%m, m, &x, &y);
	if(g != 1)
	{
		cout << "Inverse doesn't exist."<< endl;
		return -1;
	}
	else
	{
		return (x%m+m)%m;
	}
}
int mmi_iterative(int a , int m)
{
	int x_=1, x = 0;//ax_ + mx = 1 (mod m)
	int m_copy = m;
	if(m == 1)
	{
		return 0;
	}
	while(a > 1)
	{
		int prev = m, q = a/m;
		m = a % m;
		a = prev;

		prev = x;
		x = x_ - q*x;
		x_ = prev;
	}
	if(x_ < 0)
	{
		x_ += m_copy;
	}
	return x_;
}
int main()
{
	int a, m;
	cin >> a >> m;
	cout << mmi_naive(a, m)<<endl;
	cout << mmi_extended(a, m) << endl;//for co-prime
	cout << mmi_iterative(a, m)<<endl;
}
