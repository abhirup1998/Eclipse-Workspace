#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;
/*
 * trial input
7
9
1 7 20
7 3 10
3 4 30
4 5 3
4 2 5
5 2 1
2 1 10
5 6 6
1 6 2
 */
int n;
vector <vector <int> > alist, weights;
vector<int> distances;
void display_d();
void addEdge(int u, int v, int w)
{
	alist[u].push_back(v);
	weights[u].push_back(w);
}
void shortest_paths(int v)
{
	cout << "---- Shortest Path ----" << endl;
	bool visited[n+1];
	for (int i = 1; i <= n; ++i)
	{
		visited[i] = false;
	}
	distances[v] = 0;
	int u = v;
	for(int j = 1; j <= n; j++ )
	{
		int dmin = INT_MAX, k=1;
		for(unsigned i = 1; i < distances.size(); i++)
			if(distances[i] < dmin && visited[i] == false)
			{
				dmin = distances[i];
				k=i;
			}
		visited[k] = true;
		cout << "--v " << k << "    \t";
		display_d();
		u = k;
		for (unsigned i = 0; i < alist[u].size(); ++i)
		{
			int v = alist[u][i];
			if(!visited[v])
			{
				distances[v] = min(distances[v], distances[u] + weights[u][i]);
			}
		}
	}
}
void display()
{
	cout << "\n---- Adj List ----\n";
	for (int i = 1; i <= n; ++i)
	{
		for (unsigned j = 0; j != alist[i].size(); ++j)
		{
			cout << alist[i][j] << " ";
		}
		cout << endl;
	}
}
void display_d()
{
	for (unsigned i = 1; i != distances.size(); ++i)
		{
				cout << distances[i] << "\t";
		}
	cout << endl;
}
int main()
{
	int ch;
	cin >> n;
	alist.resize(n+1);
	weights.resize(n+1);
	distances.resize(n+1);
	fill(distances.begin(), distances.end(), 100);
	cin >> ch;
	do{
		int u, v, w;
		cin >> u >> v >> w;
		addEdge(u, v, w);
		ch--;
	}while(ch != 0);
	display();

	shortest_paths(1);
	display_d();
}
