//Name: Chloe Mitchell
//File Name: prog2.cpp
// Date: 09 October, 2023
// Program Description: This is the driver file that includes the main program. The main program plays a game
//of simple solitaire by taking in a file as the deck and uses a linked list to represent the player's
//hand. The game ends only when the deck runs out of cards (the file reaches the end).


#include <iostream>
#include "cards.h"
using namespace std;

int main(int argc, char* argv[]) {

    if(argc == 1){
        cout << "No file has been entered" << endl;
        return 0;
    }
    int roundCount = 1;
    int numCards = 0;

    ifstream inFile(argv[1]); //opening file
    if(!inFile) { //checking if its in the file
        cout << "Not in file!" << endl;
        exit(0);
    }

    Card* head = NULL; //creating empty linked list
    string line;
    char suit;
    int rank;
    while(getline(inFile, line)){ //getting each line from file and making it a string
        if(line.size() >= 2) {
            suit = line.back();
            rank = convertRankToInt(line.substr(0, line.size() - 1));
            insertCard(head, rank, suit);
            numCards++;
            cout << roundCount <<": ";
            displayHand(head);
            cout<<endl;

            //checking to make sure there are enough cards to be able to compare the 1st and 4th card
            //and ensures that cards can be deleted by comparing rank and suit to see if they are the same
            while(numCards>=4 && (head->rank == head->next->next->next->rank || head->suit == head->next->next->next->suit)) {
                discardCards(head, numCards);
                cout << "    ";
                displayHand(head);
                cout<<endl;
            }
            roundCount++;
        }
    }
    inFile.close(); //closes file

    return 0;
}

