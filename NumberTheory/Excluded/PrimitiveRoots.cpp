/*
 * PrimitiveRoots.cpp
 *
 *  Created on: 30-Oct-2017
 *      Author: abhirup
 */
/************************InCOMPLETE*********************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int modexp(int a, int b, int m)
{
	int res=1;
	while(b > 0)
	{
		if(b&1)
		{
			res = (res*a)%m;
		}
		a = (a*a)%m;
		b = b >> 1;
	}
	return res;
}
//int main() {
//	int p;
//	cin >> p;
//	vector<bool> v(p);
//	vector<int> roots;
//	for(int i=1; i<p; i++)
//	{
//		bool flag = true;
//		fill(v.begin(), v.end(), false);
////		cout  << i << " -- " << endl;
//		for(int x=0; x<=p-2; x++)
//		{
//			int me = modexp(i, x, p);
////			cout << "     " << x << "  " << me << endl;
//			if(v[me] == true)
//			{
//				flag = false;
//				break;
//			}
//			v[me] = true;
//		}
//		if(flag)roots.push_back(i);
////		cout << flag << endl;
////		for(auto x:v)cout << x << " ";
////		cout << endl;
//	}
//	cout << roots[0] << " " << roots.size();
//	return 0;
//}

int mmi_iterative(int a , int m)
{
	int x_=1, x = 0;//ax_ + mx = 1 (mod m)
	int m_copy = m;
	if(m == 1)
	{
		return 0;
	}
	while(a > 1)
	{
		int prev = m, q = a/m;
		m = a % m;
		a = prev;

		prev = x;
		x = x_ - q*x;
		x_ = prev;
	}
	if(x_ < 0)
	{
		x_ += m_copy;
	}
	return x_;
}
int main()
{
	int t;cin >> t;
	while(t-->=1){
	int n;
	cin >> n;
	cout << "--"<< n << "--"<<endl;
	vector<int> pr;
	for(int i=1; i<=n-1; i++)
	{
		set<int> s;
		s.insert(1);
		int g = 1; bool flag=true;
		for(int j=1; j<=n-2; j++)
		{
			g = (g*i)%n;
			if(s.find(g) == s.end())
				s.insert(g);
			else
				{
				flag=false;
				break;
				}
//			for(auto t=s.begin(); t!=s.end(); t++)
//				cout << *t << " ";
//			cout << endl;
		}
		if(flag && s.size()==n-1) pr.push_back(i);
	}
	for(auto i:pr)
		cout << i << " ";
	cout << endl;
	}
}
