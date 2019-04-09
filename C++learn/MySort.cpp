#include "MySort.h"

static int i = 0;
void QuickSort(vector<int>& v, int low, int high) {
	if (low >= high) return;
	int first = low;
	int last = high - 1;
	int key = v[first];
	while (first<last)
	{
		while (first < last && v[last] >= key)
			last--;
		if (first < last)
			v[first] = v[last];

		while (first < last && v[first] <= key)
			first++;
		if (first < last) v[last--] = v[first];
	}
	v[first] = key;
	i++;
	QuickSort(v, low, first - 1);
	QuickSort(v, first + 1, high);
}


void max_HeapSort(vector<int> &v, int low, int high) {
	int parent = low;
	int child = 2*parent+1;
	while (child <= high) {
		if (child + 1 <= high && v[child] < v[child + 1])
			child++;
		if (v[child] < v[parent]) return;
		else{
			swap(v[child], v[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
	}
}
void HeapSort(vector<int> &v,int low,int high) {
	int len = high;
	for (int i = len / 2 - 1; i >= low; i--) {
		max_HeapSort(v, i, len - 1);
	}
	for (int i = len - 1; i > low; i--) {
		swap(v[0], v[i]);
		max_HeapSort(v, 0, i - 1);
	}
}

