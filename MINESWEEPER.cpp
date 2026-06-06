#include <bits/stdc++.h>
using namespace std;
int wierszgracza,kolumnagracza;
const int wiersze=10;
const int kolumny=10;
const int logicznamina=-1;
char planszagracza[wiersze][kolumny];
int planszalogiczna[wiersze][kolumny];

    void obliczanieprzylegajacych(int planszalogiczna[wiersze][kolumny]){
        for(int r=0;r<wiersze;r++){
            for(int c=0;c<kolumny;c++)
        if(planszalogiczna[r][c]==logicznamina){
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nowyr=r+i;
                    int nowyc=c+j;

                }
            }
        }
           }
    }
    void odkrywaniePol(int wierszgracza, int kolumnagracza,int planszalogiczna[wiersze][kolumny], char planszagracza[wiersze][kolumny]){
        //zabezpieczenie 1-pozaplanszowcy
        if(wierszgracza < 0 || wierszgracza>=wiersze || kolumnagracza<0 || kolumnagracza>=kolumny) return;
        //zabezpieczenie 2-juz odkryte pole
        if(planszagracza[wierszgracza][kolumnagracza]!='-') return;
        //odkrywanie
        planszagracza[wierszgracza][kolumnagracza] = planszalogiczna[wierszgracza][kolumnagracza] + '0';
    if(planszalogiczna[wierszgracza][kolumnagracza]==0){
        for(int i = -1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                odkrywaniePol(wierszgracza+i,kolumnagracza + j,planszalogiczna,planszagracza);
            }
        }
    }
    }
int main()
{
srand(time(NULL));
const int wiersze=10;
const int kolumny=10;
int liczbamin=15;

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
    if(planszalogiczna[w][k]!=-1){
        planszalogiczna[w][k]=-1;
        planszagracza[w][k]='x';
        ile_min++;
    }

}
while(true){
//------------------ rys planszy
cout <<"   ";
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
cout <<"Podaj wiersz i kolumne:";
cin >> wierszgracza >> kolumnagracza;
wierszgracza--;
kolumnagracza--;
//if(planszalogiczna[wierszgracza][kolumnagracza]=-1){
   // planszagracza[wierszgracza][kolumnagracza]='#';
char akcja;
cout << "Co chcesz zrobic?'f' - flaguj, 'o' - odkryj: ";
cin >> akcja;
if(akcja=='f') planszagracza[wierszgracza][kolumnagracza]='F';
if(akcja=='f' && planszagracza[wierszgracza][kolumnagracza]=='F') planszagracza[wierszgracza][kolumnagracza]='.';
else if(akcja=='o'){
    if(planszalogiczna[wierszgracza][kolumnagracza]==-1){
        cout << "BUM PRZEGRALES!";
        return(0);
    }
    else{
        odkrywaniePol(wierszgracza, kolumnagracza, planszalogiczna, planszagracza);
    }
}



}
}
