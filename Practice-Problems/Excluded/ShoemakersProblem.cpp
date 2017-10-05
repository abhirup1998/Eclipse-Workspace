
#include <iostream>
using namespace std;
struct query{
	int T, S, in;
};
int asc_compare(query a, query b)
{
	if(a.S * b.T < b.S * a.T)
		return 1;
	else
		return 0;
}
void mergeHalves(query *q, query *a, int m, query *b, int n)
{

	int i = 0, j = 0, k = 0;
	query p[m], s[n];
	for (int i = 0; i < m; ++i) {
		p[i] = a[i];
	}
	for (int i = 0; i < n; ++i) {
		s[i] = b[i];
	}
	while(j < n && i < m)
	{
		if(asc_compare(p[i], s[j]))
			q[k++] = s[j++];
		else
			q[k++] = p[i++];
	}
	while(i < m)
		q[k++] = p[i++];
	while(j < n)
		q[k++] = s[j++];
}
query* mergeSort(query *q, query *end)
{
	if(end - q == 1) { return q;}
	int mid = (end - q)>>1;
	query *p = mergeSort(q, q + mid),
			*s = mergeSort(q + mid, end);
	mergeHalves(q, p, mid, s, end - q - mid);
	return q;
}

int main()
{
	int n = 0;
	cin >> n;
	query q[n];
	for (int i = 0; i < n; ++i) {
		cin >> q[i].T >> q[i].S;
		q[i].in = i+1;
	}
	query *b = mergeSort(q, q + n);
	for (int i = 0; i < n; ++i) {
		cout << b[i].in << endl;
	}
	return 0;

}
