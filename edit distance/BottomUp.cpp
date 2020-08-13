#include<iostream>
#include<string>
#include<algorithm>
using namespace std; 

int editDisttable(string str1, string str2, int m, int n){ 
	int table[m+1][n+1]; 
	for (int i=0; i<=m; i++){ 
		for (int j=0; j<=n; j++){ 
			if (i==0) 
				table[i][j] = j;
			else if (j==0) 
				table[i][j] = i;

			else if (str1[i-1] == str2[j-1]) 
				table[i][j] = table[i-1][j-1]; 

			else
				table[i][j] = 1 + min(table[i][j-1], min(table[i-1][j], table[i-1][j-1])); 
		} 
	} 
	return table[m][n]; 
} 

int main(){ 
	string s1,s2;
    cin >> s1 >> s2; 
    cout << editDisttable(s1, s2, s1.length(), s2.length()); 
    return 0; 
} 
