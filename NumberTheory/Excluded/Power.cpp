/*
 * Power.cpp
 *
 *  Created on: 28-Oct-2017
 *      Author: abhirup
 */
#include <iostream>
#include <cmath>
using namespace std;

float powr(float x, int y)
{
	if(y == 0 || x == 1)
		return 1;

	float t = powr(x, y/2);
	if(y%2 == 0)
		return t*t;

	else
	{
		if(y>0)
			return x*t*t;
		else
			return t*t*1.0/x;
	}
}
int main()
{
	int x, y;
	cin >> x >> y;
	cout << powr(x,y);
}
