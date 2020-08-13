#include<iostream>
#include<algorithm>
using namespace std;

int cutRod(int P[],int n);
int main(){
    int n;
    cin >> n;
    int P[n+1];
    P[0] = 0;
    for(int i=1;i<n+1;i++)
        cin >> P[i];
    int rev = cutRod(P,n);
    cout << rev;
    return 0;
}

int cutRod(int P[],int n){
    int r[n+1];
    r[0] = 0;
    int q;
    for(int j=1;j<=n;j++){
        q = -1;
        for(int i=1;i<=j;i++)
            q = max(q,(P[i]+r[j-i]));
        r[j] = q;
    }
    return r[n];
}