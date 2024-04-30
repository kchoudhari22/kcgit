/* Dr. Steinberg
   COP3502 Computer Science
   FIFO Queue Implementation using Array
*/

#include<stdio.h>
#include<stdlib.h>
#include <limits.h> //minimum integer

typedef struct{
	
	int rear;
	int size;
	int * array;
	
}queue_t;

//function prototypes
void enqueue(queue_t * line, int data);
int dequeue(queue_t * line);
int front(queue_t * line);
int empty(queue_t * line);
int full(queue_t * line);
queue_t * createQueue(int size);
void destroyQueue(queue_t * line);
void displayQueue(queue_t * line);

int main()
{
	int size;
	printf("Welcome to the Queue Manager (Array Version).\n");
	printf("Enter the size limit of the queue: ");
	scanf("%d", &size);
	queue_t * myqueue = createQueue(size);
	int flag = 1;
	int choice = 0;
	int data;
	
	
	do{
		
		printf("Here are the options:\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Retreieve the customer in front.\n");
		printf("4. Display the Queue.\n");
		printf("5. Exit the program\n");
		printf("Choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			
			case 1:
			
				printf("Enqueue selected.\n");
				
				if(full(myqueue))
				{
					printf("The Queue is full. Can't add anymore customers.\n");
				}
				else
				{
					printf("Enter a numerical value you would like to enter: ");
					scanf("%d", &data);
					enqueue(myqueue, data);
				}
				
				
				break;
				
			case 2:
				printf("Dequeue selected.\n");
				
				if(!empty(myqueue))
				{
					data = dequeue(myqueue);
					printf("The item that was dequeued was %d\n", data);
				}
				else
				{
					printf("Queue is empty...\n");
					printf("Nothing to dequeue...\n");
				}
				break;
				
			case 3:
				printf("Retrieve the front value selected.\n");
				
				if(!empty(myqueue))
				{
					data = front(myqueue);
					printf("The item that is currently in the front is %d\n", data);
				}
				else
				{
					printf("The Queue is currently empty.\n");
				}
				break;
				
			case 4:
				printf("Displaying the Queue\n");
				
				if(!empty(myqueue))
				{
					displayQueue(myqueue);
				}
				else
					printf("No customers in line.\n");
				
				break;
			case 5:
				printf("Program is now exiting.\n");
				flag = 0;
				break;
				
			default:
				printf("Invalid choice was made.\n");
				choice = 0;
		}
		
		
		
	}while(flag);
	
	destroyQueue(myqueue);
	
	return 0;
}

queue_t * createQueue(int size)
{
	queue_t * line = malloc(sizeof(queue_t));
	line->size = size;
	line->rear = -1;
	line->array = malloc(sizeof(int) * line->size);
	return line;
}

void enqueue(queue_t * line, int data)
{
	line->array[++line->rear] = data;
	printf("New customer has entered the line...\n");

}

int dequeue(queue_t * line)
{
	int data = line->array[0];
	
	for(int index = 0; index < line->rear; ++index)
		line->array[index] = line->array[index + 1];
	
	--line->rear;
	
	return data;
}

int front(queue_t * line)
{
	if(empty(line))
		return INT_MIN;
	
	return line->array[0];
}

int empty(queue_t * line)
{
	if(line->rear == -1)
		return 1;
	else
		return 0;
}

int full(queue_t * line)
{
	if(line->rear == line->size - 1)
		return 1;
	else
		return 0;
}

void destroyQueue(queue_t * line)
{
	free(line);
}

void displayQueue(queue_t * line)
{
	for(int x = 0; x <= line->rear; ++x)
	{
		if(x != line->rear)
			printf("%d-->", line->array[x]);
		else
			printf("%d\n", line->array[x]);
	}
}