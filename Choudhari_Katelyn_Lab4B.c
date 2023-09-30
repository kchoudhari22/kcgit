/*
COP3223 Summer 2023 Lab4B
Copyright 2023 Choudhari Katelyn
*/

//A program that calculates the distance between
//two points (x1, y1) and (x2, y2) using a
//function called distance.

//#include <stdio.h>
//#include <math.h>
//
//double distance(double x1, double y1, double x2, double y2); // fnct protype
//
//int main(void) {
//	//init variables
//	double x1 = 0;
//	double y1 = 0;
//	double x2 = 0;
//	double y2 = 0;
//
//	printf("%s", "Enter the first x and y values separated by a space: "); //get user input
//	scanf_s("%lf %lf", &x1, &y1); //read user input
//
//	printf("%s", "Enter the second x and y values separated by a space: ");
//	scanf_s("%lf %lf", &x2, &y2);
//
//	double result = distance(x1, y1, x2, y2); //calls fnct distance with parameters read from user
//
//	printf("%.2lf", result); //result will be rounded to 2 decimal points
//
//	return 0;
//
//}
//
//double distance (double x1, double y1, double x2, double y2) { //fnct header
//	
//	double result = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); //calculates distance
//	return result; //returns result of above calculation
//}