//https://www.hackerrank.com/challenges/queries-with-fixed-length/problem
//Queries with Fixed Length
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef pair<int,int> ii;
//CHECK THE CONSTRAINTS, PLEASE
struct maxqueue{
  deque<ii> q;
  int cnt_added, cnt_removed;
  maxqueue(){
    cnt_added = cnt_removed = 0;
  }
  void push(int x){
    while(!q.empty() && q.back().first < x) q.pop_back();
    q.push_back({x,cnt_added});
    cnt_added++;
  }

  void pop(){
    if(!q.empty() && q.front().second == cnt_removed) q.pop_front();
    cnt_removed++;
  }

  int maxx(){
    return q.front().first;
  }
};
vector<string> split_string(string);

// Complete the solve function below.
vector<int> solve(vector<int> v, vector<int> queries) {
    const int n = (int)v.size();
    vector<int> ans;
    for(int x : queries){
      maxqueue q;
      for(int i = 0; i < min(x,n) ; ++i) q.push(v[i]);
      int best = oo;
      for(int i = x; i < n ; ++i){
        best = min(best,q.maxx());
        q.pop();
        q.push(v[i]);
      }
      best = min(best, q.maxx());
      ans.push_back(best);
    }
    return ans;
}
