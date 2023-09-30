/*
COP3223 Summer 2023 Assignment 2.1
Copyright 2023 Choudhari Katelyn
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//A number guessing game that has 3 levels of difficulty

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
int random_number_gen(int range);
void guess_number(int difficulty, int range);

int main(void) {
	//init variables
	srand(time(NULL));//gets random number
	int play_again = 1;//init game play to start

	do {//do...while loop will do[action] before while[condition]
		//init variables
		int difficulty;
		int range;

		printf("%s","Let's play Guess the Number\n");
		printf("%s","Pick a difficulty level (1,2,3): ");//gets user difficulty level
		scanf_s("%d", &difficulty);//reads difficulty level

		//based on difficulty level chosen by the user
		//the following switch pass the difficulty
		//and range (10,100,1000) to the function
		//guess_number parameters' and will call the function
		switch (difficulty) {
		case 1:
			range = 10;
			break;
		case 2:
			range = 100;
			break;
		case 3:
			range = 1000;
			break;
		default:
			continue;
		}
		guess_number(difficulty, range);//call function, jump out of loop to guess_number function

		puts("Play again? YES = 1 NO = 0");//once both functions terminate, ask user to play again?
		scanf_s("%d", &play_again);//read user choice
	} while (play_again == 1);//while user continues to select 1/YES, game loops from start on line 30

	return 0;//returns nothing
}

int random_number_gen(int range) {//function header
	return 1 + rand() % range;//gets a random value between 1 and range
	//(10,100 or 1000 / based on user difficulty)
}

void guess_number(int difficulty, int range) {//function header
	//init variables
	int random_num = random_number_gen(range);//redefines random_number_gen function as
	//variable random_num in this function
	int user_guess;
	
	printf("%s","I have my number. What's your guess? ");//gets user guess
	scanf_s("%d", &user_guess);//reads user guess 

	for (int i = 1; i < 8; i++) { //init for loop and set counter to record number of user guesses
		//scanf_s("%d", &user_guess);//reads user guess 

		if (user_guess < random_num) {//if user number is lower than computers
			printf("%s","Too low. Guess again: ");//gets new guess
			scanf_s("%d", &user_guess);//reads user guess 
		}
		else if (user_guess > random_num) { //if user number is higher than computers
			printf("%s","Too high. Guess again: ");
			scanf_s("%d", &user_guess);//reads user guess 
		}
		else {
			printf("You got it in %d guess!\n", i); //if user number and computers random number match,
			//prints statement and number of times it took the user to guess correctly
			return; //this function returns the print statement and number of times the user guessed
		}//if the guess matches the computers random number 
	}

	puts("Better luck next time");//prints when user guesses/counter > 8 

}
*/