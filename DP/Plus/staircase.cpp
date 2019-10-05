#include <bits/stdc++.h>
using namespace std;

int memo[101], n;

int pd(int resta){
    if(resta <= 0) return resta == 0;
    int& ans = memo[resta];
    if(ans != -1) return ans;
    ans = 0;
    for(int i = 1 ; i <= 3 ; ++i)
        ans += pd(resta-i);
    return ans;
}

int main(){
    memset(memo, -1, sizeof(memo));
    cin >> n;
    cout << pd(n) << endl;
    return 0;
}
