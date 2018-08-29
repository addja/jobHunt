#include<iostream>
#include<map>
#include<string>
#include<stack>

using namespace std;

class trie {
	private:
		struct Node {
			bool word;
			map<char,Node *> ch;
			Node() {
				word = false;
			}	
		};

		Node* root;

		int countWords(Node * node) {
			int count = node->word;
			for (auto it: node->ch) {
				count += countWords(it.second);
			} 
			return count;
		}	
		
  public:
		trie() {
			root = new Node();
		}

		void insert(string s) {
			Node * tmp = root;
			for (auto c: s) {
				if (tmp->ch[c] == NULL) {
					tmp->ch[c] = new Node();
				}
				tmp = tmp->ch[c];
			}
			tmp->word = true;
		}

	int nWords() {
		return countWords(root);
	}

	bool contains(string s) {
		Node * tmp = root;
		for (auto c: s) {
			if (tmp->ch[c] == NULL) return false;
			tmp = tmp->ch[c];
		}
		if (tmp->word) return true;
		return false;
	}

	void deleteWord(string s) {
		stack<pair<char,Node *> > trace;
		Node * tmp = root;
		for (auto c: s) {
			if (tmp->ch[c] == NULL) return;
			trace.push(make_pair(c,tmp));
			tmp = tmp->ch[c];
		}
		if (tmp->ch.size() > 0) {
			tmp->word = false;
		}
		else {
			pair<char,Node *> p;
			while (!trace.empty()) {
				p = trace.top();
				delete p.second->ch[p.first];
				p.second->ch.erase(p.first);
				trace.pop();
				if (p.second->ch.size() > 0) return;
			}
		}
	}

};

int main() {
	trie e;
	e.insert("emily");
	cout << e.contains("emily") << endl;
	e.insert("emu");
	cout << e.nWords() << endl;
	cout << e.contains("emi") << endl;
	e.insert("rail");
	cout << e.nWords() << endl;
	e.deleteWord("emily");
	e.deleteWord("emu");
	e.deleteWord("rail");
	cout << e.nWords() << endl;
	e.insert("emily");
	cout << e.contains("emily") << endl;
}

