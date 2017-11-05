/*
 * PrimitiveRootsOfPrimes.cpp
 *
 *  Created on: 02-Nov-2017
 *      Author: abhirup
 */
#include <vector>
#include <iostream>
#include <set>
using namespace std;
typedef unsigned long long ull;
ull modexp(ull a, ull b, ull m)
{
	ull res=1;
	while(b > 0)
	{
		if(b&1)
		{
			res = (res*a)%m;
		}
		a = (a*a)%m;
		b = b >> 1;
	}
	return res;
}
int main()
{
	ull n;
	cin >> n;//n is prime
	set<ull> pf;
	ull tmp=n-1;
	for(ull i=2; i<=(n-1)/2; i++)
	{
		if(tmp%i == 0)
			pf.insert(i);
		while(tmp%i == 0)
			tmp /= i;
	}
	for(ull i=1; i<=n-1; i++)
	{
		bool flag = true;
		for(auto pi:pf)
		{
			int me = modexp(i, (n-1)/pi, n);
			if(me == 1)
			{
				flag=false;
				break;
			}
		}
		if(flag)
        {
            cout << i;
            break;
        }
	}
	double tot = n-1;
	for(auto p:pf)
		tot *= (p-1.0)/p;
	cout << " " << (int)tot << endl;
}
