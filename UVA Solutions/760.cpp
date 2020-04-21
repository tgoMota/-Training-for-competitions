#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define max3(a,b,c) max(a, max(b,c))

int maxSub(int i, int j, string& a, string& b){
    if(i == a.size() || j == b.size() || a[i] != b[j]) return 0;
    int& ans = memo[i][j];
    if(ans != -1) return ans;
    if(ans)
    else return ans = 1+maxSub(i+1, j+1, a, b);
}

int memo[306][305];
int solve(int i, int j, string& a, string& b){
    if(i == a.size() || j == b.size()) return -oo;
    int& ans = memo[i][j];
    if(ans != -1) return ans;
    return ans = max3(solve(i+1, j, a, b), solve(i, j+1, a, b), maxSub(i, j, a, b));
}

int main(){
    string a, b;
    int index = 0;
    while(cin >> a >> b){
        if(index) printf("\n");
        memset(memo, -1, sizeof(memo));
        printf("%d\n", solve(0, 0, a, b));
        index++;
    }
    return 0;
}