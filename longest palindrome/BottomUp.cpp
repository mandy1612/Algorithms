#include<iostream> 
#include<string> 
#include<algorithm>
using namespace std;

int longest_palindrome_substring(string str){ 
	int n = str.size(); 
	int i, j, cl; 
	int L[n][n]; 
	for (i = 0; i < n; i++) 
		L[i][i] = 1; 
	for (cl=2; cl<=n; cl++){ 
		for (i=0; i<n-cl+1; i++){ 
			j = i+cl-1; 
			if (str[i] == str[j] && cl == 2) 
				L[i][j] = 2; 
			else if (str[i] == str[j]) 
				L[i][j] = L[i+1][j-1] + 2; 
			else
				L[i][j] = max(L[i][j-1], L[i+1][j]); 
		} 
	} 
	return L[0][n-1]; 
} 

int main(){ 
	string seq;
	cin >> seq;
	cout << "The lnegth of the longest palindrome is " << longest_palindrome_substring(seq);  
	return 0; 
} 
