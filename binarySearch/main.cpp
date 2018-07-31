#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

void binSearch(vector<int> & v, int a) {
  int first = 0; int last = v.size(); int mid;
  while (first < last) {
    mid = first + (last-first)/2;
    if (v[mid] == a) break;
    else if (v[mid] > a) last = mid-1;
    else first = mid+1;
  }
  if (v[mid] == a) {
    cout << a << " found at position: " << mid << endl;
  }
  else cout << "Not in the vector" << endl;
}

int main() {
  int n; cin >> n;
  vector<int> v(n,0);
  for (int i = 0; i < n; i++) cin >> v[i];
  int k,tmp; cin >> k;
  sort(v.begin(),v.end());
  for (int i = 0; i < k; i++) {
    cin >> tmp; binSearch(v,tmp);
  }
}
