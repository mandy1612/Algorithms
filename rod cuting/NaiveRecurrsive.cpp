#include<iostream>
#include<algorithm>

using namespace std;

int cutRod(int P[], int n);
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

int cutRod(int P[], int n){
    if(n == 0)
        return P[n];
    
    int q = INT8_MIN;
    for(int i=1;i<=n;i++){
        q = max(q,P[i]+cutRod(P,n-i));
    }
    return q;
}