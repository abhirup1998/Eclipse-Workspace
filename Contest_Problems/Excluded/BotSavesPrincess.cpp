/*
 * BotSavesPrincess.cpp
 *
 *  Created on: 18-Nov-2017
 *      Author: abhirup
 */
#include <iostream>
#include <vector>
using namespace std;
void nextMove(int n, int y, int x, vector <string> grid){
	int px = -1, py  = -1, i=0;
	for( i=0; i < n;)
	{
		px = grid[i].find('p');
		if(px == string::npos)
			i++;
		else
			break;
	}
	py = i;
	if(px < x)
		cout << "LEFT\n";
	else if(px > x)
		cout << "RIGHT\n";
	else if(py < y)
		cout << "UP\n";
	else if(py > y)
		cout << "DOWN\n";
}
int main(void) {

	int n, r, c;
	vector <string> grid;

	cin >> n;
	cin >> r;
	cin >> c;

	for(int i=0; i<n; i++) {
		string s; cin >> s;
		grid.push_back(s);
	}

	nextMove(n, r, c, grid);
	return 0;
}

