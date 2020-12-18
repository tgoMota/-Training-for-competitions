//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3106
//UVA 11955 - Binomial Theorem
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll memo[55][55];

ll solve(int i, int j){
    if(j == 0 || i == j) return memo[i][j] = 1;
    ll& ans = memo[i][j];
    if(ans != -1) return ans;
    return ans = solve(i-1, j-1) + solve(i-1, j);
}

void apply(string& result, string a, string b){
    result += a+b;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        string eq;
        cin >> eq;
        vector<string> abk(3, ""); //a , b, k
        for(int i = 0, j = 0; i < (int)eq.size() ; ++i){
            if(eq[i] == '+' || eq[i] == '^'){
                j++;
            }else if(eq[i] == '(' || eq[i] == ')') continue;
            else {
                abk[j] += eq[i];
            }
        }
        int k = stol(abk[2]);
        memset(memo, -1, sizeof(memo));
        string result = "";

        printf("Case %d: ", ti);
        for(int i = k; i >= 0; i--){
            if(i != k) result+='+';
            ll coefficient= solve(k,i);
            if(coefficient> 1) apply(result, to_string(coefficient), "*");
            if(i == k) {
                result+=abk[0];
                if(i > 1) apply(result, "^", to_string(i));
            }
            else if(i){
                result += abk[0];
                if(i > 1) apply(result, "^", to_string(i));
                result+="*"+abk[1];
                if(k-i>1) apply(result, "^", to_string(k-i));
            }else {
                result+=abk[1];
                if(k > 1) apply(result, "^", to_string(k));
            }
        }
        printf("%s\n", result.c_str());
    }

    return 0;
}