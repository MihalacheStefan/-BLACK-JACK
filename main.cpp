#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
using namespace std;

const string Ranks[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
const string Colors[4] = {"hearts","diamonds","clubs","spades"};

bool CardsDealt[52];

void shuffle();
void introduction();
void Menu();
void Rules();
int NewCard();
void Player_vs_Computer();
bool Can_continue(char name[41]);
int restore_value();
int Score(int Cards[] , int number);
int Points( int card );
void Print_card(int number);
void Print_current_cards_and_score(int cards[] , int numbercards);
void Player_vs_Computer_Game(int & Value);
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

    Player_vs_Computer_Game(Value);

    while(Value != 0)
    {
        cout<<"\n\n Do you want to play again ?\n";
        cout<<"Yes (y) , No (n) \n\t";
        char play_again;
        cin>>play_again;
        if(play_again == 'y' || play_again == 'Y' )
           {
                shuffle();
                Player_vs_Computer_Game(Value);
           }
        else
            return ;
    }
    if(Value == 0)
    {
        cout<<"\n\n\n\t You lost all money ! \n\n Press ENTER to go back to Menu : ";
        cin.get();
        cin.get();
        return ;
    }


    //completez in fisier
    //if(decision_continue == false)    la final adaug in fisier sau modific existentul

}
void Player_vs_Computer_Game(int & Value)
{
    system("cls");
    cout<<"\n\t Your sum is : "<<Value<<endl;
    int bet;
    cout<<"\n\t How much do you want to bet ?\n\n\t";
    cin>>bet;
    while(bet<1 || bet > Value)
    {
        cout<<"Enter a bet between 1 and "<<Value<<endl;
        cin>>bet;
    }
    system("cls");
    int PlayerCards[20] , HousCards[20] , NumbercardsP , NumbercardsH , ScoreP ,ScoreH ;

    PlayerCards[0] = NewCard();
    PlayerCards[1] = NewCard();
    NumbercardsP = 2;
    HousCards[0] = NewCard();
    HousCards[1] = NewCard();
    NumbercardsH = 2;
    ScoreP = Score(PlayerCards , NumbercardsP);
    ScoreH = Score(HousCards , NumbercardsH);

    Print_current_cards_and_score(PlayerCards , NumbercardsP);

    cout<<"\n\n\n Dealer second card is : \n\n";
    Print_card(HousCards[1]);

    if(ScoreP == 21)
    {
        cout<<"\n\t\t BLACKJACK - 21 \n\n";
        cout<<"\t You win "<<bet<<" $ !\n\n";
        Value = Value + bet;
        cout<<"\n\n Your sum now is : "<<Value;
        return;
    }

    char wantcard ;
    cout<<"\n\n Do you want another card ? \n Yes (y) , No (n)\n\t";
    cin>>wantcard;
    while(wantcard == 'y' ||wantcard == 'Y' && ScoreP < 22)
    {
        cout<<"\n________________________________________________________________________________\n\n";
        PlayerCards[NumbercardsP++] = NewCard();

        Print_current_cards_and_score(PlayerCards , NumbercardsP);
        ScoreP = Score(PlayerCards , NumbercardsP);
        if(ScoreP < 22)
        {
            cout<<"\n\n Do you want another card ? \n Yes (y) , No (n)\n\t";
            cin>>wantcard;
            if(wantcard == 'n' ||wantcard == 'N')
                break;
        }
        else wantcard = 'n';
    }

    if(ScoreP > 21)
    {
        cout<<"\n\n\t\t You lost "<< bet <<'$';
        Value = Value - bet;
        cout<<"\n\n Your sum now is : "<<Value;
        return;
    }
    while(ScoreH < 17)
    {
        HousCards[NumbercardsH++] = NewCard();
        ScoreH = Score(HousCards , NumbercardsH);
    }
    cout<<"\n Dealer cards are :\n";
    for(int i=0;i<NumbercardsH;i++)
        Print_card(HousCards[i]);
    cout<<"\n Dealer's score is : " << ScoreH <<"\n\n";
    if(ScoreH > 21)
    {
        cout<<"\t You win "<<bet<<" $ !\n";
        Value = Value + bet;
        cout<<"\n\n Your sum now is : "<<Value;
    }
    else
    if(ScoreP == ScoreH)
        cout<<"\n It's draw !\n\n";
    else if(ScoreP == 21)
    {
        cout<<"\n\t\t BLACKJACK - 21 \n\n";
        cout<<"\t You win "<<bet<<" $ !\n\n";
        Value = Value + bet;
        cout<<"\n\n Your sum now is : "<<Value;
    }
    else if(ScoreH == 21)
    {
        cout<<"\n\t You lost "<<bet<<" $ !\n";
        Value = Value - bet;
        cout<<"\n\n Your sum now is : "<<Value;
    }
    else
    {
        if(ScoreP >ScoreH)
        {
            cout<<"\t You win "<<bet<<" $ !\n\n";
            Value = Value + bet;
            cout<<"\n\n Your sum now is : "<<Value;
        }
        else
        {
            cout<<"\n\t You lost "<<bet<<" $ !\n";
            Value = Value - bet;
            cout<<"\n\n Your sum now is : "<<Value;
        }
    }


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
void Print_card(int number)
{
    int color = number / 13;
    int rankk = number % 13;
    cout<<"\t"<<Ranks[rankk]<<" of "<<Colors[color]<<endl;

}
void Print_current_cards_and_score(int cards[] , int numbercards)
{
    int ScoreCurrent = Score(cards, numbercards);
    cout<<"\n Your Cards are :\n\n";
    for(int i=0;i<numbercards;i++)
        Print_card(cards[i]);
    cout<<"\n Your score is : "<<ScoreCurrent<<endl;
}
void shuffle()
{
    for(int i=0;i<52;i++)
        CardsDealt[i] = false;
}

