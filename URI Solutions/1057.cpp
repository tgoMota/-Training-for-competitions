//https://www.urionlinejudge.com.br/judge/pt/problems/view/1057
//URI 1057 - Chegando Junto
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define LOCAL
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
//CHECK THE LIMITS, PLEASE
int N;
vector<string> grid;
vector<ii> robots, targets;
multiset<vector<ii>> vst;
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

bool allReached(vector<ii>& v){
  for(ii robot : v){
    bool found = false;
    for(ii target : targets){
      if(robot == target) found = true;
    }
    if(!found) return false;
  }
  return true;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        scanf("%d", &N);
        grid.resize(N);
        robots.clear();
        targets.clear();
        for(int i = 0; i < N ; ++i){
          cin >> grid[i];
          for(int j = 0; j < N ; ++j){
            if(grid[i][j] == 'X') targets.push_back({i,j});
            else if(isalpha(grid[i][j])) {
              robots.push_back({i,j});
            }
          }
        }

        queue<pair<int,vector<ii>>> q;
        q.push({0,robots});
        int ans = -1;
        vst.clear();
        while(!q.empty()){
          auto all = q.front();
          q.pop();
          vector<ii> v = all.second;

          if((int)vst.count(v)) continue;
          if(allReached(v)){
            ans = all.first;
            break;
          }
          vst.insert(v);
          for(int i = 0; i < 4 ; ++i){
            vector<ii> new_pos;
            set<ii> test;
            set<pair<int,ii>> mustStay;
            set<pair<int,ii>> cango;
            for(int robot = 0; robot < 3 ; ++robot){
                ii pos = v[robot];
                int new_x = dx[i] + pos.first;
                int new_y = dy[i] + pos.second;
                if(new_x < 0 || new_x >= N || new_y < 0 || new_y >= N || grid[new_x][new_y] == '#'){ //invalid position
                  //new_pos.push_back(pos); //continue on that old position;
                  mustStay.insert({robot,pos});
                }else{
                  cango.insert({robot, {new_x, new_y}});
                  //new_pos.push_back({new_x, new_y});
                }
            }

            for(auto x : cango){
              ii pos1 = x.second;
              bool toexit = false;
              for(auto y : mustStay){
                ii pos2 = y.second;
                if(pos1 == pos2){
                  ii new_pos1 = {pos1.first-dx[i], pos1.second-dy[i]};
                  mustStay.insert({x.first, new_pos1});
                  cango.erase(cango.find(x));
                  toexit = true;
                  break;
                }
              }
              if(toexit) break;
            }

            for(auto x : cango){
              ii pos1 = x.second;
              bool toexit = false;
              for(auto y : mustStay){
                ii pos2 = y.second;
                if(pos1 == pos2){
                  ii new_pos1 = {pos1.first-dx[i], pos1.second-dy[i]};
                  mustStay.insert({x.first, new_pos1});
                  toexit = true;
                  break;
                }
              }
              if(toexit) break;
              else mustStay.insert(x);
            }
            assert((int)mustStay.size() == 3);
            for(auto x : mustStay) new_pos.push_back(x.second);
            q.push({all.first+1,new_pos});
          }
        }
        printf("Case %d: ", ti);
        if(ans == -1) printf("trapped\n");
        else printf("%d\n", ans);
    }
    return 0;
}
