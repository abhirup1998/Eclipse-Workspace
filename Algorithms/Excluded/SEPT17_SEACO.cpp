#include <iostream>
#include <vector>

using namespace std;

typedef struct queries{
	int t, l, r;
} ar;

void operate(int t, int l, int r, ar * ar, vector<int> &A)
{
	if(t == 1)
	{
		for(int i=l-1; i<r; i++)
			A[i]++;
		return;
	}
	else
	{
		for(int i=l-1; i<r; i++)
		{
			int t_ = ar[i].t;
			int l_ = ar[i].l;
			int r_ = ar[i].r;

			operate(t_, l_, r_, ar, A);
		}
	}
}

int main()
{
	int tc, t;
	cin >> tc;
	for(t=0; t<tc; t++)
	{
		int n, m;
		cin >> n >> m;
		vector <int> A(n);
		for(int k=0; k<n; k++)
			A[k] = 0;
		struct queries comm[m];
		for(int k=0; k<m; k++)
		{
			int t, l, r;
			cin >> t >> l >> r;
			comm[k].t = t;
			comm[k].l = l;
			comm[k].r = r;
			operate(t, l, r, comm, A);
		}
		for(int k=0; k<A.size(); k++)
			cout << A[k] << " ";
		cout << endl;
	}
}
