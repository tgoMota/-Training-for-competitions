//URI Online Judge | 1259
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1259
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a;
    scanf("%d", &n);
    vector<int> odd, even;
    for(int i = 0; i < n ; ++i) {
        scanf("%d", &a);
        if(a % 2 == 0) even.push_back(a);
        else odd.push_back(a);
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end(), greater<int>());
    for(int x : even) printf("%d\n", x);
    for(int x : odd) printf("%d\n", x);


    return 0;
}