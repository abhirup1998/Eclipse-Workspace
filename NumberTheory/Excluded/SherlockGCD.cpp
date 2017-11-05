/*
 * SherlockGCD.cpp
 *
 *  Created on: 30-Oct-2017
 *      Author: abhirup
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int gcd(int a, int b)
{
	if(a%b == 0)return b;
	if(b%a == 0)return a;
	int r_prev = max(a,b), r = min(a,b);
	while(r != 0)
	{
		int temp = r;
		r = r_prev%r;
		r_prev = temp;
	}
	return r_prev;
}
int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
    	int N, gc=0;
    	cin >> N;
    	vector<unsigned int> v(N);
    	for(int j=0; j < N; j++)
			cin >> v[j];
        for(auto j:v)
        {
            gc = gcd(gc, j);
        }
    	if(gc == 1)
    		cout << "YES" << endl;
    	else
    		cout << "NO" << endl;
    }
    return 0;
}
