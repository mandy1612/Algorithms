#include<iostream>
#include<queue>
#include<vector> 
using namespace std; 

struct Node { 
	char ch; 
	int freq; 
	Node *left, *right; 

	Node(char ch, unsigned freq){ 
        left = right = NULL; 
		this->ch = ch; 
		this->freq = freq; 
	} 
}; 

struct compare { 

	bool operator()(Node* l, Node* r){ 
		return (l->freq > r->freq); 
	} 
}; 

void printCodes(struct Node* root, string str){ 
	if (!root) 
		return; 

	if (root->ch != '@') 
		cout << root->ch << ": " << str << "\n"; 
	printCodes(root->left, str + "0"); 
	printCodes(root->right, str + "1"); 
} 

void buildHuffTree(char arr[], int freq[], int size){ 
	struct Node *left, *right, *top; 
	priority_queue<Node*, vector<Node*>, compare> huffTree; 
	
    for (int i = 0; i < size; ++i) 
		huffTree.push(new Node(arr[i], freq[i])); 
	while (huffTree.size() != 1){ 
		left = huffTree.top(); 
		huffTree.pop(); 
		right = huffTree.top(); 
		huffTree.pop(); 
		
        top = new Node('@', left->freq + right->freq); 
		top->left = left; 
		top->right = right; 
        huffTree.push(top); 
	} 
	printCodes(huffTree.top(), ""); 
} 

int main(){ 
    int n;
    cin >> n;
    char *a = new char[n];
    int *f = new int[n];
    for(int i=0;i<n;i++)
        cin >> a[i] >> f[i];
	
    buildHuffTree(a, f, n); 
	return 0; 
}