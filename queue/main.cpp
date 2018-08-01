#include<iostream>
#include<stack>
#include<queue>

using namespace std;

// FIFO data structure

template <class T>
class myQueue{
  private:
    stack<T> s1, s2;
  public:
    int size() {
      return s1.size();
    }

    void push(T const& elem) {
        s1.push(elem);
    }

    void pop() {
      while(s1.size() > 1) {
        s2.push(s1.top());
        s1.pop();
      }
      s1.pop();
      while(!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
      }
    }

    T front() {
      while(s1.size() > 1) {
        s2.push(s1.top());
        s1.pop();
      }
      T front = s1.top();
      if (s1.size() == 1) {
        s2.push(s1.top());
        s1.pop();
      }
      while(!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
      }
      return front;
    }

    bool empty() {
      return s1.empty();
    }

};

int main() {
  // std queue
  int n; cin >> n;
  queue<int> q; int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp; q.push(tmp);
  }
  cout << "Stack of size " << q.size() << endl;
  cout << "Popping out elements";
  while (q.size() > 3) {
    cout << ' ' << q.front(); q.pop();
  }
  cout << endl << "Now the front is: " << q.front() << endl;
  cout << "Pushing in a 7" << endl; q.push(7);
  cout << "Popping out the rest of the elements";
  while (!q.empty()) {
    cout << ' ' << q.front(); q.pop();
  }
  cout << endl;

  // double queue stack
  cin >> n;
  myQueue<int> mq;
  for (int i = 0; i < n; i++) {
    cin >> tmp; mq.push(tmp);
  }
  cout << "Stack of size " << mq.size() << endl;
  cout << "Popping out elements";
  while (mq.size() > 3) {
    cout << ' ' << mq.front(); mq.pop();
  }
  cout << endl << "Now the front is: " << mq.front() << endl;
  cout << "Pushing in a 7" << endl; mq.push(7);
  cout << "Popping out the rest of the elements";
  while (!mq.empty()) {
    cout << ' ' << mq.front(); mq.pop();
  }
  cout << endl;

}
