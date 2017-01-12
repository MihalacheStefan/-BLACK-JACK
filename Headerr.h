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
bool samename( char name1[41] ,char name2[41]);
