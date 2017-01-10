#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cstring>
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
int Can_continue(char name[41]);
int restore_value( int line ) ;
int Score(int Cards[] , int number);
int Points( int card );
void Print_card(int number);
void Print_current_cards_and_score(int cards[] , int numbercards);
void Player_vs_Computer_Game(int & Value);
void Rewrite_value_file(int line , int value);
int Add_new_line_in_file(char name[41]);
void show_history_pvc();
void show_hystory_pvc_buffer(char buffer[101]);
void Add_new_history(int decision);
void Player_vs_Player();
void Player_vs_Player_Game( char name1[41] ,char name2[41] ,int &Value1 ,int &Value2 ,int bet );
void Get_new_card_new_score(int PlayerCards[] ,int &Numbercards ,int &Scoree);
int winner_pvp(int ScoreP1 ,int ScoreP2 , int ScoreH);
int bettok();

int main()
{
    srand(time(NULL));
    introduction();
    cout<< "                        Press ENTER to continue!"<<endl;
    cin.get();
    system("cls");
    char optiune;
    do {
            Menu();
            cin>>optiune;
            while(optiune != '1' && optiune !='2' && optiune != '3' && optiune != '4' && optiune != '5')
            {
                cout<<"\n\n\t Enter a value between 1 and 5 : ";
                cin>>optiune ;
            }
            if(optiune == '1')
                Rules();
            if(optiune == '2')
                Player_vs_Computer();
            if(optiune == '3')
                Player_vs_Player();
            if(optiune == '4')
                show_history_pvc();
            system("cls");
    }while(optiune != '5');

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
    cout <<"\t\t\t"<<"2. Player vs Computer -----------|"<<endl;
    cout <<"\t\t\t"<<"3. Player vs Player -------------|"<<endl;
    cout <<"\t\t\t"<<"4. History PvC-------------------|"<<endl;
    cout <<"\t\t\t"<<"5. Exit--------------------------|"<<endl;
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
    cout<<"_______________________________________________________________________________\n"<<'\n';
    cout<<"Press ENTER to go back to Menu . ";
    cin.get();
    cin.get();

}
void Player_vs_Computer()
{
    system("cls");
    cout<<"\n\tEnter your name :\n\n\t\t\t  ";
    cin.get();
    char name[41];
    int Value = 20;
    cin>>name;
    int continue_file = Can_continue(name);

    if( continue_file != 0 )
    {
        int val = restore_value(continue_file);
        if(val != 0)
        {
            cout<<"\n Do you want to continue ?\n";
            cout<<"\n Yes (y) , No (n) \n\t";
            char decision;
            cin>>decision;
            while(decision != 'y' && decision != 'Y' && decision != 'n' && decision != 'N')
            {
                cout<<"\n\n\t Enter y or n ! \n\t\t";
                cin>>decision;
            }
            if(decision == 'y' || decision == 'Y')
                Value = val;

        }
    }

    Player_vs_Computer_Game(Value);
    int linie;
    if(continue_file == 0)
    {
        int newline = Add_new_line_in_file(name);
        linie = newline;
        Rewrite_value_file(newline , Value);
        //adaug numele in "continue_name"
        //adaug Value pe linia nou creata
    }
    else
        Rewrite_value_file(continue_file , Value);

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
                if(continue_file == 0)
                    Rewrite_value_file(linie , Value);
                else
                    Rewrite_value_file(continue_file , Value);
           }
        else if(play_again == 'n' || play_again == 'N' )
            break ;
        else
            cout<<"******************************************************\n Enter y or n ! ";
    }
    if(Value == 0)
    {
        cout<<"\n\n\n\t You lost all money ! \n\n Press ENTER to go back to Menu : ";
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
    cout<<"\n How much do you want to bet ?\n\n\t";
    int bet=bettok();

    while(bet<1 || bet > Value)
    {
        cout<<"\n Enter a bet between 1 and "<<Value<<endl;
        cout<<'\t';
        bet = bettok();
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

    cout<<"\n\n\n Dealer's second card is : \n\n";
    Print_card(HousCards[1]);

    if(ScoreP == 21)
    {
        cout<<"\n\n\n\t\t BLACKJACK - 21 \n\n\n";
        cout<<"\t You win "<<bet<<" $ !\n\n";
        Add_new_history(0);
        Value = Value + bet;
        cout<<"\n\n Your sum now is : "<<Value;
        return;
    }

    Get_new_card_new_score(PlayerCards , NumbercardsP ,ScoreP);

    if(ScoreP > 21)
    {
        cout<<"\n\n\t\t You lost "<< bet <<'$';
        Add_new_history(1);
        Value = Value - bet;
        cout<<"\n\n Your sum now is : "<<Value;
        return;
    }
    while(ScoreH < 17)
    {
        HousCards[NumbercardsH++] = NewCard();
        ScoreH = Score(HousCards , NumbercardsH);
    }
    cout<<"\n Dealer's cards are :\n";
    for(int i=0;i<NumbercardsH;i++)
        Print_card(HousCards[i]);
    cout<<"\n Dealer's score is : " << ScoreH <<"\n\n";
    if(ScoreH > 21)
    {
        cout<<"\t You win "<<bet<<" $ !\n";
        Add_new_history(0);
        Value = Value + bet;
        cout<<"\n\n Your sum now is : "<<Value;
    }
    else
    if(ScoreP == ScoreH)
    {
        cout<<"\n It's draw !\n\n";
        Add_new_history(2);
    }
    else if(ScoreP == 21)
    {
        cout<<"\n\t\t BLACKJACK - 21 \n\n";
        cout<<"\t You win "<<bet<<" $ !\n\n";
        Add_new_history(0);
        Value = Value + bet;
        cout<<"\n\n Your sum now is : "<<Value;
    }
    else if(ScoreH == 21)
    {
        cout<<"\n\t You lost "<<bet<<" $ !\n";
        Add_new_history(1);
        Value = Value - bet;
        cout<<"\n\n Your sum now is : "<<Value;
    }
    else
    {
        if(ScoreP >ScoreH)
        {
            cout<<"\t You win "<<bet<<" $ !\n\n";
            Add_new_history(0);
            Value = Value + bet;
            cout<<"\n\n Your sum now is : "<<Value;
        }
        else
        {
            cout<<"\n\t You lost "<<bet<<" $ !\n";
            Add_new_history(1);
            Value = Value - bet;
            cout<<"\n\n Your sum now is : "<<Value;
        }
    }


}
int Can_continue(char name[41])
{
    ifstream fin("continue_name.txt");
    fin.seekg(0 ,fin.end);
    int length = fin.tellg();
    fin.seekg(0,fin.beg);

    char * buffer = new char [length];
    fin.read(buffer , length);
    fin.close();

    int nr=0;
    char *parcurg = strchr(buffer , '\n');
    while(parcurg)
    {
        nr++;
        int i=1;
        while(i<strlen(parcurg) && parcurg[i]!= '\n')
            i++;
        parcurg = strchr(parcurg+i ,'\n');
    }
    length = length - nr;

    ofstream fout("continue_name.txt");
    fout.write(buffer , length);

    buffer[length] = NULL;
    if(strstr(buffer ,name ) == NULL)
        return 0;
    char *p = buffer;
    int nr_linii = 0;
    int i=0;
    while(i<strlen(buffer) && buffer[i]!= '\n')
            i++;
    int ok=1;
    if(i == strlen(name))
    {
        for(int j=0;j<strlen(name);j++)
            if(buffer[j] != name[j])
                ok=0;
    }
    else
        ok=0;

    nr_linii = 1 ;
    if(ok == 1)
        return nr_linii;
    p=strchr(buffer ,'\n');
    while(p)
    {
        nr_linii++;
        int i=1;
        while(i<strlen(p) && p[i]!= '\n')
            i++;
        int ok=1;
        if(i == strlen(name)+1)
        {
            for(int j=0;j<strlen(name);j++)
                if(p[j+1] != name[j])
                    ok=0;
        }
        else ok=0;
        if(ok == 1)
            return nr_linii;
        p = strchr(p+i,'\n');
    }
    return 0;
}
int restore_value( int line )
{
    ifstream fin("continue_value.txt");
    fin.seekg(0 ,fin.end);
    int length = fin.tellg();
    fin.seekg(0,fin.beg);

    char * buffer = new char [length];
    fin.read(buffer , length);
    fin.close();

    int nr=0;
    char *parcurg = strchr(buffer , '\n');
    while(parcurg)
    {
        nr++;
        int i=1;
        while(i<strlen(parcurg) && parcurg[i]!= '\n')
            i++;
        parcurg = strchr(parcurg+i ,'\n');
    }
    length = length - nr;

    ofstream fout("continue_value.txt");
    fout.write(buffer , length);

    buffer[length] = NULL;
    int value = 0 ;
    if(line == 1)
    {
        int i=0;
        while(i<strlen(buffer) && buffer[i] != '\n')
        {
            value = value * 10 + ( buffer[i] - '0' );
            i++;
        }
        return value;
    }
    char *p = buffer;
    int nr_linii = 2;
    p = strchr(buffer , '\n');
    while( nr_linii != line)
    {
        nr_linii ++;
        int i= 1 ;
        while(i<strlen(p) && p[i] != '\n')
            i++;
        p=strchr(p+i, '\n');
    }
    int i=1;
    while(i<strlen(p) && p[i] != '\n')
    {
        if(p[i] >= '0' && p[i]<= '9')
            value = value * 10 + ( p[i] - '0' );
        i++;
    }
    return value;
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
void Rewrite_value_file(int line , int value)
{
    ifstream fin("continue_value.txt");
    fin.seekg(0 ,fin.end);
    int length = fin.tellg();
    fin.seekg(0,fin.beg);

    char * buffer = new char [length];
    fin.read(buffer , length);
    fin.close();

    int nr=0;
    char *parcurg = strchr(buffer , '\n');
    while(parcurg)
    {
        nr++;
        int i=1;
        while(i<strlen(parcurg) && parcurg[i]!= '\n')
            i++;
        parcurg = strchr(parcurg+i ,'\n');
    }
    length = length - nr;
    buffer[length] = NULL;
    char * p = buffer;
    int nr_value_old = 0 ,nr_value_new = 0 ,invers[30] ,nr_cifre_invers = 0;

    while(value != 0)
    {
        nr_value_new++;
        invers[ nr_cifre_invers++ ] = value%10;
        value = value/10;
    }

    if(line == 1)
    {
        while(nr_value_old < strlen(buffer) && buffer[nr_value_old] != '\n')
            nr_value_old++;

        p = strchr(buffer , '\n');
        char copyy[length];
        strcpy(copyy , p);

        int i=0,k=0;
        while(k < nr_cifre_invers)
        {
            buffer[i++] = invers[nr_cifre_invers-k-1] + '0';
            k++;
        }

        strcpy(buffer + i , copyy);
    }
    else
    {
        int nr_linii = 2;
        p = strchr(buffer , '\n');
        while(nr_linii != line)
        {
            nr_linii ++;
            int i= 1 ;
            while(i<strlen(p) && p[i] != '\n')
                i++;
            p=strchr(p+i, '\n');
        }
        char copyy[length], *q;
        q = strchr(p+1,'\n');
        strcpy(copyy , q);

        int j=1, k=0 ;
        while(j<strlen(p) && p[j] != '\n')
            j++;
        nr_value_old = j-1;
        j=1;
        while(k < nr_cifre_invers )
        {
           p[j++] = invers[nr_cifre_invers-k-1] + '0';
           k++;
        }

        strcpy(p+j , copyy);
    }

    ofstream fout("continue_value.txt");
    fout.write(buffer , length - nr_value_old + nr_value_new );
}
int Add_new_line_in_file(char name[41])
{
    int line = 1;
    ifstream fin("continue_name.txt");
    fin.seekg(0 ,fin.end);
    int length = fin.tellg();
    fin.seekg(0,fin.beg);

    char * buffer = new char [length];
    fin.read(buffer , length);
    fin.close();

    int nr=0;
    char *parcurg = strchr(buffer , '\n');
    while(parcurg)
    {
        nr++;
        int i=1;
        while(i<strlen(parcurg) && parcurg[i]!= '\n')
            i++;
        parcurg = strchr(parcurg+i ,'\n');
    }
    length = length - nr;
    buffer[length] = NULL;
    ofstream fout("continue_name.txt");
    fout.write(buffer , length );

    char *p = strchr(buffer , '\n');
    while(p)
    {
        line++;
        p = strchr(p+1 ,'\n');
    }
    fout.write(name,strlen(name));
    fout.write("\n",1);
    fout.close();
    //  value file

    ifstream ffin("continue_value.txt");
    ffin.seekg(0 ,ffin.end);
    length = ffin.tellg();
    ffin.seekg(0,ffin.beg);

     buffer = new char [length];
    ffin.read(buffer , length);
    ffin.close();

    nr=0;
    parcurg = strchr(buffer , '\n');
    while(parcurg)
    {
        nr++;
        int i=1;
        while(i<strlen(parcurg) && parcurg[i]!= '\n')
            i++;
        parcurg = strchr(parcurg+i ,'\n');
    }
    length = length - nr;
    buffer[length] = NULL;


    ofstream ffout("continue_value.txt");
    ffout.write(buffer , length );
    ffout.write("0\n",2);

    return line;
}
void show_history_pvc()
{
    system("cls");
    ifstream fin("history_PvC.txt");
    fin.seekg(0 ,fin.end);
    int length = fin.tellg();
    fin.seekg(0,fin.beg);

    char * buffer = new char [length];
    fin.read(buffer , length);
    fin.close();
    int nr=0;
    char *parcurg = strchr(buffer , '\n');
    while(parcurg)
    {
        nr++;
        int i=1;
        while(i<strlen(parcurg) && parcurg[i]!= '\n')
            i++;
        parcurg = strchr(parcurg+i ,'\n');
    }
    length = length - nr;
    buffer[length] = NULL;

    ofstream fout("history_PvC.txt");

    int line ;
    if(nr > 10)
        line = nr-10;
    else
        line = 0;
    if(line == 0)
      {
        fout.write(buffer , length );
        show_hystory_pvc_buffer(buffer);
      }
    else
    {
        char *p = buffer;
        int i=1;
        p = strchr(buffer, '\n');
        if(line != 1 )
            while(i<line)
            {
                p=strchr(p+1,'\n');
                i++;
            }
        strcpy(p ,p+1);     //sterg endl
        fout.write(p , strlen(p));
        show_hystory_pvc_buffer(p);
    }
    cin.get();
    cin.get();
}
void show_hystory_pvc_buffer(char buffer[101])
{
    int n = strlen(buffer);
    int i=0,t=1;
    cout<<"\n\n\t\t   History \n\n\n";
    while(i<n )
    {
        if(t != 10)
            cout<<"\t"<<t<<".  ";
        else
            cout<<"\t"<<t<<". ";
        t++;
        if(buffer[i] == '0')
            cout<<"Win\n";
        else
            if(buffer[i] == '1')
                cout<<"Lose\n";
        else
            cout<<"Draw\n";
        i=i+2;
    }
    cout<<"\n\n  Press ENTER to continue . ";
}
void Add_new_history(int decision)
{
    ifstream fin("history_PvC.txt");
    fin.seekg(0 ,fin.end);
    int length = fin.tellg();
    fin.seekg(0,fin.beg);

    char * buffer = new char [length];
    fin.read(buffer , length);
    fin.close();

    length = strlen(buffer);
    buffer[length] = NULL;
    ofstream fout("history_PvC.txt");
    fout.write(buffer , length );
    if(decision == 0)
        fout.write("0\n" , 2);
    if(decision == 1)
        fout.write("1\n" , 2);
    if(decision == 2)
        fout.write("2\n" , 2);
}
void Player_vs_Player()
{
    system("cls");
    cout<<"\n\n\t\t\t Player vs Player mode \n\n\n";
    char name1[41], name2[41];
    cout<<"  Player 1 enter your name : ";
    cin>>name1;
    cout<<"\n\n  Player 2 enter your name : ";
    cin>>name2;
    int Value1 = 20 ,Value2 = 20 , bet;
    cout<<"\n\n Your initial sum is : 20 $ ";
    cout<<"\n\n Enter your bet : ";
    bet = bettok();
    while(bet > 20 || bet < 1)
    {
        cout<<"\n\n Enter a bet between 1 and 20 : ";
        bet =bettok();
    }
    cout<<"\n\n\t Press ENTER to continue :";
    cin.get();
    Player_vs_Player_Game(name1 , name2, Value1 ,Value2 , bet);


     while(Value1 != 0 && Value2 != 0)
    {
        system("cls");
        cout<<"\n "<<name1<<"'s sum is : "<< Value1 <<"\n";
        cout<<"\n "<<name2<<"'s sum is : "<< Value2 <<"\n";

        cout<<"\n\n Do you want to play again ?\n";
        cout<<"Yes (y) , No (n) \n\t";
        char play_again;
        cin>>play_again;

        while(play_again != 'y' && play_again != 'Y' && play_again != 'n' && play_again != 'N')
            {
                cout<<"\n\t Enter y or n ! \n\t\t";
                cin>>play_again;
            }

        if(play_again == 'y' || play_again == 'Y' )
           {
                shuffle();
                cout<<"\n\n Enter your bet : ";
                bet = bettok();
                int minim=Value1;
                if(Value2 < minim)
                    minim = Value2;
                while(bet > minim || bet < 1)
                {
                    cout<<"\n Enter a bet between 1 and "<<minim<<" : ";
                    bet =bettok();
                }
                Player_vs_Player_Game(name1 , name2, Value1 ,Value2 , bet);
           }
        else if(play_again == 'n' || play_again == 'N' )
            break ;

    }
    system("cls");
    if(Value1 == 0)
    {
        cout<<"\n\n\t"<<name1<<" lost all money !" ;
        cout<<"\n\n\n\t"<<name2<<" is the winner !";
        cout<<"\n\n Press ENTER to continue :";
        cin.get();
    }
    if(Value2 == 0)
    {
        cout<<"\n\n\t"<<name2<<" lost all money !" ;
        cout<<"\n\n\n\t"<<name1<<" is the winner !";
        cout<<"\n\n Press ENTER to continue :";
        cin.get();
    }


}
void Player_vs_Player_Game( char name1[41] ,char name2[41] ,int &Value1 ,int &Value2 ,int bet )
{
    system("cls");
    int Player1Cards[20] , Player2Cards[20] , HouseCards[20] , NumbercardsP1 , NumbercardsP2 , NumbercardsH , ScoreP1 , ScoreP2 ,ScoreH ;

    Player1Cards[0] = NewCard();
    Player1Cards[1] = NewCard();
    NumbercardsP1 = 2;
    Player2Cards[0] = NewCard();
    Player2Cards[1] = NewCard();
    NumbercardsP2 = 2;
    HouseCards[0] = NewCard();
    HouseCards[1] = NewCard();
    NumbercardsH = 2;

    ScoreP1 = Score(Player1Cards , NumbercardsP1);
    ScoreP2 = Score(Player2Cards , NumbercardsP2);
    ScoreH = Score(HouseCards , NumbercardsH);

    cout<<"\n\n\n "<<name1 <<"'s second card is : \n\n";
    Print_card(Player1Cards[1]);

    cout<<"\n\n "<<name2 <<"'s second card is : \n\n";
    Print_card(Player2Cards[1]);

    cout<<"\n\n Dealer's second card is : \n\n";
    Print_card(HouseCards[1]);

    cout<<"\n\n\t Press ENTER to continue : ";
    cin.get();

    system("cls");
    cout<<"\n\n  Player 1 turn !";
    cout<<"\n\n\t Press ENTER to continue : ";
    cin.get();

    system("cls");
    cout<<"\n";
    Print_current_cards_and_score(Player1Cards , NumbercardsP1);
    Get_new_card_new_score(Player1Cards, NumbercardsP1 ,ScoreP1);
    cout<<"\n\n\t Press ENTER to continue : ";
    cin.get();

    system("cls");
    cout<<"\n\n  Player 2 turn !";
    cout<<"\n\n\t Press ENTER to continue : ";
    cin.get();

    system("cls");
    cout<<"\n";
    Print_current_cards_and_score(Player2Cards , NumbercardsP2);
    Get_new_card_new_score(Player2Cards ,NumbercardsP2 ,ScoreP2);
    cout<<"\n\n\t Press ENTER to continue : ";
    cin.get();

    while(ScoreH < 17)
    {
        HouseCards[NumbercardsH++] = NewCard();
        ScoreH = Score(HouseCards , NumbercardsH);
    }
    // afisez toate cartile
    system("cls");

    cout<<"\n\n "<<name1<<"'s cards are :\n";
    for(int i=0;i<NumbercardsP1;i++)
        Print_card(Player1Cards[i]);
    cout<<"\n "<<name1<<"'s score is : "<< ScoreP1<<"\n\n";

    cout<<"\n\n "<<name2<<"'s cards are :\n";
    for(int i=0;i<NumbercardsP2;i++)
        Print_card(Player2Cards[i]);
    cout<<"\n "<<name2<<"'s score is : " << ScoreP2 <<"\n\n";

    cout<<"\n Dealer's cards are :\n";
    for(int i=0;i<NumbercardsH;i++)
        Print_card(HouseCards[i]);
    cout<<"\n Dealer's score is : " << ScoreH <<"\n\n\n\t";

    int win = winner_pvp(ScoreP1 ,ScoreP2 ,ScoreH);
    if(win == 0)
        cout<<"It's draw !";
    if(win == 1)
    {
        cout<<name1<<" win !";
        Value1 = Value1 + 2*bet;
        Value2 = Value2 - bet ;
    }
    if(win == 2)
    {
        cout<<name2<<" win !";
        Value2 = Value2 + 2*bet;
        Value1 = Value1 - bet ;
    }
    if(win == 3)
    {
        cout<<"Dealer win !";
        Value1 = Value1 - bet;
        Value2 = Value2 - bet;
    }
    cout<<"\n\n\t Press ENTER to continue : ";
    cin.get();
}
void Get_new_card_new_score(int PlayerCards[] ,int &Numbercards ,int &Scoree)
{
    char wantcard ;
    cout<<"\n\n Do you want another card ? \n Yes (y) , No (n)\n\t";
    cin>>wantcard;
    while(wantcard != 'y' && wantcard != 'Y' && wantcard != 'n' && wantcard !='N' )
    {
        cout<<"\n Enter y or n ! \n\t";
        cin>>wantcard;
    }
    while(wantcard == 'y' ||wantcard == 'Y' && Scoree < 22)
    {
        cout<<"\n________________________________________________________________________________\n\n";
        PlayerCards[Numbercards++] = NewCard();

        Print_current_cards_and_score(PlayerCards , Numbercards);
        Scoree = Score(PlayerCards , Numbercards);
        if(Scoree < 22)
        {
            cout<<"\n\n Do you want another card ? \n Yes (y) , No (n)\n\t";
            cin>>wantcard;
            while(wantcard == 'y' && wantcard == 'Y' && wantcard != 'n' && wantcard !='N' )
            {
                cout<<"\n Enter y or n ! \n\t";
                cin>>wantcard;
            }
            if(wantcard == 'n' ||wantcard == 'N')
                break;
        }
        else {
                wantcard = 'n';
                cin.get();
        }
    }
}
int winner_pvp(int ScoreP1 ,int ScoreP2 , int ScoreH)
{
    int nr21 =0;
    if(ScoreP1 == 21)
        nr21++;
    if(ScoreP2 == 21)
        nr21++;
    if(ScoreH == 21)
        nr21++;
    if(nr21 == 2 || nr21 == 3)
        return 0;

    if(ScoreP1 == 21)
        return 1;
    if(ScoreP2 == 21)
        return 2;
    if(ScoreH == 21)
        return 3;
    int maxim=0,nr=0;
    if(maxim < ScoreP1 && ScoreP1 < 21)
        maxim = ScoreP1;
    if(maxim < ScoreP2 && ScoreP2 < 21)
        maxim =ScoreP2;
    if(maxim < ScoreH && ScoreH < 21)
        maxim =ScoreH;

    if(maxim == ScoreP1)
        nr++;
    if(maxim == ScoreP2)
        nr++;
    if(maxim == ScoreH)
        nr++;
    if(nr == 2 || nr == 3 || nr == 0)
        return 0;

    if(maxim == ScoreP1)
        return 1;
    if(maxim == ScoreP2)
        return 2;
    if(maxim == ScoreH)
        return 3;
}
int bettok()
{
    int bet=0;
    int i=0;
    char bett[11];
    cin>>bett;
    bool betok = true;
    do{
        if(betok == false)
        {
            cout<<"\n Enter an inter value ! \n\t";
            cin>>bett;
        }
        betok = true;
        int i=0;
        while(i<strlen(bett))
        {
            if(bett[i]>= '0' && bett[i] <='9')
                bet = bet *10 + bett[i] - '0';
            else
            {
                betok = false;
                break;
            }
            i++;
        }
    }while(betok == false);
    return bet;
}

