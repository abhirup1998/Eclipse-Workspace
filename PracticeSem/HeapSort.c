/*
 * HeapSort.c
 *
 *  Created on: 30-Nov-2017
 *      Author: abhirup
 */
#include <stdio.h>
int hs, len;
void maxHeapify(int*ar, int i)
{
	// printf("Maxing at %d\n", i);
	int l = 2*i +1;
	int r = 2*i +2;
	int largest =i;
	if(l < hs && ar[l] > ar[largest])
		largest = l;
	if(r < hs && ar[r] > ar[largest])
		largest = r;
	if(largest != i)
	{
		int temp = ar[largest];
		ar[largest] = ar[i];
		ar[i] = temp;
		maxHeapify(ar, largest);
	}
}
void buildHeap(int *ar)
{
	printf("Building Heap..\n");
	hs = len;
	for(int i=(hs-1)/2; i>=0; i--)
		maxHeapify(ar, i);
}
void heapsort(int *ar)
{
	buildHeap(ar);
	while(hs > 0)
	{
		int temp = ar[0];
		ar[0] = ar[hs-1];
		ar[hs-1] = temp;
		hs--;
		maxHeapify(ar, 0);
	}
	for(int i=hs; i<len; i++)
		printf("%d ", ar[i]);
	printf("\n");
}
int main()
{
	len=0;
	scanf("%d", &len);
	int ar[len];
	for(int i=0; i<len; i++)
		scanf("%d", &ar[i]);
	buildHeap(ar);
	for(int i=0; i<len; i++)
		printf("%d ", ar[i]);
	printf("\n");
	heapsort(ar);
}
