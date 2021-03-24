#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//CHECK THE CONSTRAINTS, PLEASE

struct cmp{
  bool operator() (pair<int,int> const &a, pair<int,int> const &b) { 
      if(a.first == b.first) return a.second > b.second;
      return a.first < b.first; 
    }
};

int main(){
    fastio();
    int t;
    cin >> t;
    cin.ignore();
    for(int ti = 1; ti <= t ; ++ti){
      vector<string> v;
      priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;
      string line;
      getline(cin, line);
      istringstream ss(line);
      string token;
      int idx = 0;
      while(getline(ss, token, ' ')){
        v.push_back(token);
        pq.push({(int)token.size(),idx++});
      }

      while(!pq.empty()){
        cout << v[pq.top().second];
        pq.pop();
        if(!pq.empty()) cout << " ";
      }
      cout << '\n';
    }
    return 0;
}

