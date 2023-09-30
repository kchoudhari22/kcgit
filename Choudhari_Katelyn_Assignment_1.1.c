/*
COP3223 Summer 2023 Assignment 1.1
Copyright 2023 Choudhari Katelyn
*/

//A program that will determine the gross pay for each of several employees.
//The company pays “straight time” for the first 40 hours worked by each employee
//and pays “time-and-a-half” for all hours worked in excess of 40 hours.
//The program uses scanf to input hours and pay rate for each employee
//and determine and displays the employee’s gross pay.
/*
#include <stdio.h>

//init variables
int main(void) {
	float hours;
	float overtime_hours;
	float pay_rate;
	float overtime_rate;
	float gross_pay;

	//init loop while true
	while (1) {
		//get and read user input for hours
		printf("%s", "Enter # of hours worked (-1 to end) : ");
		scanf_s("%f", &hours);

		//calculate gross pay (hours x pay)
		//if pay is over 40 hours calculate additional hours 1.5x
		if (hours < 0) {
			break;
			//printf("%s", "Salary cannot be calculated with negative hours.");
		}

		//straight time
		if (hours >= 0 && hours <= 40) {
			printf("%s", "Enter hourly rate of the worker ($00.00) : ");
			scanf_s("%f", &pay_rate);
			gross_pay = hours * pay_rate;
			printf("Salary is $%.2f\n", gross_pay);
		}

		//time and a half
		if (hours > 40) {
			printf("%s", "Enter hourly rate of the worker ($00.00) : ");
			scanf_s("%f", &pay_rate);
			overtime_hours = hours - 40;
			overtime_rate = (pay_rate * 1.5);
			gross_pay = (pay_rate * 40) + (overtime_hours * overtime_rate);
			printf("Salary is $%.2f\n", gross_pay);
		}
	}


}
*/