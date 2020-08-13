#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int calculateEditDistance(string str1, string str2, int i, int j, int** memo) {

    if (memo[i][j] > -1) 
        return memo[i][j];
    if (i == 0) {
        memo[i][j] = j;
        return j;
    }
    if (j == 0) {
        memo[i][j] = i;
        return i;
    }
    if (str1[i - 1] == str2[j - 1]) {
        memo[i][j] = calculateEditDistance(str1, str2, i - 1, j - 1, memo);
        return memo[i][j];
    }
    memo[i][j] = min(1 + calculateEditDistance(str1, str2, i, j - 1, memo), 
                     min(1 + calculateEditDistance(str1, str2, i - 1, j, memo),
                     2 + calculateEditDistance(str1, str2, i - 1, j - 1, memo)));
    return memo[i][j];

}

int main() {
    string str1,str2;
    cin >> str1 >> str2;
    const int m = str1.size(),n = str2.size();
    int **memo = new int[m + 1][n + 1];
    for (int i=0;i<m+1;i++)
        for(int j=0;j<n;j++)
            memo[i][j] = -1;
    
    int minDistance = calculateEditDistance(str1, str2, m, n, memo);
    cout << minDistance;
    return 0;
}