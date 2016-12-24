#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
using namespace std;

const string Ranks[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
const string Colors[4] = {"hearts","diamonds","clubs","spades"};

bool CardsDealt[52];        // cartile tratate


int NewCard();

int main()
{
    srand(time(NULL));          //carti random
    cout<<NewCard()<<endl;
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
