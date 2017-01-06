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
                show_history_pvc();
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
            if(decision == 'y' || decision == 'Y')
                Value = val;
        }
    }

    Player_vs_Computer_Game(Value);

    if(continue_file == 0)
    {
        int newline = Add_new_line_in_file(name);

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
           }
        else if(play_again == 'n' || play_again == 'N' )
            break ;
        else
            cout<<"******************************************************";
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
    cout<<"\n How much do you want to bet ?\n\n\t";
    cin>>bet;
    while(bet<1 || bet > Value)
    {
        cout<<"Enter a bet between 1 and "<<Value<<endl;
        cin.get();
        cout<<'\t';
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
        cout<<"\n\n\n\t\t BLACKJACK - 21 \n\n\n";
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


