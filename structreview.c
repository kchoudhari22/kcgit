//Dr. Steinberg
//COP3502C
//Struct Basics
//Structs Review

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LIMIT 30


typedef struct{
	double x;
	int y;
	char z;
}record_t;

//function prototypes
void display1(record_t record);
void display2(record_t * record);
record_t create();

int main()
{
	record_t record = create();
	
	display1(record);
	display2(&record);
	
	return 0;
}

//direct operator
void display1(record_t record)
{
	printf("display1 called...\n");
	printf("record.x = %f\n", record.x);
	printf("record.y = %d\n", record.y);
	printf("record.z = %c\n", record.z);
}


//indirect operator
void display2(record_t * record)
{
	printf("display2 called...\n");
	printf("record->x = %f\n", record->x);
	printf("(*record).x = %f\n", (*record).x);
	printf("record->y = %d\n", record->y);
	printf("record->z = %c\n", record->z);
}


record_t create()
{
	record_t record;
	
	printf("Enter an double: ");
	scanf("%lf", &record.x);
	
	printf("Enter a integer: ");
	scanf("%d", &record.y);
	
	printf("Enter a character: ");
	scanf(" %c", &record.z);
	
	return record;
}