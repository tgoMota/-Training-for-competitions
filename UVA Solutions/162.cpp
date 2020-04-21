#include <bits/stdc++.h>
using namespace std;
const int ncards = 52;

typedef struct Player{
    int cards = 0;
    stack<string> hand;
} player;

void giveCard(player& p, string card){
    p.cards++;
    p.hand.push(card);
}

bool isFace(string& card){
    return card[1] == 'Q' || card[1] == 'A' || card[1] == 'K' || card[1] == 'J';
}

void takeEntireHeap(const int turn, vector<player>& p, stack<string>& heap){
    printf("Player %d pegou..%d cartas\n", turn, heap.size());
    int l1 = heap.size();
    int l2 = p[turn].hand.size();
    printf("-------------------------\n");
    stack<string> cpys;
    for(int i = 0; i < l2 ; ++i){
       // printf("colocando %s\n", heap.top().c_str());
        //p[turn].hand.push(heap.top());
        cpys.push(p[turn].hand.top());
        p[turn].hand.pop();
        //heap.pop();
    }

    for(int i = 0; i < l1 ; ++i){
        printf("colocando %s\n", heap.top().c_str());
        p[turn].hand.push(heap.top());
        //cpys.push(p[turn].hand.top());
        heap.pop();
    }

    for(int i = 0; i < l2 ; ++i){
        printf("colocando %s\n", cpys.top().c_str());
        p[turn].hand.push(cpys.top());
        cpys.pop();
    }
    printf("------------------------\n");
}

int main(){
    player p1, p2;
    stack<string> heap;
    string card, table = "";

    for(int i = 1; i <= ncards ; ++i){ // p1 -> turn 0 => dealer //p2 -> turn 1 => non-dealer
        cin >> card;
        giveCard(i % 2 == 0? p1 : p2, card);
    }
    cin >> card; //hash
    int remain = 1, lastFaceCard = -1;
    vector<player> players;
    players.push_back(p1);
    players.push_back(p2);

    printf("--\n");
    int turn = 1; //non-dealer
    int nturn = 0;
    bool inRow = false;
    bool end = false;
    int whoWon = -1;
    while(!players[0].hand.empty() && !players[1].hand.empty()){
        for(; remain >= 1 ; remain--){
            if(players[turn].hand.empty()){
                end = true;
                whoWon = 1 - turn;
                break;
            }
            card = players[turn].hand.top();
            heap.push(card);
            players[turn].hand.pop();
            printf("Player %d jogou %s\n", turn, card.c_str());
            if(isFace(card)) {
                inRow = true;
                lastFaceCard = turn;
                break;
            }
        }
        if(end) break;
        if(nturn && remain == 0 && !isFace(card) && inRow) {
            takeEntireHeap(lastFaceCard, players, heap);
            inRow = false;
        }
        remain = 1;
        table = card;
        if(isFace(table)){
            if(table[1] == 'Q'){
                remain++;
            }
            else if(table[1] == 'A'){
                remain += 3;
            }
            else if(table[1] == 'K'){
                remain += 2;
            }
        }

        turn = 1 - turn;
        nturn++;
        //if(nturn == 10) break;
    } 
    if(players[0].hand.empty()) whoWon = 1;
    else if(players[1].hand.empty()) whoWon = 0;
    printf("%d %d\n",whoWon+1,players[whoWon].hand.size());


    return 0; 
}