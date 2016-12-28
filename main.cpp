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
void Player_vs_Computer();
bool Can_continue(char name[41]);
int restore_value();
int Score(int Cards[] , int number);
int Points( int card );


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
                Player_vs_Computer();
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
void Player_vs_Computer()
{
    system("cls");
    cout<<"Enter your name :\n";
    cin.get();
    char name[41];
    int Value = 20;
    cin>>name;
    bool decision_continue = false;
    if(Can_continue(name) == true)
    {
        cout<<"\n\t Do you want to continue ?\n";
        char decision;
        cin>>decision;
        if(decision == 'y' || decision == 'Y')
        {
            Value = restore_value();
            if(Value == 0)
                Value = 20;
            decision_continue = true;
        }
    }
    cout<<"\n\t Your sum is : "<<Value<<endl;
    int bet;
    cout<<"\n\t How much do you want to bet ?\n";
    cin>>bet;
    while(bet<1 || bet > Value)
    {
        cout<<"Enter a bet between 1 and "<<Value<<endl;
        cin>>bet;
    }

    int PlayerCards[20] , HousCards[20] , NumbercardsP , NumbercardsH , ScoreP ,ScoreH ;

    PlayerCards[0] = NewCard();
    PlayerCards[1] = NewCard();
    NumbercardsP = 2;
    HousCards[0] = NewCard();
    HousCards[1] = NewCard();
    NumbercardsH = 2;
    ScoreP = Score(PlayerCards , NumbercardsP);
    ScoreH = Score(HousCards , NumbercardsH);


    //if(decision_continue == false)    la final adaug in fisier sau modific existentul


}
bool Can_continue(char name[41])
{

    return false;
}
int restore_value()
{
    return 0;
}
int Score(int Cards[] , int number)
{
    int sum = 0 , valcurent, aces = 0;
    for(int i=0;i<number;i++)
    {
        valcurent = Points(Cards[i]);
        sum += valcurent;
        if(Cards[i] % 13 == 0)
            aces ++;
    }
    if (sum < 12 && aces != 0 )
        sum += 10;
    return sum;
}
int Points( int card )
{
    int remnat = card %13 ;
    if(remnat == 0)
        return 1;
    if(remnat < 10)
        return remnat + 1 ;
    return 10;
}





