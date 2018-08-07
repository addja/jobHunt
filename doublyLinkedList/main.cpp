#include<iostream>
using namespace std;


template<class T>
class doublyLinkedList {
  private:
    struct node {
        node* next;
        node* prev;
        T elem;
    };
    node* head;
    int size;
  public:
    doublyLinkedList() {
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
        n->next = newn; newn->prev = n;
      }
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
        head = newn; return;
      }
      else if (pos == 0) {
        newn->next = head;
        head->prev = newn;
        head = newn;
      }
      else {
        pos = min(pos,size);
        node * n = head;
        for (int i = 0; i < pos-1; i++) n = n->next;
        newn->next = n->next;
        newn->prev = n;
        n->next = newn;
        if (newn->next != NULL) {
          newn->next->prev = newn;
        }
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
        node* old = head; head = head->next;
        head->prev = NULL;
        delete old;
      }
      else {
        node* n = head; node* old;
        for (int i = 0; i < pos-1; i++) n = n->next;
        old = n->next;
        n->next = old->next;
        if (old->next != NULL) old->next->prev = n;
        delete old;
      }
      size--;
    }

};

int main() {
  int n; cin >> n;
  doublyLinkedList<int> dll; int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp; dll.push(tmp);
  }
  cout << "Head of the list: " << dll.begin() << endl;
  cout << "Size of the list: " << dll.listSize() << endl;
  cout << "Inserting a 44 " << endl; dll.insert(5,44);
  cout << "Elements of the list:";
  for (int i = 0; i < dll.listSize(); i++) {
    cout << " " << dll.get(i);
  }
  cout << endl << "Deleting the 44 and adding to the end of the list" << endl;
  dll.deleteElement(5); dll.insert(11115,44);
  cout << "Elements of the list:";
  for (int i = 0; i < dll.listSize(); i++) {
    cout << " " << dll.get(i);
  }
  cout << endl;
  doublyLinkedList<int> dll2;
  dll2.push(2); dll2.deleteElement(0);
  dll2.push(4); dll2.push(3); dll2.deleteElement(0);
  cout << "Elements of the list:";
  for (int i = 0; i < dll2.listSize(); i++) {
    cout << " " << dll2.get(i);
  }
  cout << endl;
}
