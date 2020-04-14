#include <bits/stdc++.h>
using namespace std;

// // int check(string& a, string& b, int posa, int posb){
// //     int enda = posa+b.size()-1, endb = b.size()-1;
// //     while(posa < a.size() && posb < b.size()){
// //         if(a[posa] != b[posb] || a[enda] != b[endb]) return 0;
// //         posa++, posb++, enda--, endb--;
// //     }
// //     return 1;
// // }

// // int ways(string& a, string& b){
// //     int ans = 0;
// //     for(int i = 0; i < a.size(); ++i){
// //         if(a[i] == b[0]) ans += check(a, b, i, 0);
// //         if((a.size() - i) < b.size()) return ans;
// //     }
// //     return ans;
// // }

// vector<vector<int>> tu;


// // int checkAll(string& a, string& b){
// //     int pi = b[0]-'a', ans = 0;
// //     for(int i = 0; i < tu[pi].size() ; ++i){
// //         int poscheck = tu[pi][i];
// //         ans += check(a,b,poscheck,0);
// //     }
// //     return ans;
// // }

    void computeLPSArray(string& pat, int M, vector<int>& lps) 
    { 
        // length of the previous longest prefix suffix 
        int len = 0; 
        int i = 1; 
        lps[0] = 0; // lps[0] is always 0 
  
        // the loop calculates lps[i] for i = 1 to M-1 
        while (i < M) 
        { 
            if (pat[i] == pat[len]) 
            { 
                len++; 
                lps[i] = len; 
                i++; 
            } 
            else // (pat[i] != pat[len]) 
            { 
                // This is tricky. Consider the example. 
                // AAACAAAA and i = 7. The idea is similar  
                // to search step. 
                if (len != 0) 
                { 
                    len = lps[len-1]; 
  
                    // Also, note that we do not increment 
                    // i here 
                } 
                else // if (len == 0) 
                { 
                    lps[i] = len; 
                    i++; 
                } 
            } 
        } 
    }

    int KMPSearch(string pat, string txt) 
    { 
        int M = pat.length(); 
        int N = txt.length(); 
  
        // create lps[] that will hold the longest 
        // prefix suffix values for pattern 
        vector<int> lps(M);
        int j = 0; // index for pat[] 
  
        // Preprocess the pattern (calculate lps[] 
        // array) 
        computeLPSArray(pat,M,lps); 
  
        int i = 0; // index for txt[] 
        int res = 0;  
        int next_i = 0;  
          
        while (i < N) 
        { 
            if (pat[j] == txt[i]) 
            { 
                j++; 
                i++; 
            } 
            if (j == M) 
            { 
                // When we find pattern first time, 
                // we iterate again to check if there  
                // exists more pattern 
                j = lps[j-1]; 
                res++; 
  
                // We start i to check for more than once 
                // appearance of pattern, we will reset i  
                // to previous start+1 
                if (lps[j]!=0) 
                    i = ++next_i; 
                j = 0; 
            } 
  
            // mismatch after j matches 
            else if (i < N && pat[j] != txt[i]) 
            { 
                // Do not match lps[0..lps[j-1]] characters, 
                // they will match anyway 
                if (j != 0) 
                    j = lps[j-1]; 
                else
                    i = i+1; 
            } 
        } 
        return res; 
    } 


int main(){
    string a, b;
    int t, p;
    char l;
    getline(cin, a);
    getline(cin, b);
    scanf("%d", &t);
    while(t--){
        cin.ignore();
        scanf(" %d %c", &p, &l);
        swap(a[p-1], l);
        // int cnt = KMPSearch(b, a);
        int cnt = 0;
        int nPos = a.find(b, 0); 
        while (nPos != string::npos)
        {
            cnt++;
            nPos = a.find(b, nPos+1);
        }
        printf("%d\n", cnt);
        swap(a[p-1], l);
    }

    return 0;
}