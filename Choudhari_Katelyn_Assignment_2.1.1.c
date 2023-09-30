/*
COP3223 Summer 2023 Assignment 2.1
Copyright 2023 Choudhari Katelyn
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//A number guessing game that has 3 levels of difficulty

int guessing_game(int number); //function prototype

int main(void) {
	//init variables
	srand(time(NULL));//gets random number
	int play_again = 1;//init game play to start

	while (play_again) { //loop while play_again = 1 or YES
		int difficulty;
		printf("%s", "Let's play Guess the Number\n");
		printf("%s", "Pick a difficulty level (1,2,3): ");//gets user difficulty level
		scanf_s("%d", &difficulty);//reads difficulty level

		//based on difficulty level chosen by the user
		//the following if, else conditions will call the
		//function guessing_game and pass the paramenter with
		//the max range value for that difficulty level
		if (difficulty == 1) {
			guessing_game(10);
		}
		else if (difficulty == 2) {
			guessing_game(100);
		}
		else if (difficulty == 3) {
			guessing_game(1000);
		}

		puts("Play again? YES = 1 NO = 0"); //prompts user to play or not after the loop runs and the function is called
		scanf_s("%d", &play_again);//reads difficulty level
	}

	puts("Better luck next time"); //if guesses are more than 8 times game stop and prompts user to play again?

	return 0; //this function returns nothing
}

int guessing_game(int number) {//function header
	//init variables
	int user_guess;
	int random_num = 1 + rand() % number; //gets a random value between 1 and the max range of number
	//(10,100 or 1000 / based on user difficulty)

	printf("%s", "I have my number. What's your guess? ");//gets user guess
	scanf_s("%d", &user_guess);//reads user guess

	for (int i = 1; i <= 7; i++) { //loop / counter to record number of user guesses
		if (user_guess < random_num) {//if user number is lower than computers
			printf("%s", "Too low. Guess again: ");//gets new guess
			scanf_s("%d", &user_guess);//reads new user guess
		}
		else if (user_guess > random_num) { //if user number is higher than computers
			printf("%s", "Too high. Guess again: ");
			scanf_s("%d", &user_guess);
		}
		else {
			printf("You got it in %d guess!\n", i); //if user number and computers random number match,
			//prints statement and number of times it took the user to guess correctly
			return; //this function returns the print statement and number of times the user guessed
		}//if the guess matches the computers random number 
	}

	puts("Better luck next time"); //if guesses are more than 8 times game stop and prompts user to play again?
}
*/