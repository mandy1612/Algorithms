#include<iostream>
#include<algorithm>
using namespace std;

void selectActivity(int s[],int f[],int size);

int main(){
    int start[5];
    int stop[5];
    for(int i=0;i<5;i++){
        cin >> start[i] >> stop[i];
    }
    sort(stop,stop+5);
    selectActivity(start,stop,5);
    return 0;
}

void selectActivity(int s[],int f[],int size){
    int itr1,itr2;
    itr1 = 0;
    cout << itr1 << " ";
    for(itr2=1;itr2<size;itr2++){
        if(s[itr2]>=f[itr1]){
            cout << itr2 << " ";
            itr1 = itr2;
        }
    }
}