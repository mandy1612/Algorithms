#include<iostream> 
#include<list> 
using namespace std; 

class Graph { 
	int v;
	list<int> *adj; 
	void dfs(int v, bool visited[]); 
public: 
	Graph(int v);
	void insertEdge(int v, int w); 
	void traverse(int v); 
}; 

Graph::Graph(int v) { 
	this->v = v; 
	adj = new list<int>[v]; 
} 

void Graph::insertEdge(int v, int w) { 
	adj[v].push_back(w);
} 

void Graph::dfs(int v, bool visited[]) { 
	visited[v] = true; 
	cout << v << " "; 
	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		if (!visited[*i]) 
			dfs(*i, visited); 
} 

void Graph::traverse(int v) { 
	bool *visited = new bool[v]; 
	for (int i = 0; i < v; i++) 
		visited[i] = false; 
	dfs(v, visited); 
} 

int main() { 
	Graph g(4); 
	g.insertEdge(0, 1); g.insertEdge(0, 2); g.insertEdge(1, 2); g.insertEdge(2, 0); g.insertEdge(2, 3); g.insertEdge(3, 3); 
	g.traverse(2); 
	return 0; 
} 
