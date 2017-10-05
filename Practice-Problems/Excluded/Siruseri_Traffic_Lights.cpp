#include <vector>
#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;
/*
 * trial input
1 4
4 5
4 3 2 5
1 2 4
1 3 8
2 3 6
2 4 10
3 4 7
 */
int n;
vector <vector <int> > alist, weights;
vector<int> distances;
vector<int> T;
void addEdge(int u, int v, int w)
{
	alist[u].push_back(v);
	alist[v].push_back(u);
	weights[u].push_back(w);
	weights[v].push_back(w);
}
void shortest_paths(int src, int dest)
{
	bool visited[n+1];
	for (int i = 1; i <= n; ++i)
	{
		visited[i] = false;
	}
	distances[src] = 0;
	int u = src;
	for(int j = 1; j <= n; j++ )
	{
		int dmin = INT_MAX, k=0;
		for(unsigned i = 1; i < distances.size(); i++)
			if(distances[i] < dmin && visited[i] == false)
			{
				dmin = distances[i];
				k=i;
			}
		visited[k] = true;
		u = k;
		for (unsigned i = 0; i < alist[u].size(); ++i)
		{
			int v = alist[u][i];
			if(!visited[v])
			{
				if(v != dest)
				{
					int w = weights[u][i];
					int p = ceil((distances[u] + w) / (double)T[v]);
					int d = p * T[v];
					distances[v] = min(distances[v], d);
				}
				else distances[v] = min(distances[v], distances[u] + weights[u][i]);
			}
		}
	}
}

int main()
{
	int edges;
	int src, dest;
	cin >> src >> dest;
	cin >> n >> edges;
	alist.resize(n+1);
	weights.resize(n+1);
	distances.resize(n+1);
	T.resize(n+1);int in = 0;
	fill(distances.begin(), distances.end(), INT_MAX);
	for(int i = 1; i<=n; i++)
	{
		cin >> in;
		T[i] = in;
	}
	T[0] = 0;
	do{
		int u, v, w;
		cin >> u >> v >> w;
		addEdge(u, v, w);
		edges--;
	}while(edges != 0);

	shortest_paths(src, dest);
	cout << distances[dest] << endl;

}
