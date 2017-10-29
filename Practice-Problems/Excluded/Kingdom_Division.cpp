/*
 * Kingdom_Division.cpp
 *
 *  Created on: 04-Oct-2017
 *      Author: Abhirup Das
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int w;
vector<vector<int> > g;
vector<bool> aff;
vector<bool> vis;
void affiliate(int u)
{
	vis[u] = true;
	if(aff[u])
	{
		if(g[u].size() == 1)
		{
			int v = g[u][0];
			aff[v] = true;
			cout << v+1 << " aff in " << w << "ways" << endl;
			cout << "Control Shift from " << u+1 << " to " << v+1 << endl;
			affiliate(g[u][0]);
			return;
		}
		cout << "Marking leaves of " << u+1 << endl;
		for(int j = 0; j<g[u].size(); j++)
		{
			int v = g[u][j];
			if(!vis[v] && g[v].size() == 1)
			{
				aff[v] = true;
				cout << v+1 << " aff in " << w << "ways" << endl;
				vis[v] = true;
			}
		}
		cout << "Traversing neighbours of " << u+1 << endl;
		for(int j = 0; j<g[u].size(); j++)
		{
			int v = g[u][j];
			if(!vis[v])
			{
				cout << "Control Shift from " << u+1 << " to " << v+1 << endl;
				affiliate(v);
			}
		}
	}
	else
	{
//		if(g[u].size() == 1)
//		{
//			aff[u] = true;
//			cout << u+1 << " aff in " << w << "ways" << endl;
//			if(vis[g[u][0]])
//				return;
//			else
//			{
//				int v = g[u][0];
//				aff[v] = true;
//				cout << v+1 << " aff in " << w << "ways" << endl;
//				cout << "Control Shift from " << u+1 << " to " << v+1 << endl;
//				affiliate(v);
//			}
//			return;
//		}
		int leaf= 0;
		cout << "Marking leaves of " << u+1 << endl;
		for(int j = 0; j<g[u].size(); j++)
		{
			int v = g[u][j];
			if(!vis[v] && g[v].size() == 1)
			{
				aff[v] = true;
				cout << v+1 << " aff in " << w << "ways" << endl;
				vis[v] = true;
				leaf++;
			}
		}
		w = w * 2;
		aff[u] = true;
		cout << u+1 << " aff in " << w << "ways" << endl;
		cout << "Traversing neighbours of " << u+1 << endl;
		for(int j = 0; j<g[u].size(); j++)
		{
			int v = g[u][j];
			if(!vis[v])
			{
				cout << "Control Shift from " << u+1 << " to " << v+1 << endl;
				affiliate(v);
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	g.resize(n); aff.resize(n); vis.resize(n);
	for(int i=0; i<n-1; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x-1].push_back(y-1);
		g[y-1].push_back(x-1);
	}
	w = 2;
	aff[0] = true;
	affiliate(0);
	cout << w;
}
