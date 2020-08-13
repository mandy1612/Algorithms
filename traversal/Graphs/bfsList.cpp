#include<iostream> 
#include <list> 

using namespace std; 

class Graph { 
	int v;
	list<int> *adjList; 
public: 
	Graph(int v);
	void insertEdge(int v, int u);  
	void bfs(int s); 
};

Graph::Graph(int v) { 
	this->v = v; 
	adjList = new list<int>[v]; 
} 

void Graph::insertEdge(int v, int u) { 
	adjList[v].push_back(u);  
} 

void Graph::bfs(int s) { 
	
	bool *visited = new bool[v]; 
	for(int i = 1; i < v; i++) 
		visited[i] = false; 

	list<int> q; 

	visited[s] = true; 
	q.push_back(s); 

	list<int>::iterator i; 

	while(!q.empty()) { 
		s = q.front(); 
		cout << s << " "; 
		q.pop_front(); 

		for (i = adjList[s].begin(); i != adjList[s].end(); ++i) 
		{ 
			if (!visited[*i]) 
			{ 
				visited[*i] = true; 
				q.push_back(*i); 
			} 
		} 
	} 
} 

int main() {  
	Graph g(4); 
	g.insertEdge(1, 2); g.insertEdge(1, 3); g.insertEdge(1, 4); g.insertEdge(3, 2); g.insertEdge(2, 4); g.insertEdge(3, 4); 
	g.bfs(2); 
	return 0; 
}