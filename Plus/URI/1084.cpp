//https://www.urionlinejudge.com.br/judge/en/problems/view/1084
//URI 1084 - Apagando e Ganhando
#include <bits/stdc++.h>
using namespace std;

int main(){

    string a, st;
    int n, d;

    while(cin >> n >> d && n+d){
        cin >> a;
        int ind = 0;
        st.clear();
        while(d > 0){
            if(st.empty()) st.push_back(a[ind++]);
            if(st.back() < a[ind]){
                st.pop_back(); 
                d--;
                continue;
            }
            st.push_back(a[ind++]);
            if(ind == n) while(d--) st.pop_back();
        }

        a.erase(a.begin(), a.begin()+ind);
        st+=a;
        cout << st << endl;
    }

    return 0;
}