/*
 * MinimumPenaltyPath.cpp
 *
 *  Created on: 24-Sep-2017
 *      Author: Abhirup Das
 *  Problem link:
 *  https://www.hackerrank.com/challenges/beautiful-path?h_r=internal-search
3 4
1 2 1
1 2 1000
2 3 3
1 3 100
1 3
Output = 3
 */
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
using namespace std;
int n;
//typedef long long ll;
typedef pair<int,int>  pr;
vector<vector<pr> > v;
vector <bool> vis;
vector<int> penalty;
void display_d()
{
	for (unsigned i = 1; i < penalty.size(); ++i)
		{
				cout << penalty[i] << "\t";
		}
	cout << endl;
}
class mycomp{
public:
	bool operator ()(const pr &A, const pr &B) const
	{
		return A.second > B.second;
	}
};
void min_penalty_path(int s, int e)
{
	vis[s] = true;
	penalty[s] = 0;
//	cout << "Creating pqueue..";
	priority_queue<pr, vector<pr>, mycomp > pq;

	for(int i = 1; i <= n; i++)
		pq.push(make_pair(i, penalty[i]));
//	cout << "Created!" << endl;
	for(int i = 1; i<=n && !pq.empty(); i++)
	{
		pr a = pq.top();
		pq.pop();
		int k = a.first;
//		cout << "Min @ " << k << endl;
		vis[k] = true;
		for(int j = 0; j<v[k].size(); j++)
		{
			int vn = v[k][j].first;
			if(!vis[vn])
			{
				penalty[vn] = min(penalty[vn], (int)(penalty[k] | v[k][j].second));
				pq.push(make_pair(vn, penalty[vn]));
			}
		}
//		display_d();
	}
}
int main()
{
	int m;
	cin >> n >> m;
	v.resize(n+1); vis.resize(n+1); penalty.resize(n+1);
	for(int i = 1; i<=n; i++)
	{
		vis[i] = false;
		penalty[i] = INT_MAX;
	}
	for(int i = 0; i<m; i++)
	{
		int x,y, z;
		cin >> x >> y >> z;
		v[x].push_back(make_pair(y, z));
		v[y].push_back(make_pair(x, z));
	}
//	cout << endl;
//	for(int i=1 ; i<v.size(); i++)
//	{
//		cout << i << "th .. ";
//		for(int j=0; j<v[i].size(); j++)
//			cout << v[i][j].first << "," << v[i][j].second << "   ";
//		cout << endl;
//	}
	int s, e;
	cin >> s >> e;
	min_penalty_path(s, e);
	if(!(penalty[e] == INT_MAX)) cout << penalty[e];
	else cout << -1;

}
