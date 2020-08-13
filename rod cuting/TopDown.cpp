#include<iostream>
#include<algorithm>
using namespace std;

int cutRod(int P[], int r[], int n);
int main(){
    int n;
    cin >> n;
    int P[n+1];
    P[0] = 0;
    for(int i=1;i<n+1;i++)
        cin >> P[i];
    int r[n+1];
    for(int i=1;i<n+1;i++)
        r[i] = -1;
    
    int rev = cutRod(P,r,n);
    cout << rev;
    return 0;
}

int cutRod(int P[], int r[], int n){
    if(n == 0)
        return P[n];
    if(r[n] > -1)
        return r[n];
    
    int q = -1;
    for(int i=1;i<=n;i++){
        if(r[n-i] <= -1)
            r[n-i] = cutRod(P,r,n-i);
        q = max(q,P[i]+r[n-i]);
    }
    r[n] = q;
    return r[n];
}