#include <iostream>
#include <vector>

using namespace std;
int n, s, d, p;
vector<vector <int> > al;
vector<bool> vis;
bool f = false;
void dfs(int u)
{
	vis[u] = true;
	cout << "visiting " << u+1;
	if(u == d-1)
	{
		vis[u] = false;
		f = true;
		p++;
		return;
	}
	for(int i=0; i<al[u].size(); i++)
	{
		int v = al[u][i];
		if(vis[v] == false)
			dfs(v);
	}
	if(f)
		{
		vis[u] = false;
		cout << "backtr " << u+1;
		}
}
int main()
{
	int tc;
	cin >> tc;
	for(int t=0; t<tc; t++)
	{
		f = false; p = 0;
		cin >> n >> s >> d;
		al.resize(n); vis.resize(n);
		for (int i=0; i<n; i++ )
		{
			vis[i] = false;
		}
		for (int i = 0; i < n-1; ++i)
		{
			int u, v;
			cin >> u >> v;
			al[u-1].push_back(v-1);
			al[v-1].push_back(u-1);
		}
		dfs(s-1);
		cout << "ans: \n" << p;
	}

}
