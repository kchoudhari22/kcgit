// COP3502 - Programming Assignment 4
// Katelyn Choudhari
// ka609383@ucf.edu

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 500000
#define MAX_QUEUES 12

typedef struct {
  char name[51];
  int lineNumber;
  int tickets;
  int time;
} Customer;

typedef struct node_t {
  Customer *customer;
  struct node_t *next;
} node_t;

typedef struct {
  node_t *front;
  node_t *back;
  int size;
} Queue;

Queue *processingQueue;
Queue *boothQueues[MAX_QUEUES];
Queue *createQueue();
void enqueue(Queue *queue, Customer *customer);
Customer *dequeue(Queue *queue);
int empty(Queue *queue);
void processCustomers(int n, int b);
int getQueueNumber(char *name, int numOfQueues);
void assignToQueue(Customer *customer, int numOfQueues);
Customer *createCustomer(char *name, int lineNumber, int tickets, int time);
void printBoothAssignments(int b);
void printList(Queue *head);
int queueCounts[MAX_QUEUES];

int main(void) {
  int n, b;
  scanf("%d %d", &n, &b);

  for (int i = 0; i < MAX_QUEUES; i++) {
    boothQueues[i] = createQueue();
  }

  processingQueue = createQueue();

  for (int i = 0; i < n; i++) {
    char name[51];
    int tickets, time;
    scanf("%s %d %d", name, &tickets, &time);
    int queueNum = getQueueNumber(name, b);
    Customer *customer = createCustomer(name, queueNum, tickets, time);
    queueCounts[queueNum - 1]++;
    enqueue(processingQueue, customer);
  }

  processCustomers(n, b);
  printBoothAssignments(b);

  return 0;
}

Queue *createQueue(void) {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  if (queue == NULL) {
    printf("Memory allocation failed for queue.\n");
    exit(1);
  }
  queue->front = NULL;
  queue->back = NULL;
  queue->size = 0;
  return queue;
}

void enqueue(Queue *queue, Customer *customer) {
  node_t *newNode = (node_t *)malloc(sizeof(node_t));
  if (newNode == NULL) {
    printf("Memory allocation failed for node.\n");
    exit(1);
  }
  newNode->customer = customer;
  newNode->next = NULL;
  if (queue->back == NULL) {
    queue->front = queue->back = newNode;
  } else {
    queue->back->next = newNode;
    queue->back = newNode;
  }
  queue->size++;
}

Customer *dequeue(Queue *queue) {
  if (queue->front == NULL)
    return NULL;
  node_t *temp = queue->front;
  Customer *customer = temp->customer;
  queue->front = queue->front->next;
  if (queue->front == NULL)
    queue->back = NULL;
  free(temp);
  queue->size--;
  return customer;
}

int empty(Queue *queue) { return queue->front == NULL; }

Customer *createCustomer(char *name, int lineNumber, int tickets, int time) {
  Customer *newCustomer = (Customer *)malloc(sizeof(Customer));
  if (newCustomer == NULL) {
    printf("Memory allocation failed for customer.\n");
    exit(1);
  }
  strcpy(newCustomer->name, name);
  newCustomer->lineNumber = lineNumber;
  newCustomer->tickets = tickets;
  newCustomer->time = time;
  return newCustomer;
}

// Function to get queue number based on the first character of the name
int getQueueNumber(char *name, int numOfQueues) {
  int queueNumber = name[0] % 13;
  if (queueNumber == 0) {
    int current = 0;
    for (int i = 0; i < MAX_QUEUES; i++) {
      if (queueCounts[i] > 0) {
        if (queueCounts[i] < queueCounts[current] ||
            queueCounts[current] == 0) {
          current = i;
        }
      }
    }
    queueNumber = current + 1;
  }
  return queueNumber;
}

// Process customers: creating and assigning to queues
void processCustomers(int n, int b) {
  // Find non-empty queues
  int nonEmptyQueues[MAX_QUEUES] = {0};
  int numNonEmptyQueues = 0;
  for (int i = 0; i < MAX_QUEUES; i++) {
    if (queueCounts[i] > 0) {
      nonEmptyQueues[numNonEmptyQueues] = i;
      numNonEmptyQueues++;
    }
  }

  // Determine number of queues per booth and number of booths with extra queue
  int queuesPerBooth = numNonEmptyQueues / b;
  int extraQueues = numNonEmptyQueues % b;

  // Assign queues to booths
  int assignedQueues[MAX_QUEUES][MAX_QUEUES] = {0};
  int boothIndex = 0;
  int queueIndex = 0;
  for (int i = 0; i < numNonEmptyQueues; i++) {
    assignedQueues[boothIndex][queueIndex++] = nonEmptyQueues[i];
    if (queueIndex == queuesPerBooth + (boothIndex < extraQueues ? 1 : 0)) {
      boothIndex++;
      queueIndex = 0;
    }
  }

  // Process customers for each booth
  while (processingQueue->size > 0) {
    Customer *customer = dequeue(processingQueue);
    for (int booth = 0; booth < MAX_QUEUES; booth++) {
      for (int i = 0; i < MAX_QUEUES; i++) {
        if (assignedQueues[booth][i] == customer->lineNumber - 1) {
          enqueue(boothQueues[booth], customer);
          break;
        }
      }
    }
  }
}

// Print booth assignments
void printBoothAssignments(int b) {
  for (int i = 0; i < b; i++) {
    printf("Booth %d\n", i + 1);
    int currentTime = 0;
    while (!empty(boothQueues[i])) {
      Customer *customer = dequeue(boothQueues[i]);
      int processingTime = 30 + customer->tickets * 5;
      if (customer->time > currentTime) {
        currentTime = customer->time;
      }
      currentTime += processingTime;
      printf("%s from line %d checks out at time %d.\n", customer->name,
             customer->lineNumber, currentTime);
      free(customer);
    }
    printf("\n");
  }
}