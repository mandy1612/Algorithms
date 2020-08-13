#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int palindrome(string str){
    string rev = str;
    reverse(rev.begin(),rev.end());
    if(str == rev)
        return str.size();
    return 0;
}

int main(){
    string input;
    cin >> input;
    string substr,finalstr;
    int k,size,max = 0;
    for(int i=0;i<input.length();i++){
            for(k=i;k<input.length();k++){
                substr = input.substr(i, k-i+1);
                size = palindrome(substr);
                if(size == -1)
                    continue;
                else if(max < size){
                    max = size;
                    finalstr = substr;
                }
            }
    }
    cout << "Longest palidrome present: " << finalstr << "\tof length " << max;
}