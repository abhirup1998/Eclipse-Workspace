#include <bits/stdc++.h>
#include <vector>
using namespace std;

int len, ans=INT_MIN;
vector < vector < int > > al;
vector < int > value;

void dfs(int v, int maxsal)
{
	maxsal=max(maxsal, value[v]);
	ans=max(ans, maxsal-value[v]);
	for (int i=0; i < al[v].size(); i++)
		dfs(al[v][i], maxsal);
}

int main()
{
	int k = 0;
	int root = 0;
	cin >> len;
	al.resize(len+1);
	value.resize(len+1);
	for (int i=1; i<=len; i++)
		cin >> value[i];
	for (int i=1; i<=len; i++)
	{
		cin >> k;
		if (k==-1) root=i;
		else al[k].push_back(i);
	}
	dfs(root, value[root]);
	cout << ans;
	return 0;
}
