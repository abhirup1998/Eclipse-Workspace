/*
 * GreedyFlorist.cpp
 *
 *  Created on: 28-Sep-2017
 *      Author: Abhirup Das
 Problem Link
 https://www.hackerrank.com/challenges/greedy-florist
 */
#include <bits/stdc++.h>

using namespace std;
int mincost(int n, int k, vector<int> c)
{
	int ans=0;
	if(n < k)
	{
		for(int i=0; i<n; i++)
			ans += c[i];
		return ans;
	}
	sort(c.begin(), c.end(), greater<int>());
	int t = 0, x = 1;
	for(int i=0; t < n; i+=k)
	{
//		cout << i << "       ";
		for(int j=0; j<k && t < n; j++)
//			cout << c[t] << " ";
			ans += x*c[t++];
//			cout << ans << "    , ";
//		cout << endl;
		x++;
	}
	return ans;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for(int c_i = 0; c_i < n; c_i++){
       cin >> c[c_i];
    }
    cout << mincost(n, k, c) << endl;
    return 0;
}
