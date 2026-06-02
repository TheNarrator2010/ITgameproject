#include <bits/stdc++.h>
using namespace std;
int main()
{
srand(time(NULL));
const int wiersze=10;
const int kolumny=10;
int liczbamin=15;
char planszagracza[wiersze][kolumny];
int planszalogiczna[wiersze][kolumny];

for(int w=0;w<wiersze;w++){
    for(int k=0;k<kolumny;k++){
        planszagracza[w][k]='.';
        planszalogiczna[w][k]=0;
    }
        }
int ile_min=0;
while (ile_min<15){
    int w=rand() % 10;
    int k=rand() % 10;
    if(planszalogiczna[w][k]!=1){
        planszalogiczna[w][k]=1;
        planszagracza[w][k]='x';
        ile_min++;
    }

}
int x,y;
while(true){
//------------------ rys planszy
cout <<"  ";
for(int k=0;k<kolumny;k++)
    cout << k+1<<" ";
cout <<endl;

for(int w=0;w<wiersze;w++){
     cout << w+1 << " ";
     if (w<9) cout << " ";
    for(int k=0;k<kolumny;k++){
        cout << planszagracza[w][k]<<" ";
    }
    cout << endl;
}
//---------------- koniec planszy
//gracz i jego dzialania
cout <<"Podaj wierz i kolumne:";
cin >> x >>y;
if(planszalogiczna[x][y]=1){
    planszagracza[x][y]='#';
    cout << "PRZEGRALES";
    return(0);

}

}
}
}
