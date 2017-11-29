/*
 * modulo.cpp
 *
 *  Created on: 05-Nov-2017
 *      Author: abhirup
 */
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
int main()
{
	int t;
	cin >> t;
	for(int tc=0; tc < t; tc++){
		int n; cin >> n;
		vector<ull> A(n), B(n);
		for(int i=0; i<n; i++)
			cin >> A[i];
		ull b=INT_MAX;
		for(int i=0; i<n; i++)
		{
			cin >> B[i];
			if(B[i] < b)
				b=B[i];
		}
		for(int i=0;i<n ;i++)
		{
			A[i] = A[i]%B[i];
		}
		vector<int>v(b);
		for(ull i=0; i<b; i++)
		{
			for(ull j=0; j<n; j++)
			{
				if(A[j]%B[j]!=i)
				{
					ull vn;
					if(i < A[j])
						vn = i + B[j] - A[j];
					else
						vn = i - A[j];
					v[i] += vn;
				}
			}
		}
		cout << *min_element(v.begin(), v.end()) << endl;
	}
}
