#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
inline int denom(int x)
{
	return x/5 +(x%5)/2 + (x%5)%2;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int tc, minm;
	cin >> tc;
	for(int t=0; t<tc; t++)
	{
		int n,en,k;
		cin >> n;
		vector<int> choc(n);
		for(k=0; k<n; k++)
		{
			cin >> choc[k];
		}
		sort(choc.begin(), choc.end());
		vector<int> ch(n);
		en=0;
		for(k = 0; k<choc.size();)//getting rid of repetitions
		{
			while(choc[k] == choc[k+1])
				k++;
			if(k < choc.size())
				ch[en++] = choc[k++];
		}
		minm = *ch.begin();
		ch.resize(en);
		vector<int> range(6);
		for(int i=0; i<6; i++)
		{
			for(int j=0; j<en; j++)
			{
				int d = denom((ch[j] - (minm - i)));
				range[i] += d;
			}
		}
		minm = INT_MAX;
		for(k=0; k<6; k++)
			if(range[k] < minm)
				minm = range[k];
		cout << minm << endl;
	}


}
