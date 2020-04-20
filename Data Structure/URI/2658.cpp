#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef pair<int,int> pii;

const int M = 100005;
int t[4*M][9];
int lz[4*M];

vector<int> noteFreq;
vector<int> updateAux;
int N, Q;

void build(int i, int l, int r){
    if(l == r){
        t[i][1] = 1;
    }else{
        int m = l + (r - l)/2;
        build(2*i, l, m);
        build(2*i+1, m+1, r);
        t[i][1] = t[2*i][1] + t[2*i+1][1];
    }
}

void push(int i, int l, int r){
    if(!lz[i]) return;
    for(int note = 0; note < 9 ; ++note) updateAux[(note+lz[i])%9] = t[i][note];
    for(int note = 0; note < 9 ; ++note) t[i][note] = updateAux[note];
    if(l != r){
        lz[2*i] += lz[i];
        lz[2*i+1] += lz[i];
    }
    lz[i] = 0;
}

void query(int i, int l, int r, int ql, int qr){
    push(i, l, r);
    if(ql > r || qr < l) return;
    if(ql <= l && qr >= r){
        for(int note = 0; note < 9 ; ++note) noteFreq[note] += t[i][note];
        return;
    }
    int m = l + (r-l)/2;
    query(2*i, l, m, ql, qr);
    query(2*i+1, m+1, r, ql, qr);
}

void update(int i, int l, int r, int ql, int qr, int x){
    push(i, l, r);
    if(ql > r || qr < l) return ;
    if(ql <= l && qr >= r){
        lz[i] += x;
        push(i, l, r);
        return;
    }

    int m = l + (r-l)/2;
    update(2*i, l, m, ql, qr, x);
    update(2*i+1, m+1, r, ql, qr, x);
    for(int note = 0; note < 9 ; ++note) t[i][note] = t[2*i][note] + t[2*i+1][note];
}


int main(){
    scanf("%d%d", &N, &Q);
    build(1,0,N-1);
    updateAux.assign(9,0);

    for(int i = 0; i < Q ; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        noteFreq.assign(9,0);
        query(1, 0, N-1, a, b);
        int greaterNote = -1, greaterFreq = -1;
        for(int note = 0; note < noteFreq.size() ; ++note) {
            if(noteFreq[note] >= greaterFreq){
                greaterFreq = noteFreq[note];
                greaterNote = note;
            }
        }

        update(1, 0, N-1, a, b, greaterNote);
    }

    for(int i = 0; i < N ; ++i){
        noteFreq.assign(9,0);
        query(1,0,N-1, i,i);
        for(int note = 0; note < 9 ; ++note) {
            if(noteFreq[note]) {
                printf("%d\n", note);
                break;
            }
        }
    }

    return 0;
}