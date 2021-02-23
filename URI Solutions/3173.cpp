//https://www.urionlinejudge.com.br/judge/pt/problems/view/3173
//URI 3173 - Estrela de Natal
#include <bits/stdc++.h>
using namespace std;
 
int ma[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},
                 {0,31,29,31,30,31,30,31,31,30,31,30,31}};
double toJup = 11.9, toSat = 29.6;
bool isLeap(int year){
  if(year%4==0 && (year%100!=0 || year%400==0)) return true;
  return false;
}

void jup(int year, int month, int day, int n){
  int nextYear = year + toJup*n + 1;
  int totalDays = toJup*366*0.25*n + toJup*365*0.75*n;
  int ansDays = totalDays;
  day = 1;
  totalDays -= 11; //dezember to jan
  month = 1;
  year++;
  while(totalDays>0){
    bool leap = isLeap(year);
    int rest = ma[leap][month] - day+1;
    if(totalDays >= rest){
      totalDays -=rest;
      day = 1;
      month++;
      if(month > 12){
        month = 1;
        year++;
      }
    }else{
      day += totalDays;
      totalDays = 0;
    }
  }

  string strDay = "", strMonth = "";
  if(day < 10) strDay += "0";
  strDay += to_string(day);
  if(month < 10) strMonth += "0";
  strMonth += to_string(month);
  printf("Dias terrestres para Jupiter = %d\n", ansDays);
  printf("Data terrestre para Jupiter: %d-%s-%s\n", year, strMonth.c_str(), strDay.c_str());
}

void sat(int year, int month, int day, int n){
  int nextYear = year + toSat*n + 1;
  int totalDays = toSat*366*0.25*n + toSat*365*0.75*n;
  int ansDays = totalDays;
  day = 1;
  totalDays -= 11; //dezember to jan
  month = 1;
  year++;
  while(totalDays>0){
    bool leap = isLeap(year);
    int rest = ma[leap][month] - day+1;
    if(totalDays >= rest){
      totalDays -=rest;
      day = 1;
      month++;
      if(month > 12){
        month = 1;
        year++;
      }
    }else{
      day += totalDays;
      totalDays = 0;
    }
  }

  string strDay = "", strMonth = "";
  if(day < 10) strDay += "0";
  strDay += to_string(day);
  if(month < 10) strMonth += "0";
  strMonth += to_string(month);
  printf("Dias terrestres para Saturno = %d\n", ansDays);
  printf("Data terrestre para Saturno: %d-%s-%s\n", year, strMonth.c_str(), strDay.c_str());
}

int main(){
    int n;
    scanf("%d", &n);
    int year = 2020, month = 12, day = 21;
    jup(year, month, day, n);
    sat(year, month, day, n);
    return 0;
}