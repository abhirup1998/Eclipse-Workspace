#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
vector<vector<int> > al;
vector<vector<int> > arr;
void display(int *a, int n)
{
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int xoc(int, int*);
int main()
{
	int n, Q;
	cin >> n >> Q;
	al.resize(n);
	arr.resize(Q);
	int que[Q];
	for(int i=0; i<n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		al[u].push_back(v);
	}
	int p;
	for(int i=0; i<n; i++)
	{
		cin >> p;
		arr[0].push_back(p);
	}

	int max = 0;
	for(int i=0; i<Q; i++)
	{
		cin >> que[i];
		if(max < que[i])max = que[i];
	}

	arr.resize(max+1);
	for(int i=0; i<max; i++)
	{
		int ar[n];
		for(int j=0; j<n; j++)
			ar[j] = arr[i][j];
		xoc(0, ar);
		for(int j=0; j<n; j++)
			arr[i+1].push_back(ar[j]);
	}


	for(int i=0; i<Q; i++)
	{
		cout << arr[que[i]][0] << " ";
		cout << endl;
	}
}
int xoc(int n, int * arr)
{
	int u = n, res = arr[n];
	if(al[u].empty())
		return arr[n];
	for(int j=0; j<al[u].size(); j++)
	{
		int v = al[u][j];
		res = res ^ xoc(v, arr);
	}
	arr[n] = res;
	return res;
}

