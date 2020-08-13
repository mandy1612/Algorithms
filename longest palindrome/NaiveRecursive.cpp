#include<iostream>
#include<algorithm>
#include<string> 
using namespace std; 

int max (int x, int y) { return (x > y)? x : y; } 

int longest_palindrome_substring(string seq, int i, int j){ 
    if (i == j) 
	    return 1; 
    if (seq[i] == seq[j] && i + 1 == j) 
	    return 2; 

    if (seq[i] == seq[j]) 
	    return longest_palindrome_substring (seq, i+1, j-1) + 2; 

    return max( longest_palindrome_substring(seq, i, j-1), longest_palindrome_substring(seq, i+1, j) ); 
} 

int main(){ 
	string input;
    cin >> input;  
	cout << "The length of the longest_palindrome_substring is " << longest_palindrome_substring(input, 0, input.size() - 1); 
	return 0; 
}