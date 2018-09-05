#include<iostream>
using namespace std;

// useful for applications that go around a list

template<class T>
class circularLinkedList {
  private:
    struct node {
        node* next;
        T elem;
    };
    node* head;
    int size;
  public:
    circularLinkedList() {
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
        while (n->next != head) {
          n = n->next;
        }
        n->next = newn;
      }
      newn->next = head;
      newn->elem = elem;
      size++;
    }

    T begin() {
      return head->elem;
    }

    void insert(int pos, T elem) {
      node* newn = new node;
      newn->elem = elem;
      if (pos == 0 && head == NULL) {
        head = newn;
				head->next = head;
      }
      else if (pos == 0) {
        newn->next = head;
        node * n = head;
        while(n->next != head) n = n->next;
        n->next = newn;
        head = newn;
      }
      else {
        pos = min(pos,size);
        node * n = head;
        for (int i = 0; i < pos-1; i++) {
          n = n->next;
        }
        newn->next = n->next;
        n->next = newn;
      }
      size++;
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
      if (pos == 0 && size == 1) {
        delete head; head = NULL;
      }
      else if (pos == 0) {
        node* n = head;
        for (int i = 0; i < size; i++) n = n->next;
        n->next = head->next;
        node* old = head; head = n->next;
        delete old;
      }
      else {
        node* n = head; node* old;
        for (int i = 0; i < pos-1; i++) n = n->next;
        old = n->next;
        n->next = old->next;
        delete old;
      }
      size--;
    }

};

int main() {
  int n; cin >> n;
  circularLinkedList<int> cll; int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp; cll.push(tmp);
  }
  cout << "Head of the list: " << cll.begin() << endl;
  cout << "Size of the list: " << cll.listSize() << endl;
  cout << "Inserting a 44 " << endl; cll.insert(5,44);
  cout << "Elements of the list:";
  for (int i = 0; i < cll.listSize(); i++) {
    cout << " " << cll.get(i);
  }
  cout << endl << "Deleting the 44 and adding to the end of the list" << endl;
  cll.deleteElement(5); cll.insert(11115,44);
  cout << "Elements of the list:";
  for (int i = 0; i < cll.listSize(); i++) {
    cout << " " << cll.get(i);
  }
  cout << endl;

  circularLinkedList<int> cll2;
  cll2.push(2); cll2.deleteElement(0);
  cll2.push(4); cll2.push(3); cll2.deleteElement(0);
  cout << "Elements of the list:";
  for (int i = 0; i < cll2.listSize(); i++) {
    cout << " " << cll2.get(i);
  }
  cout << endl;
}
