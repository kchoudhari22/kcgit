/* Dr. Steinberg
   COP3502 Computer Science
   FIFO Queue Implementation using Linked List
*/

#include<stdio.h>
#include<stdlib.h>
#include <limits.h> //minimum integer

typedef struct node_s{
	
	int data;
	struct node_s * nextptr;
	
}node_t;

typedef struct{
	
	node_t * front;
	node_t * rear;
	
}queue_t;

//function prototypes
void enqueue(queue_t * line, int data);
int dequeue(queue_t * line);
int front(queue_t * line);
int empty(queue_t * line);
queue_t * createQueue(void);
void destroyQueue(queue_t * line);
void displayQueue(queue_t * line);

int main()
{
	queue_t * myqueue = createQueue();
	int flag = 1;
	int choice = 0;
	int data;
	printf("Welcome to the Queue Manager.\n");
	
	do{
		
		printf("Here are the options:\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Retrieve the next customer in line.\n");
		printf("4. Display the queue\n");
		printf("5. Exit the program\n");
		printf("Choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			
			case 1:
				printf("Enqueue selected.\n");
				printf("Enter a numerical value you would like to enter: ");
				scanf("%d", &data);
				enqueue(myqueue, data);
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
				printf("Retrieving next customer in line.\n");
				
				if(!empty(myqueue))
				{
					data = front(myqueue);
					printf("The item that is currently next in line is %d\n", data);
				}
				else
				{
					printf("The queue is currently empty.\n");
				}
				break;
			
			case 4:
				printf("Displaying the line.\n");
				
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

queue_t * createQueue(void)
{
	queue_t * line = malloc(sizeof(queue_t));
	line->front = NULL;
	line->rear = NULL;
	return line;
}

void enqueue(queue_t * line, int data)
{
	if(empty(line))
	{
		printf("The queue is empty...\n");
		line->front = malloc(sizeof(node_t));
		line->front->data = data;
		line->front->nextptr = line->front;
		line->rear = line->front;
	}
	else
	{
		node_t * temp = malloc(sizeof(node_t));
		temp->data = data;
		temp->nextptr = line->front;
		line->rear->nextptr = temp;
		line->rear = temp;	
	}
	
	printf("New entry has entered the queue...\n");
}

int dequeue(queue_t * line)
{
	if(!empty(line))
	{
		int data = line->front->data;
		
		if(line->front != line->rear)
		{		
			node_t * temp = line->front;
			
			line->front = line->front->nextptr;
			
			line->rear->nextptr = line->front;
			
			free(temp);
		}
		else
		{
			free(line->front);
			line->front = NULL;
			line->rear = NULL;
		}
		
		return data;
	}
	else
	{
		printf("Nothing to dequeue...\n");
		return INT_MIN;
	}
}

int front(queue_t * line)
{
	return line->front->data;
}

int empty(queue_t * line)
{
	if(line->front == NULL)
		return 1;
	else
		return 0;
}

void destroyQueue(queue_t * line)
{
	node_t * temp = line->front;
	
	while(temp != line->rear)
	{
		line->front = line->front->nextptr;
		free(temp);
		temp = line->front;
	}
	
	free(temp);
	free(line);
}

void displayQueue(queue_t * line)
{
	node_t * temp = line->front;
	
	while(temp != line->rear)
	{
		printf("%d--->", temp->data);
		temp = temp->nextptr;
	}
	
	printf("%d\n", temp->data);
}