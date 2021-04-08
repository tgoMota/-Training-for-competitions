#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main(){
    string line;
    int t = 0;
    while(cin >> line){
      if(t++) cout << '\n';
      vector<int> freq(256, 0);
      for(char c : line) freq[c]++;
      vector<ii> v;
      for(int i = 0; i < 256 ; ++i){
        if(freq[i]) v.push_back({freq[i], i});
      }
      sort(v.begin(),v.end(), [&](ii&a, ii& b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
      });
      for(int i = 0; i < (int)v.size() ; ++i){
        cout << v[i].second << " " << v[i].first << '\n';
      }
    }
    return 0;
}

