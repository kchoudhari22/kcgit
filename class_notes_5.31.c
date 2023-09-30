//counter controlled iteration
//the name of a control variable
//the initial value
// the loop-continuation condition

/*
#include <stdio.h>
#include <math.h>

int main() {
	
		int counter = 1;
		while (counter <= 5) {
			printf("%d", counter);
			counter++;
		}

		//for (initialization; loop-continuation-dondition, increment)
		for (int counter = 1; counter <= 5; counter++) { //for loop
			printf("%d", counter);
			//do not change the value of the counter inside of a for block of code because the counter is in the ()
			//counter++; <-- do not do this in a for loop
		}
		//control variable defined in a for loop only exist until the loop terminates
		//printf("%d", counter);


	//add all the odd numbers from 0 - 100 using a for loop
		int sum = 0;
		for (int x = 1; x <= 100; x+=2) {
			sum += x;
			printf("%d \n", x);
			}
			printf("%d \n", sum);
	
	//calculating the compund interest
	//investment = $1000, interest rate 5% (0.05), desposit for 10 years
	//a = base * (1 + interest) ^ year

	//year     money
	//1        1000.00
	//2        1005.00

	//pow(1 + interest, year)
	double principle = 1000.00;
	double rate = 0.05;
	double amount = 0;
	int year = 10;

	printf("%5s%20s\n", "year", "amount on deposit"); //5 and 20 is a field width, means how many characters

	for (int y = 0; y < year; y++) {

		//calculate the interest
		amount = principle * pow((1 + rate), y);

		printf("%5d%20.2f\n", y, amount);
	}

//if today is monday, have pizza
//else if today is tuesday, have fried chicken
//switch: for more than 2 conditions
//case monday: pizza
//case tuesday: fried chicken
//case wednesday: ice cream

//input the students gradse A,B,C,D,F, count the number of each grade
	char grade = 0;
	printf("%s", "Enter the grade: ");
	scanf_s("%c", &grade);
	//
	//instead of using scanf_s you can use
	//grade = getchar();
	//but this will only return the first character
	//printf("char is %c", grade)
	//putchar(grade);
	//
	//to get multiple characters from a string use a while or for loop
	//for(int i = 0; i < 4, i++){
	//    grade = getchar()
	//    putchar(grade);
	//}

	int aCount = 0;
	int bCount = 0;
	int cCount = 0;
	int dCount = 0;
	int fCount = 0;

	switch(grade) {
		case 'A':
			aCount++;
			printf("%s", "You get an A");
			break;
		case 'B':
			bCount++;
			printf("%s", "You get an B");
			break;
		case 'C':
			cCount++;
			printf("%s", "You get an C");
			break;
		case 'D':
			dCount++;
			printf("%s", "You get an D");
			break;
		case 'F':
			fCount++;
			printf("%s", "You get an F");
			break;
	}

}
*/