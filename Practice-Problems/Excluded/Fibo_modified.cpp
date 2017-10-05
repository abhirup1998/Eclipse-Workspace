/*
 * Fibo_modified.cpp
 *
 *  Created on: 01-Oct-ts17
 *      Author: Abhirup Das
 */
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
	int ts = 50;
	vector<short> a(ts),b(ts),f(ts);
	int n=0, na=0, nb=0, nf=0, j=ts-1 ,k=ts-1;
	char in[100];
	char c='0'; int i = 0;
	while(true){
		scanf("%c", &c);
		if(c == '\n' || c == '\0') break;
		in[i++] = c;
	}
	n = (int)in[i-1]-48; n-=2;
	i = i-3;
	while(in[i]!= ' ')
		b[k--] = (int)in[i--]-48;
	i--;
	while(i >= 0)
		a[j--] = (int)in[i--]-48;
	j++; k++;
	na = j; nb = k;
	while(n-- > 0)
	{
		fill(f.begin(), f.end(), 0);
		int li = ts-1, pi = ts-1, temp=0, l;
		for(l=ts-1; l>=nb; l--)
		{
			pi = li;
			for(int m=ts-1; m>=nb; m--)
			{
				f[pi] += b[m]*b[l] + temp;
				temp = f[pi]/10;
				f[pi] = f[pi] % 10;
				pi--;
			}
			li--;
			f[pi] += temp;
			temp=0;
		}
		int t=0;
		while(f[t] == 0)t++;
		nf = t;
		temp=0;
//		cout << endl << "F1 ";
//		for(l=nf; l<ts; l++)cout << f[l];
//		cout << endl;

		for(l=ts-1; l >= na-1; l--)
		{
			f[l] += a[l] + temp;
			temp = f[l] / 10;
			f[l] = f[l] % 10;
		}
		f[l] += temp;

//		cout << "F2 ";
//		for(l=nf; l<ts; l++)cout << f[l];
//		cout << endl;
		na = nb;
		for(l=nb; l<ts; l++) a[l] = b[l];
		nb = nf;
		for(l=nf; l<ts; l++) b[l] = f[l];
//		cout << "A ";
//		for(l=na; l<ts; l++)cout << a[l];
//		cout << endl << "B ";
//		for(l=nb; l<ts; l++)cout << b[l];
//		cout << endl;
//		cout << "N " << n << endl;
	}
	for(int l=nb; l<ts; l++)cout << b[l];
	cout << endl;
}
