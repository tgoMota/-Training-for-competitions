//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=98
//UVA 162 - Beggar My Neighbour
// WRONG   ......
#include <bits/stdc++.h>
using namespace std;
deque<string> player[2];
deque<string> heap;
const int R = 4, C = 13;

bool isFaced(string& card){
    return card[1] == 'J' || card[1] == 'Q' || card[1] == 'K' || card[1] == 'A';
}

int howMuch(string& card){
    if(card[1] == 'J') return 1;
    if(card[1] == 'Q') return 2;
    if(card[1] == 'K') return 3;
    if(card[1] == 'A') return 4;
    return 0;
}

void takeEntireHeap(int turn){
    while(!heap.empty()){
        player[turn].push_back(heap.back());
        heap.pop_back();
    }
}

int main(){
    string card;
    while(1){
        heap.clear();
        player[0].clear();
        player[1].clear();
        int turn  = 0;// 0 => non-dealer // 1=> dealter 
        for(int i = 0; i < R ; ++i){
            for(int j = 0; j < C ; ++j){
                cin >> card;
                if(card == "#") return 0;
                player[turn].push_front(card);
                turn = 1-turn;
            }
        }
        string card;
        bool faced = false;
        int whoFinish = -1;
        while(whoFinish == -1){
            if(faced){
               //  printf("%d jogou  %s faced\n", 1-turn, card.c_str());
                int limit = howMuch(card);
               // printf("%d jogou  %s\n", turn, card.c_str());
                while(limit-- && whoFinish == -1){
                    card = player[turn].front();
                    heap.push_front(card);
                    player[turn].pop_front();
                   // printf("%d jogou %s\n", turn, card.c_str());
                    if(player[turn].empty()) whoFinish = turn;
                    if(isFaced(card)) break;
                }

                if(whoFinish != -1) break;
                if(!isFaced(card)){
                  //  printf("%d pegou o monte\n", 1-turn);
                    takeEntireHeap(1-turn); //the last player who played one faced card take the Entire heap
                }
            }
            else{
                card = player[turn].front();
                heap.push_front(card);
                player[turn].pop_front();
               // printf("%d jogou  %s\n", turn, card.c_str());
                if(player[turn].empty()) whoFinish = turn;
            }
            faced = isFaced(card);
            turn = 1 - turn;
        }
        int whoWon = whoFinish == 0 ? 1 : 2;
        printf("%d%3d\n",whoWon, (int)player[1-whoFinish].size());
    }    
    return 0;
}