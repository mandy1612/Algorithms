#include<iostream>
#include<string>
using namespace std;

string str;
int max_len;
int start_len;
int end_len;

bool isPal(int i, int j, int **table){
    if (table[i][j] != 0){
        cout << "Res found for i:" << i << " j: " << j;
        return (table[i][j] == 1);
    }
    if (i == j){
        table[i][j] = 1;
        return true;
    }
    if (i + 1 == j){
        if (str[i] == str[j]) {
            table[i][j] = 1;
            return true;
        }
        table[i][j] = -1;
        return false;
    }
    if (str[i] == str[j]){
        bool res = isPal(i + 1, j - 1,table);
        table[i][j] = (res) ? 1 : 0;
        return res;
    }
    table[i][j] = 0;
    return false;
}

void longest_pal_calc(int i, int j,int **table) {
    if (isPal(i, j,table)) {
        if (j - i + 1 > max_len){
            max_len = j - i + 1;
            start_len = i;
            end_len = j;
        }
    } 
    else{
        longest_pal_calc(i + 1, j,table);
        longest_pal_calc(i, j - 1,table);
    }
}

int main(){
    str = "abadbbda";
    const int n = str.size();
    int **table = new int[n][n];
    longest_pal_calc(0, n - 1,table);
    cout << "Longest: " << max_len;
    cout << str.substr(start_len, end_len - start_len + 1);
}