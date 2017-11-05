/*
 * KMP.cpp
 *
 *  Created on: 05-Nov-2017
 *      Author: abhirup
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void sufprof(string p, vector<int> &temp)//O(m)
{
	int i=1, j=0;
	temp[0] = 0;
	while(i < p.size())
		if(p[j] == p[i])
			temp[i++] = (j++) +1;
		else
		{
			if(j == 0)
				temp[i++] = 0;
			j = j>0?temp[j-1]:0;
		}
}
int findSubstring(string t, string p)
{
	int n = t.size(), m=p.size();
	vector<int> temp(m);
	sufprof(p, temp);
	for(auto ch:p)
		cout << ch << " ";
	cout << endl;
	for(auto t:temp)
		cout << t << " ";
	cout << endl;
	int ptr=0, occ=0, i=0;
	while(i<n)//O(n)
	{
		if(p[ptr] == t[i])
		{
			i++; ptr++;
		}
		if(ptr == m)
		{
			cout << "Found at "<< i-ptr<< endl;
			ptr = temp[ptr-1];
			occ++;
		}
		else if(i < n && p[ptr]!=t[i])
		{
			if(ptr==0)
				i++;
			ptr = temp[ptr-1];
		}
	}
	return occ;
}
int main()
{
	string t, p;
	cin >> t;
	cin >> p;
	int in, occ;
	occ = findSubstring(t,p);
	cout << occ;
}
