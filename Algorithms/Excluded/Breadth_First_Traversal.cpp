#include <iostream>
#include <deque>

using namespace std;
void print_queue(deque<int> q)
{
	while(!q.empty())
	{
		cout << q.front() << " ";
		q.pop_front();
	}
	cout << endl;
}
void bfs(int G[7][7], int num, int v)
{
	deque <int> Q;
	int visited[num+1], parent[num+1];
	for (int i = 1; i <= num; ++i) {
		visited[i] = 0;
		parent[i] = -1;
	}
	visited[v] = 1;parent[v] = -100;
	Q.push_back(v);

	while(! Q.empty())
	{

		int u = Q.front();
		cout << "u -->> " << Q.front() << endl;
		Q.pop_front();
		for (int j = 0; j < num; ++j)
		{
			if(visited[j+1] == 0 && G[u-1][j] == 1)
			{
				Q.push_back(j+1);
				visited[j+1] = 1;
				parent[j+1] = u;
			}
		}
		print_queue(Q);
		cout << "Visited[]  " ;
		for (int j = 1; j < num+1; ++j) {
			cout << visited[j] << " ";
		}
		cout << endl;

	}
	cout << "PARENTS ";
	for (int j = 1; j <= num; ++j) {
		cout << parent[j] << " ";
	}
	cout << endl;
}

int main()
{
	int G[7][7] = {
			{ 0, 1, 0, 1, 0, 0, 0},
			{ 1, 0, 1, 0, 0, 1, 0},
			{ 0, 1, 0, 0, 1, 0, 0},
			{ 1, 0, 0, 0, 0, 1, 0},
			{ 0, 0, 1, 0, 0, 0, 1},
			{ 0, 1, 0, 1, 0, 0, 1},
			{ 0, 0, 0, 0, 1, 1, 0}
	};
	bfs(G, 7, 1);
}
