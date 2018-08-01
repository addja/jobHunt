#include<iostream>
#include<stack>
#include<queue>

using namespace std;

// LIFO data structure

template <class T>
class myStack {
  private:
    queue<T> q1, q2;
  public:
    int size() {
      return q1.size();
    }

    void push(T const& elem) {
        q1.push(elem);
    }

    void pop() {
      while(q1.size() > 1) {
        q2.push(q1.front());
        q1.pop();
      }
      q1.pop(); q1.swap(q2);
    }

    T top() {
      while(q1.size() > 1) {
        q2.push(q1.front());
        q1.pop();
      }
      T top = q1.front();
      if (q1.size() == 1) {
        q2.push(q1.front());
        q1.pop();
      }
      q1.swap(q2);
      return top;
    }

    bool empty() {
      return q1.empty();
    }

};

int main() {
  // std stack
  int n; cin >> n;
  stack<int> s; int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp; s.push(tmp);
  }
  cout << "Stack of size " << s.size() << endl;
  cout << "Popping out elements";
  while (s.size() > 3) {
    cout << ' ' << s.top(); s.pop();
  }
  cout << endl << "Now the top is: " << s.top() << endl;
  cout << "Pushing in a 7" << endl; s.push(7);
  cout << "Popping out the rest of the elements";
  while (!s.empty()) {
    cout << ' ' << s.top(); s.pop();
  }
  cout << endl;

  // double queue stack
  cin >> n;
  myStack<int> ms;
  for (int i = 0; i < n; i++) {
    cin >> tmp; ms.push(tmp);
  }
  cout << "Stack of size " << ms.size() << endl;
  cout << "Popping out elements";
  while (ms.size() > 3) {
    cout << ' ' << ms.top(); ms.pop();
  }
  cout << endl << "Now the top is: " << ms.top() << endl;
  cout << "Pushing in a 7" << endl; ms.push(7);
  cout << "Popping out the rest of the elements";
  while (!ms.empty()) {
    cout << ' ' << ms.top(); ms.pop();
  }
  cout << endl;

}
