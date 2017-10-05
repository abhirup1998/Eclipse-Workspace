#include <iostream>
//#include <vector>
using namespace std;
int count;
//vector<pair<int,int> > inv;
void mergeCount(int *s, int *p, int m, int *q, int n)
{
	int i = 0, j = 0, k = 0, a[m], b[n];
	for(i=0; i<m; i++)
		a[i] = p[i];
	for(i=0; i<n; i++)
		b[i] = q[i];
	i = 0;
	while(j < n && i < m)
		{
			if(a[i] <= b[j])
				s[k++] = a[i++];
			else
			{
				s[k++] = b[j];
//				for(int p = i; p<m; p++)
//					inv.push_back(make_pair(b[j], a[p]));
				count += m-i;
				j++;
			}
		}
		while(i < m)
		{
			s[k++] = a[i++];
		}
		while(j < n)
		{
			s[k++] = b[j++];
		}
}
int* mergeSort(int *s, int *e)
		{
			int len = e-s;
			if(e-s==1)return s;
			int mid = (e-s)/2;
			int *p = mergeSort(s, s+mid), *q = mergeSort(s+mid, e);

			mergeCount(s, p, mid, q, len-mid);

			return s;
		}

int main()
{
	int tc;
	cin >> tc;
	for(int j=0; j<tc; j++)
	{
		int n;
		cin >> n;
		int one[n];
		count = 0;
		for(int i=0; i<n; i++)
		{
			cin >> one[i];
		}
		//	int* nxt;
		//	nxt = mergeSort(one, one+n);
		//	for(int i=0; i<n; i++)
		//		cout << nxt[i] << " ";
		//	cout << endl;
		//	for(int i=0; i<inv.size(); i++)
		//		cout << "(" << inv[i].first<< ", " << inv[i].second << ")" << " ";
		//	cout << endl;
		mergeSort(one, one+n);
		cout << count << endl;
	}
	return 0;
}
