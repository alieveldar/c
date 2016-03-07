/*
 * blj.c
 *
 *  Created on: Mar 7, 2016
 *      Author: modus
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
const int deckSize = 52;

struct cards {
	char suit[2];
	char name[3];
	int score;
};
struct cards deck[52];
char names[14] = { '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K',
		'A' };
char suits[5] = { 'D', 'H', 'C', 'S' };
int scores[13] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 1 };


void fillDeck(void);
void printDeck();
void shuffleDeck();

int main(void) {
	fillDeck();
	printf("----------------------------------------------------\n");
	printf("%s,%s,%i\n", deck[0].suit, deck[0].name, deck[0].score);
	printf("----------------------------------------------------\n");
	printf("----------------------------------------------------\n");
	/*printDeck();*/
	shuffleDeck();
	printDeck();
	return 0;
}
void fillDeck() {
	int counterdeck = 0, countersuits = 0, counterscores = 0, counternames = 0;
	for (counterdeck = 0; counterdeck < deckSize; counterdeck++) {
		deck[counterdeck].suit[0] = suits[countersuits];
		countersuits++;
		if (countersuits == 4) {
			countersuits = 0;
		}
		deck[counterdeck].name[0] = names[counternames];
		counternames++;
		if (counternames == 13) {
			counternames = 0;
		}
		deck[counterdeck].score = scores[counterscores];
		counterscores++;
		if (counterscores == 13) {
			counterscores = 0;
		}
	};

}
void printDeck() {
	int index = 0;
	for (index = 0; index < deckSize; index++) {
		printf("----------------------------------------------------\n");
		printf("%s , %s , %i \n", deck[index].name, deck[index].suit,
				deck[index].score);
		printf("----------------------------------------------------\n");
		printf("%i Crads in Deck\n", index);
		printf("----------------------------------------------------\n");

	}
}
void shuffleDeck() {
	int shuffletime, index1, index2, counter;
	struct cards container;
	srand(time(NULL));
	shuffletime = (rand() % 100000);
	printf("%i\n", shuffletime);
	for (counter = 0; counter < shuffletime; counter++) {
		index1 = (rand() % 52);
		index2 = (rand() % 52);
		container = deck[index1];
		deck[index1] = deck[index2];
		deck[index2] = container;
	}

}






