#include<iostream>
#include<vector>
#include<stdlib.h>
#include<queue>

using namespace std;

void printVector(vector<int> & v) {
	for(auto e: v) cout << e << " ";
	cout << endl;
}

void insertionSort(vector<int> & v) {
	vector<int> aux;
	bool inserted;
	for (int i = 0; i < (int)v.size(); i++) {
		inserted = false;
		for (int j = 0; j < (int)aux.size(); j++) {
			if (v[i] < aux[j]) {
				aux.push_back(42); // magic number
				for (int k = (int)aux.size()-1; k >= j; k--) {
					aux[k+1] = aux[k];
				}
				aux[j] = v[i];
				inserted = true;
				break;	
			}
		}
		if (!inserted) aux.push_back(v[i]);
	}
	v = aux;
}

void mergeSort(vector<int> & v) {
	if (v.size() < 2) return;
	vector<int> v1, v2;
	int s = v.size()/2;	
	for (int i = 0; i < s; i++) v1.push_back(v[i]);
	for (int i = s; i < (int)v.size(); i++) v2.push_back(v[i]);
	mergeSort(v1);
	mergeSort(v2);
	int i = 0; int j = 0;
	while (i < (int)v1.size() && j < (int)v2.size()) {
		if (v1[i] > v2[j]) {
			v[i+j] = v2[j];
			j += 1;
		}
		else {
			v[i+j] = v1[i];
			i += 1;
		}
	}
	while (i < (int)v1.size()) {
			v[i+j] = v1[i];
			i += 1;
	}
	while (j < (int)v2.size()) {
			v[i+j] = v2[j];
			j += 1;
	}
}

void bubbleSort(vector<int> & v) {
	int end = v.size();
	while (end > 1) {
		for (int i = 0; i < end-1; i++) {
			if (v[i] > v[i+1]) swap(v[i],v[i+1]);	
		}
		end--;
	}	
}

void selectionSort(vector<int> & v) {
	int idx;
	for (int i = 0; i < (int)v.size(); i++) {
		idx = i;
		for (int j = i+1; j < (int)v.size(); j++) {
			if (v[j] < v[idx]) idx = j;
		}
		if (idx != i) swap(v[i],v[idx]);
	}
}

int pivot(vector<int> & v, int lo, int hi, int p) {
	while (lo <= hi) {
		while (v[lo] < p) lo++; 
		while (v[hi] > p) hi--; 
		if (lo <= hi) {
			swap(v[lo],v[hi]);
			lo++; hi--;
		}
	}
	return lo;
}	

void quickSort(vector<int> & v,int lo, int hi) {
	if (lo >= hi) return;
	int p = rand() % (hi-lo) + lo;	
	int mid = pivot(v,lo,hi,v[p]);
	quickSort(v,lo,mid-1);
	quickSort(v,mid+1,hi);
}

void heapSort(vector<int> & v) {
	priority_queue<int> q; // this is underneath a heap
	for (auto e: v) q.push(e);
	for (int i = v.size()-1; i >= 0; i--) {
		v[i] = q.top(); q.pop();	
	}
}

int main() {
	int n; cin >> n;
	vector<int> v(10);
	for (int i = 0; i < n; i++) cin >> v[i];

	cout << "The original vector is: ";
	printVector(v);

	vector<int> sam(v);

	cout << "Insertion sort: ";
	insertionSort(sam);
	printVector(sam);

	sam = v;
	cout << "Merge sort: ";
	mergeSort(sam);
	printVector(sam);

	sam = v;
	cout << "Bubble sort: ";
	bubbleSort(sam);
	printVector(sam);

	sam = v;
	cout << "Selection sort: ";
	selectionSort(sam);
	printVector(sam);

	sam = v;
	cout << "Quick sort: ";
	quickSort(sam,0,n-1);
	printVector(sam);

	sam = v;
	cout << "Heap sort: ";
	heapSort(sam);
	printVector(sam);

}
