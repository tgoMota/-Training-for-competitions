#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;

int main(){
    cin >> n;
    a.assign(n+1, 0);
    string b;
    cin >> b;
    for(int i = 1; i <= b.size() ; ++i) a[i] = (int)b[i-1]; 


    return 0;
}