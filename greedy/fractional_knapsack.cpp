#include<iostream>
#include<algorithm>
using namespace std;

struct Object{
    int value,weight;
};

double computeMaxValue(int maxWeight,Object a[],int size);
bool comparator(Object a, Object b);

int main(){
    Object *a = new Object[3];
    int w;
    cin >> w;
    for(int i=0;i<3;i++)
        cin >> a[i].value >> a[i].weight;
    cout << computeMaxValue(w,a,3);
}

bool comparator(Object a, Object b){
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double computeMaxValue(int maxWeight,Object a[],int size){
    int currWeight = 0;
    double finalValue = 0.0;
    sort(a,a+size,comparator);
    for(int i=0;i<size;i++){
        if(currWeight + a[i].weight <= maxWeight){
            currWeight += a[i].weight;
            finalValue += (double)a[i].value;
        }
        else{
            int residue = maxWeight - currWeight;
            finalValue += ((double)a[i].value/a[i].weight) * (double)residue;
            break;
        }
    }
    return finalValue;
}