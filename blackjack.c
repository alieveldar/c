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
#include<alloca.h>
const int deckSize = 52;
const int Player = 1;
const int Dealer = 0;
int deckCounter = 52;
int playerHandCounter = 0;
int dealerHandCounter = 0;
int scorePlayerHand = 0;
int checkPlayerHand = 1;
char userAnswer;

struct cards {
	char suit[2];
	char name[3];
	int score;
};
struct cards deck[52];
struct cards playerHand[10];
struct cards dealerHand[10];
char names[14] = { '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K',
		'A' };
char suits[5] = { 'D', 'H', 'C', 'S' };
int scores[13] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 1 };

void fillDeck(void);
void printDeck();
void shuffleDeck();
void checkDeck();
void passCard(struct cards *hand, int person);
void Ask();
void Choice();
void PrintHand();
void CheckHand();
void getWinner();

int main(void) {
	fillDeck();
	shuffleDeck();
	passCard(playerHand, Player);
	passCard(playerHand, Player);
	PrintHand();
	printf("You score is (%i).        ", scorePlayerHand);
	do {
		CheckHand();
		Ask();
		Choice();
		PrintHand();
		printf("You score is (%i).    ", scorePlayerHand);
	} while ((userAnswer == 'y' || userAnswer == 'Y'));
	getWinner();
	return 0;
}
void fillDeck() {
	int counterdeck = 0;
	int countersuits = 0;
	int counterscores = 0;
	int counternames = 0;
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
		printf("%i Cards in Deck\n", index);
		printf("----------------------------------------------------\n");

	}
}
void shuffleDeck() {
	int shuffletime, index1, index2, counter;
	struct cards container;
	srand(time(NULL));
	shuffletime = (rand() % 10000);
	for (counter = 0; counter < shuffletime; counter++) {
		index1 = (rand() % 52);
		index2 = (rand() % 52);
		container = deck[index1];
		deck[index1] = deck[index2];
		deck[index2] = container;
	}

}
void checkDeck() {
	int counter, testingscore;
	int suitcounter = 0;
	int scorecounter = 0;
	char choice;
	printf("-----------8888888888888888888888888----------------------\n");
	printf("Please add card suit D, C, H or S ");
	scanf("%c", &choice);
	printf("The choice is %c", choice);

	for (counter = 0; counter < deckSize; counter++) {
		if (deck[counter].suit[0] == choice) {
			suitcounter = suitcounter + 1;

		}
	}
	printf("The number of cards of the suit - %i\n", suitcounter);
	printf("Please add card score  ");
	scanf("%i", &testingscore);
	for (counter = 0; counter < deckSize; counter++) {
		if (deck[counter].score == testingscore) {
			scorecounter = scorecounter + 1;
		}
	}
	printf("The number of cards with you score is %i\n", scorecounter);

}
void passCard(struct cards *hand, int person) {
	int size = 0;
	struct cards tempContainer[1];
	size = deckCounter - 1;
	if (person == 1) {
		tempContainer[0] = deck[size];
		playerHand[playerHandCounter] = tempContainer[0];
		playerHandCounter = playerHandCounter + 1;
	} else {
		tempContainer[0] = deck[size];
		dealerHand[dealerHandCounter] = tempContainer[0];
		dealerHandCounter = dealerHandCounter + 1;
	}
	deckCounter = size;

}
void Ask() {
	printf("       Do you want another card ? TYpe Y or N ");
	scanf("%s", &userAnswer);
}

void Choice() {
	if (userAnswer == 'y' || userAnswer == 'Y') {
		passCard(playerHand, Player);
	}
}

void PrintHand() {
	int index = 0;
	int temp = 0;
	int scores = 0;
	for (index = 0; index < playerHandCounter; index++) {
		printf("----------------------------------------------------\n");
		printf("%s , %s , %i \n", playerHand[index].name,
				playerHand[index].suit, playerHand[index].score);
		printf("----------------------------------------------------\n");
		printf("----------------------------------------------------\n");
		temp = playerHand[index].score;
		scores = scores + temp;
		scorePlayerHand = scores;
	}
}
void CheckHand() {
	int index = 0;
	int temp = 0;
	for (index = 0; index < playerHandCounter; index++) {
		temp = playerHand[index].score;
		scorePlayerHand = scorePlayerHand + temp;
	}
}

void getWinner() {
	int index = 0;
	int temp = 0;
	int score = 0;
	int checkdeal;

	do {
		passCard(dealerHand, Dealer);
		temp = dealerHand[index].score;
		score = score + temp;
		index = index + 1;

	} while (score <= 17);
	if (score > 21) {
		checkdeal = 0;
	} else {
		checkdeal = 1;
	}
	if (scorePlayerHand > 21) {
		checkPlayerHand = 0;
	} else {
		checkPlayerHand = 1;
	}
	if (checkdeal < checkPlayerHand) {
		printf("You win!!! You score is %i   Dealer score is %i \n", scorePlayerHand,
				score);
	}
	if (checkdeal > checkPlayerHand) {
		printf("You Loose!!! You score is %i   Dealer score is %i \n",
				scorePlayerHand, score);
	}
	if ((checkdeal == checkPlayerHand) && (checkdeal == 1)) {
		if (score > scorePlayerHand) {
			printf("You Loose!!! You score is %i   Dealer score is %i \n",
					scorePlayerHand, score);
		} else {
			printf("You win!!! You score is %i   Dealer score is %i \n",
					scorePlayerHand, score);
		}
	}
	if ((checkdeal == checkPlayerHand) && (checkdeal == 0)) {
		printf("Nobody win!!! You score is %i   Dealer score is %i \n",
				scorePlayerHand, score);
	}

}

