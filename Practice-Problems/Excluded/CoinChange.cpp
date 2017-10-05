/*
 * CoinChange.cpp
 *
 *  Created on: 28-Sep-2017
 *      Author: Abhirup Das
 */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//long getNoOfDenominations(int n, vector <int> d, int m)
//{
//	int i,j;
//	vector<vector<int> > g(m, vector<int>(n+1));
//	for(i = 0; i<m; i++)g[i][0] = 0;
//	for(j = 0; j<=n; j++)g[0][j] = j/d[0];
//	cout << d[0] << " --> ";
//	for(j = 0; j<=n; j++)
//		cout << g[0][j] << " ";
//	cout << endl;
//	for(i = 1; i<m; i++)
//	{
//		cout << d[i] << " --> 0 ";
//		for(j = 1; j <= n; j++)
//		{
//			g[i][j] = min(g[i-1][j], j/d[i] + g[i-1][j%d[i]]);
//			cout << g[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}
int64_t getWays(int n, vector<int> d, int m)
{
	int i,j;
	vector<vector<int64_t> > g(m, vector<int64_t>(n+1));
	for(i = 0; i<m; i++)
		g[i][0] = 1;
	for(j = 0; j<=n; j++)
		if(j % d[0] == 0)
			g[0][j] = 1;
		else
			g[0][j] = 0;

	for(i = 1; i<m; i++)
	{
		for(j = 1; j < d[i] && j <= n; j++)
		{
			g[i][j] = g[i-1][j];
		}
		for(; j <=n; j++)
		{
			g[i][j] = g[i-1][j] + g[i][j-d[i]];
		}
	}
//	for(i=0; i<m; i++)
//	{
//		for(j=0; j<=n; j++)
//			cout << g[i][j] << " ";
//		cout << endl;
//	}
	return g[m-1][n];
}
int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> d(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> d[c_i];
    }
    sort(d.begin(), d.end());
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    cout << getWays(n, d, m);
    return 0;
}
