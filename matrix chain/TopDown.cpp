#include<iostream>
#include<algorithm>
using namespace std;

int matrix_chain_order(int m[][], int p[], int i, int j){
    if(i == j)
        return 0;
    int q = INT32_MAX;
    for(int k=i;k<j;k++){
        if(m[i][k] <= -1 && m[k+1][j] <= -1){
            m[i][k] = matrix_chain_order(m,p,i,k);
            m[k+1][j] = matrix_chain_order(m,p,k+1,j);
        }
        if(q > (m[i][k] + m[k+1][j] + (p[i-1] * p[k] * p[j])))
            q = m[i][k] + m[k+1][j] + (p[i-1] * p[k] * p[j]);
    }
    m[i][j] = q;
    return q;
}

int main(){
    int n;
    cin >> n;
    int p[n];
    for(int i=0;i<n;i++)
        cin >> p[i];
    int m[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            m[i][j] = -1;

    cout << "qimum number of multiplcation is " << matrix_chain_order(m,p,1,n - 1);
}