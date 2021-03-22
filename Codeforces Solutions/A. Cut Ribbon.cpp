//https://codeforces.com/problemset/problem/189/A
//A. Cut Ribbon
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f


int main(){
    vector<int> v;
    sort(v.begin(), v.end(), [&](int a, int b){
        if(a%2 == 0 && b%2 == 0){
            return a < b;
        }else if(a%2 == 0) return true;
        else if(b%2 == 0) return true;
        
        return a < b;
    });
    
}
