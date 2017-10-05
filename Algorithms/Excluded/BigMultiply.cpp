/*
 * BigMultiply.cpp
 *
 *  Created on: 01-Oct-2017
 *      Author: Abhirup Das
 */

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
typedef unsigned long long ull;
vector<short> mul(vector<short> &m, vector<short> &q)
		{
			vector<short> p(m.size() + q.size());
			int k = p.size()-1, nxt = p.size()-1, temp = 0;
			for(int i = q.size()-1; i>=0; i--)
			{
				k = nxt;
				for(int j = m.size()-1; j>=0; j--)
				{
					p[k] += q[i] * m[j] + temp;
					temp = p[k]/10;
					p[k] = p[k] % 10;
					cout << "AMul --" << p[k] << " " << q[i] << " X "
					<< m[j] << " carry= " << temp << "       ||| ";
					for(int i = 0; i<p.size(); i++)
						cout << p[i] << " ";
					cout << "|||" << endl;
					k--;
				}
				p[k] = temp;
				temp=0;
				nxt--;
			}
			int i = 0;
			for( i = 0; i<p.size(); i++)
				if(p[i] != 0)break;
			vector<short> t(p.begin()+i, p.end());
			return t;
		}
vector<short> mul2(vector<short> &m, vector<short> &q)
		{
			vector<short> p(m.size() + q.size());
			int k = p.size()-1, nxt = p.size()-1, temp = 0;
			for(int i = q.size()-1; i>=0; i--)
			{
				k = nxt;
				for(int j = m.size()-1; j>=0; j--)
				{
					p[k] += q[i] * m[j] + temp;
					temp = p[k]/10;
					p[k] = p[k] % 10;
					cout << "AMul --" << p[k] << " " << q[i] << " X "
					<< m[j] << " carry= " << temp << "       ||| ";
					for(int i = 0; i<p.size(); i++)
						cout << p[i] << " ";
					cout << "|||" << endl;
					k--;
				}
				p[k] = temp;
				temp=0;
				nxt--;
			}
			int i = 0;
			for( i = 0; i<p.size(); i++)
				if(p[i] != 0)break;
			vector<short> t(p.begin()+i, p.end());
			return t;
		}
//vector<short> add(vector<short> &a, vector<short> &b)
//		{
//			vector<short> ar[5], c(max(b.size(), a.size())+1);
//			int i = a.size()-1, j = b.size()-1, k = c.size()-1;
//			while(i >= 0 && j >= 0)
//			{
//				c[k--] =
//			}
//		}
int main()
{
	vector<short> a, b;
	char c='0';
	while(true){
		c = getchar();
		if(c == '\n' || c == '\0' || c==' ') break;
		a.push_back((int)(c-48));
	}
	while(true){
		c = getchar();
		if(c == '\n' || c == '\0' || c==' ') break;
		b.push_back((int)(c-48));
	}
	for (int i = 0; i < a.size(); ++i)
	{
		/* code */cout << a[i];
	}
	cout << endl;
	for (int i = 0; i < b.size(); ++i)
	{
		/* code */cout << b[i];
	}
	cout << endl;
	vector<short> s = mul(b,a);
	for(int i=0; i<s.size(); i++)
		cout << s[i];
	cout << endl;
	return 0;
}
// int main ()
// {
//   int c;
//   puts ("Enter text. Include a dot ('.') in a sentence to exit:");
//   do {
//     c=getchar();
//     putchar (c);
//   } while (c != '.');
//   return 0;
// }
