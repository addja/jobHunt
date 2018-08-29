#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

// directed graph represented with a matrix of adjacencies, spacial complexity of n^2
// alternative for sparce graphs: list of adjacencies, spacial complexity of n*m
class graph {
	private:
		int nvertices;
		vector<vector<bool> > adj;

		void topoRec(int i, vector<bool> & visited, stack<int> & s) {
			visited[i] = true;
			for (int j = 0; j < nvertices; j++) {
				if (!visited[j]) topoRec(j,visited,s);
			}
			s.push(i);
		}
	
	public:
		graph(int n) {
			nvertices = n;
			adj = vector<vector<bool> >(n, vector<bool>(n, false));
		}
		
		void addEdge(int n1, int n2) {
			adj[n1][n2] = true;
		}

		void BFS(int node) {
			cout << "Breadth first search starting at " << node << " :";
			vector<bool> visited(nvertices,false);
			queue<int> q;
			q.push(node);
			visited[node] = true;
			while (!q.empty()) {
				node = q.front();
				cout << " " << node;
				q.pop();
				for (int i = 0; i < nvertices; i++) {
					if (!visited[i] && adj[node][i]) {
						q.push(i);	
						visited[i] = true;
					}
				}
			}
			cout << endl;
		}

		void DFS(int node) {
			cout << "Depth first search starting at " << node << " :";
			vector<bool> visited(nvertices,false);
			stack<int> s;
			s.push(node);
			visited[node] = true;
			while (!s.empty()) {
				node = s.top();
				cout << " " << node;
				s.pop();
				for (int i = 0; i < nvertices; i++) {
					if (!visited[i] && adj[node][i]) {
						s.push(i);	
						visited[i] = true;
					}
				}
			}
			cout << endl;
		}

		void topologicalSort() {
			cout << "Topological sort of the graph:";
			vector<bool> visited(nvertices,false);
			stack<int> s;
			for (int i = 0; i < nvertices; i++) {
				if (!visited[i]) topoRec(i,visited,s);
			}
			while (!s.empty()) {
				cout << " " << s.top();
				s.pop();
			}
			cout << endl;
		}

};

int main() {
	int n, m, tmp1, tmp2;
	cin >> n >> m;
	graph * g = new graph(n);
	for (int i = 0; i < m; i++) {
		cin >> tmp1 >> tmp2;
		g->addEdge(tmp1,tmp2);
	}
	g->BFS(2);
	g->DFS(2);
	g->topologicalSort();
}
