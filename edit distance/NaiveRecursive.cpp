#include<algorithm>
#include<iostream> 
using namespace std; 

int edit_dist(string str1 , string str2 , int m ,int n){ 
	if (m == 0) 
        return n; 

	if (n == 0) 
        return m; 

	if (str1[m-1] == str2[n-1]) 
		return edit_dist(str1, str2, m-1, n-1); 

	return 1 + min ( edit_dist(str1, str2, m, n-1), edit_dist(str1, str2, m-1, n), edit_dist(str1, str2, m-1, n-1)); 
} 

int main(){ 
	string str1,str2;
	cin >> str1 >>str2;
	cout << edit_dist( str1 , str2 , str1.length(), str2.length()); 
	return 0; 
}