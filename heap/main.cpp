#include<vector>
#include<iostream>

using namespace std;

// Min heap:
// - complete tree (all levels complete but maybe the last level
//    which has all the leaves on the leaftmost possible positions)
// - the root has the minimum possible value
// - implemented in an array
// - root a[0]
// - parent of i: a[(i-1)/2]
// - left child of i: a[2i+1]
// - right child of i: a[2i+2]

template <class T>
class minHeap {
  private:
    vector<T> v;

    void heapifyUp() {
      int index = v.size()-1;
      while (index > 0) {
        int pa = parent(index);
        if (v[index] > v[pa]) return;
        swap(v[index],v[pa]);
        index = pa;
      }
    }

    void heapifyDown() {
      int index = 0;
      while ((uint)index < v.size()) {
        int ch = left(index);
        if (v[ch] > v[right(index)]) ch = right(index);
        if (v[ch] > v[index]) return;
        swap(v[index],v[ch]);
        index = ch;
      }
    }
  public:
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return 2*i+1; }
    int right(int i) { return 2*i+2; }
    int getMin() { return v[0]; }

    void insertKey(T k) {
      v.push_back(k);
      heapifyUp();
    }

    T extractMin() {
      T minVal = v[0];
      v[0] = v[v.size()-1]; v.pop_back();
      heapifyDown();
      return minVal;
    }
};

int main() {
  minHeap<int> h;
  h.insertKey(11);
  h.insertKey(3);
  h.insertKey(2);
  h.insertKey(15);
  h.insertKey(5);
  h.insertKey(4);
  h.insertKey(45);
  cout << h.extractMin() << " " << endl;
  cout << h.getMin() << " " << endl;
  h.insertKey(1);
  cout << h.getMin() << " " << endl;
}
