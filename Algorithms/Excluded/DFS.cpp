/*
 * DFS.cpp
 *
 *  Created on: 05-Nov-2017
 *      Author: abhirup
 */
#include <iostream>
#include <vector>
using namespace std;
vector<int> vis;
vector< vector <int> > v;
void dfs(int p)
{
	vis[p] = true;
	cout << " -- " << p << endl;
	for(int i=0; i<v[p].size(); i++)
	{
		if(!vis[v[p][i]])
			dfs(v[p][i]);

	}
}
int main()
{
	int n, m, p;
	cin >> n >> m;
	vis.resize(n);
	v.resize(n);
	for(int i=0; i<m; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	while(1){
		cin >> p;
		if(p == -1)
			break;
		fill(vis.begin(), vis.end(), 0);
		dfs(p);
	}
}
