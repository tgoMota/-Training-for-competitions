#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

string minWindow(string s, string t) {
        
        unordered_map<char,int>m;
        unordered_map<char,int>m1;
        
        for(int i=0;i<t.size();i++){
                m[t[i]]++;
        }
        
        int count=0;
        int start=0,window=INT_MAX,start_index=-1;
        for(int i=0;i<s.size();i++){
            
            m1[s[i]]++;
            
            if(m1[s[i]]<=m[s[i]]&&m[s[i]]!=0)count++;
            
            if(count==t.size()){
                
                
                while(m1[s[start]]>m[s[start]]||m[s[start]]==0){
                    if(m1[s[start]]>m[s[start]])
                        m1[s[start]]--;
                        start++;
                    
                }
                
                int win=i-start+1;
                if(win<window){
                    window=win;
                    start_index=start;
                }
                
            }
            
        }
        
        if(start_index==-1)return "";
        
        return s.substr(start_index,window);
        
    }

int main(){
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        string s;
        cin >> s;
        printf("%d\n", (int)minWindow(s, "123").size());
    }
    return 0;
}