/*
COP3223 Summer 2023 Lab7B
Copyright 2023 Choudhari Katelyn
*/

//Modify the program in below(Fig. 7.16 in text book) so that the card - dealing function deals a five - card poker hand.Then write the following additional functions :
//a) Determine whether the hand contains a pair.
//b) Determine whether the hand contains two pairs.
//c) Determine whether the hand contains three of a kind(e.g., three jacks).
//d) Determine whether the hand contains four of a kind(e.g., four aces).
//e) Determine whether the hand contains a flush(i.e., all five cards of the same suit).
//f) Determine whether the hand contains a straight(i.e., five cards of consecutive face values).

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define SUITS 4
//#define FACES 13
//#define CARDS 52
//#define HAND 5
//
////prototype
//void shuffle(int deck[SUITS][FACES]);
//void deal(int deck[SUITS][FACES]);
//
//int pair(const int hand[]);
//int two_pair(const int hand[]);
//int three_of_kind(const int hand[]);
//int four_of_kind(const int hand[]);
//int flush(const int hand[]);
//int straight(const int hand[]);
//
//const char* face[];
//const char* suit[];
//
//int main(void) {
//	//init deck array
//	int deck[SUITS][FACES] = { 0 };
//
//	srand(time(NULL)); //seed random-number generator
//	shuffle(deck); //shuffle the deck
//
//	//init suit array
//	const char* suit[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
//
//	//init face array
//	const char* face[FACES] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
//
//	deal(deck, face, suit); //deal the deck
//
//	int hand[5] = { 0 };
//	//int hand[5] = { 3,4,5,6,9 };  // for debugging
//
//	for (int i = 0; i < HAND; i++) {
//		hand[i] = deck[0][i];
//	}
//
//
//	if (pair(hand))
//		printf("%s","\nWe have a pair!");
//	if (two_pair(hand))
//		printf("%s", "\nWe have two pairs!");
//	if (three_of_kind(hand))
//		printf("%s", "\nWe have three of a kind!");
//	if (four_of_kind(hand))
//		printf("%s", "\nWe have four of a kind!");
//	if (flush(hand))
//		printf("%s", "\nWe have a flush!");
//	if (straight(hand))
//		printf("%s", "\nWe have a straight!");
//}
//
////shuffle cards in deck
//void shuffle(int deck[][FACES]) {
//	//for each of the cards, choose slot of deck randomly
//	for (size_t card = 1; card <= CARDS; ++card) {
//		size_t row = 0; //row number
//		size_t column = 0; // column number
//
//		//choose new random location until unoccupied slot found
//		do {
//			row = rand() % SUITS;
//			column = rand() % FACES;
//		} while (deck[row][column] != 0);
//
//		deck[row][column] = card; // place card number in chosen slot
//	}
//}
//
////deal cards in deck
//void deal(int deck[][FACES], const char *face[], const char *suit[]) {
//	//deal each of the cards
//	for (size_t card = 1; card <= CARDS; ++card) {
//		//loop through rows of deck
//		for (size_t row = 0; row < SUITS; ++row) {
//			//loop through columns of deck for current row
//			for (size_t column = 0; column < FACES; ++column) {
//				// if slot contains current card, display card
//				if (deck[row][column] == card) {
//					printf("%5s of %-8s  %c", face[column], suit[row],
//						card % 4 == 0 ? '\n' : '\t'); // 2-column format
//				}
//			}
//		}
//	}
//}
//
//int pair(const int hand[]) {
//	int frequency[FACES] = { 0 };
//	for (size_t i = 0; i < HAND; i++) {
//		int face = hand[i] % FACES;
//		frequency[face]++;
//	}
//
//	for (size_t i = 0; i < FACES; i++) {
//		if (frequency[i] == 2) {
//			return 1;
//		}
//	}
//
//	return 0;
//}
//
//int two_pair(const int hand[]) {
//	int frequency[FACES] = { 0 };
//	int pairs = 0;
//
//	for (size_t i = 0; i < HAND; i++) {
//		int face = hand[i] % FACES;
//		frequency[face--]++;
//	}
//
//	for (size_t i = 0; i < FACES; i++) {
//		if (frequency[i] == 2) {
//			++pairs;
//		}
//	}
//
//	return (pairs == 2);
//}
//
//int three_of_kind(const int hand[]) {
//	int frequency[FACES] = { 0 };
//
//	for (size_t i = 0; i < HAND; i++) {
//		int face = hand[i] % FACES;
//		frequency[face--]++;
//	}
//
//	for (size_t i = 0; i < FACES; i++) {
//		if (frequency[i] == 3) {
//			return 1;
//		}
//	}
//
//	return 0;
//
//}
//int four_of_kind(const int hand[]) {
//	int frequency[FACES] = { 0 };
//
//	for (size_t i = 0; i < HAND; i++) {
//		int face = hand[i] % FACES;
//		frequency[face--]++;
//	}
//
//	for (size_t i = 0; i < FACES; i++) {
//		if (frequency[i] == 4) {
//			return 1;
//		}
//	}
//
//	return 0;
//
//}
//int flush(const int hand[]) {
//	int suitFrequency[SUITS] = { 0 };
//
//	for (size_t i = 0; i < HAND; i++) {
//		int suit = (hand[i] - 1) / FACES;
//		suitFrequency[suit]++;
//	}
//
//	for (size_t i = 0; i < SUITS; i++) {
//		if (suitFrequency[i] == HAND) {
//			return 1;
//		}
//	}
//
//	return 0;
//
//}
//int straight(const int hand[]) {
//	int sort[HAND] = { 0 };
//	
//	for (size_t i = 0; i < HAND; i++) {
//		sort[i] = hand[i] % FACES;	
//	}
//
//	for (size_t i = 0; i < HAND - 1; i++) {
//		for (size_t j = 0; j < HAND - i - 1; j++) {
//			if (sort[j] > sort[j + 1]) {
//				int temp = sort[j];
//				sort[j] = sort[j + 1];
//				sort[j + 1] = temp;
//			}
//		}
//	}
//
//	for (size_t i = 0; i < HAND - 1; i++) {
//		int current_num = sort[i];
//		int next_num = sort[i+1];
//		if ((current_num  +1) != next_num) {
//			return 0;
//		}
//	}
//
//	return 1;
//}