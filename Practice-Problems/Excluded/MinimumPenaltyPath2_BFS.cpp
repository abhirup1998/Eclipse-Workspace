/*
 * MinimumPenaltyPath2_BFS.cpp
 *
 *  Created on: 24-Sep-2017
 *      Author: Abhirup Das
 Problem Link:

 */
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> pr;
vector<vector<pr> > v(1000);
bool vis[1000][1024];

int main()
{
	int n,m;
	cin >> n >> m;
	v.resize(n);
	for(int i = 0; i<m; i++)
	{
		int x,y, z;
		cin >> x >> y >> z;
		v[x-1].push_back(make_pair(y-1, z));
		v[y-1].push_back(make_pair(x-1, z));
	}
	int s, e;
	cin >> s >> e;
	queue<int> bfsq;
	bfsq.push(s-1);
	bfsq.push(0);
	while(!bfsq.empty())
	{
		int u = bfsq.front(); bfsq.pop();
		int cost = bfsq.front(); bfsq.pop();
		vis[u][cost] = true;
		for(int i=0; i<v[u].size(); i++)
		{
			int u2 = v[u][i].first;
			int w2 = v[u][i].second;
			if(vis[u2][w2|cost] == false)
			{
				vis[u2][w2|cost] = true;
				bfsq.push(u2);
				bfsq.push(w2|cost);
			}
		}
	}
	int ans = -1;
	for(int i=0; i<1024; i++)
	{
		if(vis[e-1][i])
		{
			ans = i;
			break;
		}
	}
	cout << ans;
}
