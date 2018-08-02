#include<iostream>
using namespace std;

template<class T>
class linkedList {
  private:
    struct node {
        node* next;
        T elem;
    };
    node* head;
    int size;
  public:
    linkedList() {
      size = 0; head = NULL;
    }

    int listSize() {
      return size;
    }

    void push(T elem) {
      node* newn = new node;
      if (size == 0) {
        head = newn;
      }
      else {
        node *n = head;
        while (n->next != NULL) {
          n = n->next;
        }
        n->next = newn;
      }
      newn->next = NULL;
      newn->elem = elem;
      size++;
    }

    T begin() {
      return head->elem;
    }

    void insert(int pos, T elem) {
      node* newn = new node;
      newn->elem = elem;
      pos = min(pos,size);
      size++;
      node * n = head;
      for (int i = 0; i < pos-1; i++) {
        n = n->next;
      }
      newn->next = n->next;
      n->next = newn;
    }

    T get(int pos) {
      if (pos >= size) {
        throw runtime_error("Index out of bounds");
      }
      node* n = head;
      for (int i = 0; i < pos; i++) n = n->next;
      return n->elem;
    }

    void deleteElement(int pos) {
      if (pos >= size) {
        throw runtime_error("Index out of bounds");
      }
      node* n = head; node* old;
      for (int i = 0; i < pos-1; i++) n = n->next;
      old = n->next;
      n->next = old->next;
      delete old;
      size--;
    }

};

int main() {
  int n; cin >> n;
  linkedList<int> ll; int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp; ll.push(tmp);
  }
  cout << "Head of the list: " << ll.begin() << endl;
  cout << "Size of the list: " << ll.listSize() << endl;
  cout << "Inserting a 44 " << endl; ll.insert(5,44);
  cout << "Elements of the list:";
  for (int i = 0; i < ll.listSize(); i++) {
    cout << " " << ll.get(i);
  }
  cout << endl << "Deleting the 44 and adding to the end of the list" << endl;
  ll.deleteElement(5); ll.insert(11115,44);
  cout << "Elements of the list:";
  for (int i = 0; i < ll.listSize(); i++) {
    cout << " " << ll.get(i);
  }
  cout << endl;
}
