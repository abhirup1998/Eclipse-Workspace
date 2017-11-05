/*
 * Segment Trees.cpp
 *
 *  Created on: 05-Nov-2017
 *      Author: abhirup
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int buildST(int node, int b, int e, const vector<int> &A, vector<int> &ST)
{

	if(b==e)
	{
		ST[node] = A[b];
	}
	else
	{
		int l=buildST(node*2+1, b, (b+e)/2, A, ST);
		int r=buildST(node*2+2, (b+e)/2 + 1, e, A, ST);
		cout << l << " "<< r<< endl;
		ST[node] = l+r;
	}
	cout <<b<< "," << e<< " = "<<ST[node] << endl;
	return ST[node];
}
int query(int node, int b, int e, int i, int j,const vector<int> &ST)
{
	if(b > j || e < i)
		return 0;
	if(b>=i && e<=j)
		return ST[node];
	int l = query(node*2+1, b, (b+e)/2, i, j, ST),
		r = query(node*2+2, (b+e)/2+1, e, i, j, ST);
	return l+r;
}
void update(int node,int b, int e,int i, int diff, vector<int> &ST)
{
	ST[node]+=diff;
	for(auto s:ST)
	{
		cout << s << " ";
	}
//	cout << "updating "<<
	cout<< endl;
	if(b < e)
	{
		if(i <= (b+e)/2)
			update(node*2+1, b, (b+e)/2, i, diff, ST);
		else
			update(node*2+2, (b+e)/2+1, e, i, diff, ST);
	}
//	ST[node]+=diff;
//	cout << "at " <<

}
int main()
{
	int n;
	cin >> n;
	vector<int> A(n);
	vector<int> ST(2*pow(2, log(n)/log(2)+1), 0);
	for(auto &a:A)cin >> a;
	for(auto a:A)cout << a << " ";
	cout << endl;
	cout<< "Input done. Now building..\n";
	buildST(0, 0, n-1, A, ST);
	int i=0,j=1;
	while(1)
	{
		cout<< "Querying\n";
		cin >> i >> j;
		if(i==j)break;
		cout << "ans= " << query(0, 0, n-1, i, j, ST)<< endl;
	}
	int in, val;
	while(1){
		cout << endl << "Updating..\n";
		cin >> in >> val;
		if(in == 0)
			break;
		update(0, 0, n-1, in, val-A[in], ST);
		A[in] = val;
		for(auto s:ST)
			cout << s << " ";
	}

}
