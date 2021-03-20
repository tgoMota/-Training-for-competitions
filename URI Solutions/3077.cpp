//https://www.urionlinejudge.com.br/judge/pt/problems/view/3077
//URI 3077 - Distribuindo Pequis
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9+7;
//CHECK THE LIMITS, PLEASE
int main(){
    fastio();
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    int sum = 0;
    for(int i = 0; i < n ; ++i){
      int a;
      cin >> a;
      dq.push_back(a);
      sum += a;
    }
    vector<int> ans(n, 0);
    for(int i = 0; i < n ; ++i){
      ans[i] += sum * (k/n);
    }
    for(int i = 0; i < k%n ; ++i){
      int t = 0;
      for(int x : dq) ans[t++]+=x;
      int a = dq.back();
      dq.pop_back();
      dq.push_front(a);
    }
    for(int i = 0; i < n ; ++i){
      cout << ans[i];
      if(i != n-1) cout << " ";
    }
    cout << '\n';
    return 0;
}
