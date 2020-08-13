#include<iostream> 
using namespace std; 

int matrix_chain_order(int p[], int i, int j){ 
	if(i == j) 
		return 0; 
	int k; 
	int q = INT32_MAX; 
    int temp; 
	for (k = i; k < j; k++){ 
		temp = matrix_chain_order(p, i, k) + matrix_chain_order(p, k + 1, j) + (p[i - 1] * p[k] * p[j]); 
		if (temp < q) 
			q = temp; 
	} 

	return q; 
} 
 
int main(){ 
	int n;
    int p[n];
    for(int i=0;i<n;i++)
        cin >> p[i]; 

	cout << "qimum number of multiplications is " << matrix_chain_order(p, 1, n - 1); 
}