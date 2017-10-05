/*
 * ShortestReach_BFS.cpp
 *
 *  Created on: 24-Sep-2017
 *      Author: Abhirup Das
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++)
    {
        int n;
        int m;
        cin >> n >> m;
        vector<vector<int> > v(n);
        vector<bool> vis(n);
        vector<long> d(n);
        fill(vis.begin(), vis.end(), false);
        fill(d.begin(), d.end(), -1);
        for(int a1 = 0; a1 < m; a1++){
            int x, y;
            cin >> x >> y;
            v[x-1].push_back(y-1);
            v[y-1].push_back(x-1);
        }
        int s;
        cin >> s;
        queue<int> q; long prv_level = 0;
        q.push(s-1); d[s-1] = 0;
        vis[s-1] = true;
        while(!q.empty())
        {
        	int u = q.front(); q.pop();
        	for(int i=0; i<v[u].size(); i++)
        	{
        		int vn = v[u][i];
        		if(!vis[vn])
        		{
        			d[vn] = prv_level + 6;
        			q.push(vn);
        			vis[vn] = true;
        		}
        	}
        	prv_level += 6;
        }
        for(int i=0; i<d.size(); i++)
        	if(i != s-1) cout << d[i] << " ";
        cout << endl;
    }
    return 0;
}
