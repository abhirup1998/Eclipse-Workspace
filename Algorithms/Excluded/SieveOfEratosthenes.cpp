/*
 * SieveOfEratosthenes.cpp
 *
 *  Created on: 30-Oct-2017
 *      Author: abhirup
 */
#include <iostream>
#include <cmath>
using namespace std;
void buildPrefix(int n, int*pref)
{
	bool prime[n+1];
	fill(prime, prime+n+1, true);
	prime[0] = prime[1] = false;
	for(int p=2; p*p<=n; p++)
	{
		if(prime[p])
		{
			int i= p*2;
			while(i <= n)
			{
				prime[i]=false;
				i += p;
			}
		}
	}
	for(int p=2; p<=n; p++)
	{
		pref[p] = pref[p-1];
		if(prime[p])pref[p]++;
	}
	for(int i=0; i<=n; i++)
		if(prime[i])
			cout << i << endl;
}
int query(int L, int R, int*pref)
{
	return pref[R] - pref[L-1];
}
int main()
{
	int L, R;
	cin >> L >> R;
	int pref[R+1];
	pref[0] = 0;
	pref[1] = 0;
	buildPrefix(R, pref);
	cout << "no of primes= " << query(L, R, pref)<< endl;
}
