#include <bits/stdc++.h>
using namespace std;
int wierszgracza,kolumnagracza;
const int wiersze=10;
const int kolumny=10;
const int logicznamina=-1;
char planszagracza[wiersze][kolumny];
int planszalogiczna[wiersze][kolumny];
int ile_min=0;
int ukrytepola=0;
//warunek wytgranej-jezeli ukrytepola = liczbie min gracz wygrywa
bool warunekwygranej(char planszagracza[wiersze][kolumny], int ile_min){
    for(int w=0; w<=wiersze;w++){
        for(int k=0;k<=kolumny;k++){
            if(planszagracza[w][k]=='F' || planszagracza[w][k]=='.'){
                ukrytepola++;
                }
            }
        }
    if(ukrytepola==ile_min){
            return true;
    }

    return false;
}
//liczenie ile min jest dookola
    void obliczanieprzylegajacych(int planszalogiczna[wiersze][kolumny]){
        for(int r=0;r<wiersze;r++){
            for(int c=0;c<kolumny;c++)
        if(planszalogiczna[r][c]==logicznamina){
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nowyr=r+i;
                    int nowyc=c+j;
                    if(nowyr>=0 && nowyr<wiersze && nowyc>=0 && nowyc<kolumny){
                        if(planszalogiczna[nowyr][nowyc] != logicznamina){
                            planszalogiczna[nowyr][nowyc]++;
                        }
                    }
                }
            }
        }
           }
    }
    //rekurencja czyli rozlewanie i odkrywanie samego pola
    void odkrywaniePol(int r, int c,int planszalogiczna[wiersze][kolumny], char planszagracza[wiersze][kolumny]){

        //zabezpieczenie 1-pozaplanszowcy
        if(r < 0 || r>=wiersze || c<0 || c>=kolumny) return;
        //zabezpieczenie 2-juz odkryte pole
        if(planszagracza[r][c]!='.') return;
        //odkrywanie
        planszagracza[r][c] = planszalogiczna[r][c] + '0';
    if(planszalogiczna[r][c]==0){
        for(int i = -1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                odkrywaniePol(r+i,c + j,planszalogiczna,planszagracza);
            }
        }
    }
}
int main()
{
    //poczatek funkcji main, wprowadzenie losowania
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
//losowanie min
int ile_min=0;
while (ile_min<20){
    int w=rand() % 10;
    int k=rand() % 10;
    if(planszalogiczna[w][k]!=-1){
        planszalogiczna[w][k]=-1;
        //planszagracza[w][k]=='x';
        ile_min++;
    }

}
obliczanieprzylegajacych(planszalogiczna);
while(true){
//------------------ rys planszy
system("cls");
cout << "-----WITAJ W SAPERZE-----" << endl;
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
if(wierszgracza<0 || wierszgracza>=wiersze || kolumnagracza<0 || kolumnagracza>=kolumny){
    cout << "Zle wspolrzedne! Wpisz jeszcze raz." << endl;
    continue;
}
if(akcja=='f'){
    if(planszagracza[wierszgracza][kolumnagracza]=='.') planszagracza[wierszgracza][kolumnagracza]='F';
    else if(planszagracza[wierszgracza][kolumnagracza]=='F') planszagracza[wierszgracza][kolumnagracza]='.';
}
else if(akcja=='o'){
    if(planszagracza[wierszgracza][kolumnagracza]=='F') cout << "Na tym polu jest flaga! Najpierw ja zdejmij" << endl;
    else if(planszalogiczna[wierszgracza][kolumnagracza]==logicznamina){
    cout << "BUM! PRZEGRALES!" << endl;
    return(0);
    }
    else{
        odkrywaniePol(wierszgracza, kolumnagracza, planszalogiczna, planszagracza);
    }
}
//sprawdzanie wygranej+
if(warunekwygranej(planszagracza, ile_min)){
    system("cls");
    cout << endl << "BRAWOO! WYGRALES!!" << endl;
    return(0);
}
}
}
