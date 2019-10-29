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
                st.erase(st.end()-1, st.end()); //erasing the last element
                d--;
                continue;
            }
            st.push_back(a[ind++]);
            if(ind == n) while(d--) st.erase(st.end()-1, st.end());
        }

        a.erase(a.begin(), a.begin()+ind);
        st+=a;
        cout << st << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main(){

//     string a, ans;
//     stack<char> st;
//     int n, d;

//     while(cin >> n >> d && n+d){
//         cin >> a;
//         int ind = 0;
//         while(d > 0){
//             if(st.empty()) st.push(a[ind++]);
//             if(st.top() < a[ind]){
//                 st.pop();
//                 d--;
//                 continue;
//             }

//             st.push(a[ind++]);

//             if(ind == n){
//                 while(d--) st.pop();
//             }
//         }

//         for(int i = ind ; i < n ; ++i) st.push(a[i]);
//         ans = "";
//         while(!st.empty()) {
//             ans = st.top()+ans;
//             st.pop();
//         }
//         cout << ans << endl;
//     }

//     return 0;
// }