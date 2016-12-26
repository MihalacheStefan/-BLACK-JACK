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
void Rules();
int NewCard();

int main()
{
    srand(time(NULL));
    introduction();
    cout<< "                        Press ENTER to continue!"<<endl;
    cin.get();
    system("cls");
    int optiune;
    do {

            Menu();
            cin>>optiune;
            if(optiune == 1)
                Rules();
            if(optiune == 2)
                ;
            if(optiune == 3)
                ;
            system("cls");
    }while(optiune != 4);

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
void Rules()
{
    system("cls");
    cout<<"\n\t\t"<<"*********************************************"<<endl;
    cout<<"\t\t"  <<"*                R_U_L_E_S                  *"<<'\n';
    cout<<"\t\t"  <<"*********************************************"<<"\n\n";
    cout<<"\t\t"<< "Blackjack is a popular American casino game,"<<'\n';
    cout<<"\t\t"<< "now found throughout the world. It is a banking "<<'\n';
    cout<<"\t\t"<< "game in which the aim of the player is to achieve "<<'\n';
    cout<<"\t\t"<< "a hand whose points total nearer to 21 than the "<<'\n';
    cout<<"\t\t"<< "banker's hand, but without exceeding 21."<<'\n';
    cout<<"\t\t"<< "Blackjack is played with an international "<<'\n';
    cout<<"\t\t"<< "52-card deck without jokers."<<'\n';
    cout<<"_______________________________________________________________________________"<<'\n';
    cout<<"Press ENTER to go back to Menu:";
    cin.get();
    cin.get();

}




