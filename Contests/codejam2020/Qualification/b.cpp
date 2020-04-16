#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

typedef long long ll;
int main(){
    int t, n;
    cin >> t;
    string data;
    for(int ti = 1; ti <= t ; ++ti){
        cin >> data;
        stack<char> st; 
        for(int i = 0; i < data.length() ;i++){ 
            if(data[i] == '(' || data[i] == ')') continue;
            int num = data[i] - '0';
            while(st.size() > num){
                data.insert(data.begin()+i, ')');
                st.pop();
                i++;
            }
            while(st.size() < num){
                data.insert(data.begin()+i, '(');
                st.push('(');
                i++;
            }
        }

        while(!st.empty()){
            data+=')';
            st.pop();
        }

        printf("Case #%d: %s\n", ti, data.c_str());
    }

    return 0;
}