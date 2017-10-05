#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define N 4

bool isValidCell(int x, int y)
{
	if(x<0 || y<0 || x>=N || y>=N)
		return false;
	return true;
}
void countPaths(int maze[N][N], int x, int y, bool visited[N][N], int& count)
{
	if(x == N-1 && y == N-1)
	{

		count++;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
				cout << visited[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		return;
	}
	visited[x][y] = 1;
	if(isValidCell(x, y) && maze[x][y])
	{
		if(!visited[x+1][y])
			countPaths(maze, x+1, y, visited, count);
		if(!visited[x-1][y])
			countPaths(maze, x-1, y, visited, count);
		if(!visited[x][y+1])
			countPaths(maze, x, y+1, visited, count);
		if(!visited[x][y])
			countPaths(maze, x, y-1, visited, count);
	}
	visited[x][y] = 0;
}

int main()
{
	int maze[N][N] =
	{
			{1, 1, 1, 1},
			{1, 1, 0, 1},
			{0, 1, 0, 1},
			{1, 1, 1, 1}
	};
	int count = 0;
	bool visited[N][N];
	memset(visited, 0, sizeof visited);
//	for(int i = 0; i < N; i++)
//		for(int j = 0; j < N; j++)
//			visited[i][j] = false;
	countPaths(maze, 0, 0, visited, count);
	cout << "No of paths " << count;
	return 0;
}


















