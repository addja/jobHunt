#include<list>
#include<string>
#include<iostream>

using namespace std;

// hash table with chaining as collision protocol
class hashTable {
  private:
    const static int size = 50;
    list<pair<int,string> > table [size];

    int hash(int key) {
      return (key*42) % size;
    }
  public:
    void insert(int key, string value) {
      table[hash(key)].push_front(make_pair(key,value));
    }

    string* get(int key) {
      int k = hash(key);
      auto it = table[k].begin();
      while (it != table[k].end()) {
        if ((*it).first == key) return &(*it).second;
        it++;
      }
      return NULL;
    }

    void deleteKey(int key) {
      int k = hash(key);
      auto it = table[k].begin();
      while (it != table[k].end()) {
        if ((*it).first == key) {
          table[k].erase(it); return;
        }
        it++;
      }
      return;
    }

};

void printEntry(hashTable * ht, int key) {
  string* s = (*ht).get(key);
  if (s) {
    cout << *s << endl;
  }
  else {
    cout << "Key not in the hash table" << endl;
  }
}

int main() {
  hashTable *ht = new hashTable;
  (*ht).insert(7,"Hello world");
  (*ht).insert(777,"Hello hell");
  printEntry(ht,7);
  printEntry(ht,777);
  printEntry(ht,1);
  (*ht).deleteKey(7);
  printEntry(ht,7);
  printEntry(ht,777);
}
