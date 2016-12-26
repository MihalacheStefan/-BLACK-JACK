#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
using namespace std;

const string Ranks[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
const string Colors[4] = {"hearts","diamonds","clubs","spades"};

bool CardsDealt[52];        // cartile tratate
void introduction();
void Menu();
int NewCard();

int main()
{
    srand(time(NULL));
    introduction();
    cout<< "                        Press ENTER to continue!"<<endl;
    cin.get();
    system("cls");

    Menu();
    cin.get();
    return 0;
}
int NewCard()
{
    int newc;
    int ok=0;
    newc = rand()% 52 ;
    if ( CardsDealt[newc] == false )
        {
           ok = 1;
           CardsDealt[newc] = true;
        }
    while(ok == 0)
    {
        newc = rand() % 52;
        if ( CardsDealt[newc] == false )
        {
            ok = 1;
           CardsDealt[newc] = true;
        }
    }
    return newc ;
}
void introduction()
{

cout<<"'|| '||'  '|'         '||                                          .           "<<endl;
cout<<" '|. '|.  .'    ....   ||    ....    ...   .. .. ..     ....     .||.    ...   "<<endl;
cout<<"  ||  ||  |   .|...||  ||  .|   '' .|  '|.  || || ||  .|...||     ||   .|  '|. "<<endl;
cout<<"   ||| |||    ||       ||  ||      ||   ||  || || ||  ||          ||   ||   || "<<endl;
cout<<"    |   |      '|...' .||.  '|...'  '|..|' .|| || ||.  '|...'     '|.'  '|..|' "<<endl;


cout<<"     '||      '||                  '||         ||                 '||       " <<endl;
cout<<"      || ...   ||   ....     ....   ||  ..    ...  ....     ....   ||  ..   " <<endl;
cout<<"      ||'  ||  ||  '' .||  .|   ''  || .'      || '' .||  .|   ''  || .'    " <<endl;
cout<<"      ||    |  ||  .|' ||  ||       ||'|.      || .|' ||  ||       ||'|.    " <<endl;
cout<<"      '|...'  .||. '|..'|'  '|...' .||. ||.    || '|..'|'  '|...' .||. ||.  " <<endl;
cout<<"                                            .. |'                           " <<endl;
cout<<"                                              ''                            " <<endl;
}
void Menu()
{
    cout <<"\n\n"<<"\t\t\t\t       Menu "<<"\n\n" ;
    cout <<"\t\t\t"<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout <<"\t\t\t"<<"1. Rules ------------------------|"<<endl;
    cout <<"\t\t\t"<<"2. Player vs. Computer ----------|"<<endl;
    cout <<"\t\t\t"<<"3. History ----------------------|"<<endl;
    cout <<"\t\t\t"<<"4. Exit--------------------------|"<<endl;
    cout <<"\t\t\t"<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout <<"\n\t\t"<<"Enter your option : ";
}





