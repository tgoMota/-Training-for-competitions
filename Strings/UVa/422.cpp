#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;
vector<pair<int,int>> ans;

vector<int> LPS(string pat){
    const int N = pat.size();
    vector<int> lps(N+1); 
    lps[0] = -1;
    int i = 0, j = -1;
    while(i<N){
        while(j>=0 && pat[i] != pat[j]) j = lps[j];
        i++, j++;
        lps[i] = j;
    }
    return lps;
}


void kmp(string& data, string& pat, const int row, int lane){
    vector<int> lps = LPS(pat);
    const int N = data.size();
    const int M = pat.size();
    int i = 0, j = 0;
    while(i < N){
        while(j>=0 && data[i] != pat[j]) j = lps[j];
        i++, j++;
        if(j == M){
            if(lane == 0){ //row
                ans.push_back({row, i-N+3});
                ans.push_back({row, i});
            }else if(lane == 1){ //col
                ans.push_back({i-N+3, row+1});
                ans.push_back({i, row+1});
            }else if(lane == 2){
                ans.push_back({row+2, i-N+3});
                ans.push_back({row+i, i});
            }else if(lane == 3){
                ans.push_back({i-N+3, row+2});
                ans.push_back({i, row+i});
            }
            j = lps[j];
        }
    }
}

string takeTraceString(int row, int col){
    string traceString = "";
    
    for(int i = row, j = col; i < n && j < n ; ++i, j++){
        traceString+=v[i][j];
    }
    //printf("em %d,%d , trace = %s\n", row, col, traceString.c_str());
    return traceString;
}

string takeSecondTraceString(int row, int col){
    string traceString = "";
    
    for(int i = row, j = col; i >= 0 && j >= 0 ; --i, j--){
        traceString+=v[i][j];
    }
    //printf("em %d,%d , trace = %s\n", row, col, traceString.c_str());
    return traceString;
}

void backTrace(string& query){
    //rows
    string traceString;
    for(int row = 0; row < n ; ++row){
        traceString = takeTraceString(row, 0);
        kmp(traceString, query, row, 2); ////
        reverse(traceString.begin(), traceString.end());
        kmp(traceString, query, row, 2);
    }

    for(int col = 1; col < n ; ++col){
        traceString = takeTraceString(col, 0);
        kmp(traceString, query, col, 3);
        reverse(traceString.begin(), traceString.end());
        kmp(traceString, query, col, 3);
    }
}

void backSecondTrace(string& query){
    string traceString;
    for(int row = 1; row < n ; ++row){
        traceString = takeSecondTraceString(row, n-1);
        kmp(traceString, query, row, 2); ////
        reverse(traceString.begin(), traceString.end());
        kmp(traceString, query, row, 2);
    }

    for(int col = n-1; col >= 0 ; --col){
        traceString = takeSecondTraceString(0, n-1);
        kmp(traceString, query, col, 3);
        reverse(traceString.begin(), traceString.end());
        kmp(traceString, query, col, 3);
    }
}

void backRow(string& query, int index){
    if(index == n) return;
    kmp(v[index], query, index+1, 0);
    backRow(query, index+1);
}

string takeColString(const int col){
    string s = "";
    for(int i = 0; i < n ; ++i) s+=v[i][col];
    return s;
}

void backCol(string& query, int index){
    if(index == n) return;
    string colString = takeColString(index);
    kmp(colString, query, index, 1);
    backCol(query, index+1);
}

void back(string query){
    backRow(query, 0);
    backCol(query, 0);
    backTrace(query);
}

int main(){
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n ; ++i) cin >> v[i];

    string query;
    while(cin >> query && query != "0"){
        ans.clear();
        back(query);
        int index = ans.size();
        for(auto x : ans) {
            printf("%d,%d",x.first, x.second);
            if(index) printf(" ");
            index--;
        }
        if(ans.size() == 0) printf("Not found");
        printf("\n");
    }
    return 0;
}