#include<iostream> 
#include<vector>
using namespace std; 

class Graph { 
	int v , e;  
	int** adj; 
public: 
	Graph(int v, int e); 
	void insertEdge(int start, int e); 
	void bfs(int start); 
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

void Graph::bfs(int start) { 
	vector<bool> visited(v, false); 
	vector<int> q; 
	q.push_back(start); 
	visited[start] = true; 
	int vis; 
	while (!q.empty()) { 
		vis = q[0]; 
		cout << vis << " "; 
		q.erase(q.begin()); 
		for (int i = 0; i < v; i++) { 
			if (adj[vis][i] == 1 && (!visited[i])) { 
				q.push_back(i); 
				visited[i] = true; 
			} 
		} 
	} 
} 
 
int main() { 
	int v = 5, e = 4; 
	Graph G(v, e); 
	G.insertEdge(0, 1); G.insertEdge(0, 2); G.insertEdge(1, 3); G.insertEdge(3, 4);
	G.bfs(4); 
} 
