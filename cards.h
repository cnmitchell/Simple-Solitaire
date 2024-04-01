// Name: Chloe Mitchell
// File Name: cards.h
// Date: 09 October, 2023
// Program Description: this is the header file that contains all the function declarations needed for the driver file
//to do it jobs correctly

#ifndef SIMPLESOLITAIRE_CARDS_H
#define SIMPLESOLITAIRE_CARDS_H
#endif //SIMPLESOLITAIRE_CARDS_H
#include<fstream>
using namespace std;

struct Card{
    int rank;
    char suit;
    Card* next;
};

int convertRankToInt(const string&);
string convertRankToString(int);
void insertCard(Card*& head, int, char);
void discardCards(Card*&, int&);
void displayHand(Card*&);
string convertSuit(char suit);
