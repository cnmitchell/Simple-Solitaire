// Name: Chloe Mitchell
// File Name: cards.cpp
// Date: 09 October, 2023
// Program Description: this file contains all the functions, defined in the header file, internal code to
//actually work with the driver file through the header file

#include "cards.h"
#include <iostream>
 using namespace std;

//this function converts the rank of the card to its actual int value
int convertRankToInt(const string& str) {
    if(str == "J")
        return 11;
    if(str == "Q")
        return 12;
    if(str == "K")
        return 13;
    if(str == "A")
        return 14;
    return stoi(str);
}

//this function converts the rank of the card back to its original value and makes it a string
string convertRankToString(int num){
    if(num == 11)
        return "J";
    if(num == 12)
        return "Q";
    if(num == 13)
        return "K";
    if(num == 14)
        return "A";
    return to_string(num);
}

//this functions adds a new card at the beginning of the linked list (drawing card from deck)
void insertCard(Card*& head, int rank, char suit){
    Card* pnew = new Card;
    pnew->rank = rank;
    pnew->suit = suit;
    pnew->next = head;
    head = pnew;
    pnew = NULL;
}

//this function compares the 1st and 4th card
//if the suit is the same, the function deletes the 2nd and 3rd card in linked list(discards 2nd and 3rd card from hand)
//if the rank is the same, the function deletes the first 4 cards in linked list (discards the first 4 cards from hand)
void discardCards(Card*& head, int& numCards) {

    //setting fourth card in linked list to walker
    Card *walker = head;
    for (int i = 0; i < 3; i++)
        walker = walker->next;

    //comparing first and fourth card's suit
    if (head->suit == walker->suit) {
        //deleting 2nd and 3rd card in linked list
        for (int i = 0; i < 2; i++) {
            Card *temp = head->next;
            head->next = temp->next;
            delete temp;
            temp = NULL;
            numCards-=1;
        }
    }

    //comparing first and fourth cards rank
    if (head->rank == walker->rank) {
        //deleting first 4 cards in linked list
        for (int i = 0; i < 4; i++) {
            Card *temp = head;
            head = head->next;
            delete temp;
            temp = NULL;
            numCards-= 1;
        }
    }
}

//this function converts the letter of the suit to the symbol that represents the suit
string convertSuit(char suit){
    if(suit == 'H')
        return "\xE2\x99\xA5";
    if(suit == 'D')
        return "\xE2\x99\xA6";
    if(suit == 'C')
        return "\xE2\x99\xA3";
    if(suit == 'S')
        return "\xE2\x99\xA0";
    return "";
}

//this function displays the linked list (player's cards in hand)
    void displayHand(Card*& head){
        Card* walker = head;
        while (walker != NULL)
        {
            cout << convertRankToString(walker->rank) << convertSuit(walker-> suit) << + " ";
            walker = walker->next;
        }
    }