//https://www.urionlinejudge.com.br/judge/pt/problems/view/1562
//URI 1562 - Escolhendo as Duplas
#include <bits/stdc++.h>
using namespace std;
vector<int> in_degree, match, wish;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
      in_degree.assign(n+1, 0);
      match.assign(n+1, -1);
      wish.resize(n+1);
      for(int i = 1; i <= n ; ++i){
        scanf("%d", &wish[i]);
        in_degree[wish[i]]++;
      }
      if(n&1){
        printf("IMPOSSIBLE\n");
        continue;
      }
      queue<int> q;
      bool ok = true;
      for(int i = 1; i <= n ; ++i) {
        if(in_degree[i] == 0) q.push(i);
      }
	    vector<bool> cycle(n+1, true);
      while(!q.empty()){
        int v = q.front();
        q.pop();
		    cycle[v] = false;
        int u = wish[v];
        if(--in_degree[u] == 0) q.push(u);
        if(match[v] == -1 && match[u] == -1){
          match[u] = v;
          match[v] = u;
        }
      }

      for(int i = 1; i <= n ; ++i){
        int cnt =0;
        if(cycle[i]){
          for(int v = i; ; v = wish[v]){
            if(match[v] != -1) cnt++;
            if(wish[v] == i) break;
          }
          if(cnt == 0 || match[i] != -1){
            for(int v = i; ; v = wish[v]){
              cycle[v] = false;
              if(match[v] == -1 && match[wish[v]] == -1){
                match[v] = wish[v];
                match[wish[v]] = v;
              }
              if(wish[v] == i) break;
            }
          }
        }
      }

      for(int i = 1; i <= n && ok ; ++i){
        if(match[i] == -1) ok = false;
      }
	
      if(!ok){
        printf("IMPOSSIBLE\n");
        continue;
      }

      for(int i = 1;  i <= n ; ++i){
        printf("%d", match[i]);
        if(i!=n) printf(" ");
      }
      printf("\n");
    }
    return 0;
}