/*
 * PrimeFactorization.cpp
 *
 *  Created on: 30-Oct-2017
 *      Author: abhirup
 */
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> SPF(n+1, 1);
	for(int p=2; p*p<=n; p++)
	{
		if(SPF[p] == 1)
			for(int j=p*2; j<=n; j+=p)
			{
				if(SPF[j] == 1)
					SPF[j] = p;
			}
	}
	for(int i=2; i<=n; i++)
	{
		int p=i;
		cout << i << " ";
		while(SPF[p]!=1)
		{
			cout << SPF[p] << " x ";
			p/=SPF[p];
		}
		cout << p << endl;
	}

}
