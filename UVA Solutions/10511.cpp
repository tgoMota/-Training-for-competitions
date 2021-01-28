//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1452
//UVA 10511 - Councilling
#include <bits/stdc++.h>
using namespace std;
//CHECK THE LIMITS, PLEASE
map<pair<int,string>, int> idString;
map<int,string> takeById;
vector<unordered_map<int,int>> adj;
vector<string> allparty;
int sink, destiny, n;
const int NAX = 5000;

vector<int> parent;
void aug(int v){
  if(parent[v] == -1) return;
  adj[parent[v]][v]--;
  adj[v][parent[v]]++;
  aug(parent[v]);
}

bool bfs(){
  parent.assign(NAX, -1);
  vector<bool> vst(NAX,false);
  queue<int> q;
  q.push(sink);
  vst[sink] = true;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    if(v == destiny) break;
    for(auto x : adj[v]){
      if(!vst[x.first] && x.second > 0){
        vst[x.first] = true;
        parent[x.first] = v;
        q.push(x.first);
      }
    }
  }
  return vst[destiny];
}

int maxflow(){
  int mxflow = 0;
  while(bfs()){
    mxflow++;
    aug(destiny);
  }
  return mxflow;
}

int main(){
    int t;
    scanf("%d\n", &t);
    string tt;
    for(int ti = 1; ti <= t ; ++ti){
        sink = 0, destiny = 4000;
        idString.clear();
        takeById.clear();
        adj.assign(NAX, unordered_map<int,int>());
        allparty.clear();
        int nameidx = 1, partyidx = 1001, clubidx = 2001;
        string line;
        while(getline(cin, line) && !line.empty()){
          stringstream ss(line);
          string token;
          int idx = 0;
          while(getline(ss, token, ' ')){
            string name = "", party = "";
            int id_name, id_party, id_club;
            if(idx == 0){
              id_name = nameidx;
              name = token;
              idString[{0,name}] = nameidx;
              takeById[nameidx++] = name;
            }else if(idx == 1){
              party = token;
              if(idString.find({1,party}) == idString.end()){
                id_party = partyidx;
                idString[{1,party}] = partyidx;
                takeById[partyidx++] = party;
                allparty.push_back(party);
              }else{
                id_party = idString[{1,party}];
              }
            }else{
              string club = token;
              if(idString.find({2,club}) == idString.end()){
                id_club = clubidx;
                idString[{2,club}] = clubidx;
                takeById[clubidx++] =  club;
              }else{
                id_club = idString[{2,club}];
              }

              adj[id_party][id_name] = 1;
              adj[id_name][id_club] = 1;
              adj[id_club][destiny] = 1;
            }
            idx++;
          }
        }
        int npersons = nameidx-1, npartys = partyidx-1001, nclubs = clubidx-2001;
        int can = (nclubs-1)/2;
        for(string s : allparty){
          int id_party = idString[{1,s}];
          adj[sink][id_party] = can;
        }

        int mxflow = maxflow();
        if(mxflow != nclubs){
          printf("Impossible.\n");
        }
        else{
          for(int i = 1001; i < partyidx ; ++i){
            for(auto x : adj[i]){
              if(x.second == 0){
                int j = x.first;
                for(auto y : adj[j]){
                  if(y.second == 0){
                    printf("%s %s\n", takeById[x.first].c_str(), takeById[y.first].c_str());
                  }
                }
              }
            }
          }
        }
        if(ti < t) printf("\n");
    }
    return 0;
}
