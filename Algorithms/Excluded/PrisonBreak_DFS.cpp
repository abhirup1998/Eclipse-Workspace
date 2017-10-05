#include <iostream>
#include <vector>

using namespace std;
int n, p=0;
vector<vector <int> > maze;
int f = false;
//void display()
//{
//	for(int i=0; i<n; i++)
//	{
//		for(int j=0; j<n; j++)
//			cout << maze[i][j] << " ";
//		cout << endl;
//	}
//	cout << endl;
//}
void dfs(int r, int c)
{
	if(r==-1 || c==-1 || r==n || c==n || maze[r][c] == 1 || maze[r][c] == 2)
		return;
	maze[r][c] = 2;
	if(r == n-1 && c == n-1)
	{
		maze[r][c] = 0;
		f = true;p++;
		return;
	}
	dfs(r+1, c);
	dfs(r, c+1);
	dfs(r, c-1);
	dfs(r-1, c);
	if(f) maze[r][c] = 0;
}
int main()
{
	int tc;
	cin >> tc;
	for(int t=0; t<tc; t++)
	{
		cin >> n;
		p = 0;
		maze.resize(n);
		for(int i=0; i<n; i++)
		{
			maze[i].resize(n);
			for(int j=0; j<n; j++)
				cin >> maze[i][j];
		}
		dfs(0, 0);
		cout << p << endl;
	}
//	9
//	1 0 1 1 0 1 0 0 1
//	0 0 0 0 0 0 1 1 0
//	0 1 0 0 0 1 0 1 0
//	0 1 0 0 0 0 1 0 0
//	1 1 1 0 0 0 0 0 1
//	0 0 1 0 1 1 0 0 0
//	0 0 1 1 1 1 1 0 0
//	1 1 0 1 0 0 1 0 1
//	1 1 1 1 1 1 1 0 0
//	3
//	1 0 0
//	0 1 0
//	1 0 0
}

