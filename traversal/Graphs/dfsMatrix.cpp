#include<vector>
#include<iostream>
using namespace std; 

class Graph { 
	int v , e; 
	int** adj; 
public: 
	Graph(int v, int e); 
	void insertEdge(int start, int e); 
	void dfs(int start, vector<bool>& visited); 
}; 

Graph::Graph(int v, int e) { 
	this->v = v; 
	this->e = e; 
	adj = new int*[v]; 
	for (int row = 0; row < v; row++) { 
		adj[row] = new int[v]; 
		for (int column = 0; column < v; column++) { 
			adj[row][column] = 0; 
		} 
	} 
} 

void Graph::insertEdge(int start, int e) { 
	adj[start][e] = 1; 
	adj[e][start] = 1; 
} 

void Graph::dfs(int start, vector<bool>& visited) { 
    cout << start << " "; 
	visited[start] = true; 
	for (int i = 0; i < v; i++) { 
		if (adj[start][i] == 1 && (!visited[i])) { 
			dfs(i, visited); 
		} 
	} 
} 

int main() { 
	int v = 5, e = 4; 
	Graph G(v, e); 
	G.insertEdge(0, 1); G.insertEdge(0, 2); G.insertEdge(0, 3); G.insertEdge(0, 4); 
	vector<bool> visited(v, false); 
	G.dfs(1, visited); 
	return 0;
}