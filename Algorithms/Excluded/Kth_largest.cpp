/*
 * Kth_largest.cpp
 *
 *  Created on: 23-Sep-2017
 *      Author: Abhirup Das
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
//#define left(i) 2*i+1
//#define right(i) 2*i+2
typedef struct heap{

	int len, hsize;
	vector<int> v;

}heap;
void maxheapify(int i, heap *h)
{
	int l = 2*i+1, r = 2*i+2;
	int largest = i;
	auto v = h->v.begin();
	if(l <= h->hsize && v[l] > v[largest])
		largest = l;
	if(r <= h->hsize && v[r] > v[largest])
		largest = r;
	if(largest != i)
	{
		int temp = v[largest];
		v[largest] = v[i];
		v[i] = temp;
		maxheapify(largest, h);
	}
}
void buildheap(heap *h)
{
	cout << "building.." << endl;
	h->hsize = h->len;
	for(int i = (h->hsize-1)/2; i>=0; i--)
		maxheapify(i, h);
}
int kthlargest(heap *h, int k)
{
	if(k <= 2) return h->v[0];
	for(int i=1; i<=k-1; i++)
	{
		h->v[0] = INT_MIN;
		buildheap(h);
	}
	return h->v[0];
}
void display(heap *h)
{
	cout << "=====================================\n";
	for(int i=0; i<h->hsize; i++)
		cout << h->v[i] << " ";
	cout << endl << "=====================================\n" << endl;
}
int main()
{
	int n, i;
	heap h;
	cin >> n;
	h.len = n;
	h.v.resize(n);
	for (i = 0; i < n; ++i) {
		cin >> h.v[i];
	}
	buildheap(&h);
	display(&h);
	cout << kthlargest(&h, 4);
}
