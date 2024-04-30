// COP3502 - Programming Assignment 7
// Katelyn Choudhari
// ka609383@ucf.edu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 19
#define TABLESIZE 300007

// Defines what an item is, including name, how many in stock, and how much it
// costs
typedef struct item {
  char name[MAXLEN + 1]; // Item name
  int quantity;          // Item quantity
  int saleprice;         // Item price
} item;

// A node in the linked list, containing an item and a pointer to the next node
typedef struct node {
  item *iPtr;        // Pointer to the actual item
  struct node *next; // Pointer to the next node in the list
} node;

// The hash table structure, which contains a bunch of linked lists
typedef struct hashtable {
  node **lists; // Array of pointers to the first node of each linked list
  int size;     // How many slots in the table
} hashtable;

// Calculates a hash index from a string, used to decide where in the table to put the item
int hashfunc(char *word, int size) {
  int len = strlen(word);
  int res = 0;
  for (int i = 0; i < len; i++) {
    res = (1151 * res + (word[i] - 'a')) %
          size; // 'a' adjusts char value to start from 0
  }
  return res;
}

// Creates a hash table with a given number of slots, all initialized to NULL
hashtable *createHashTable(int size) {
  hashtable *h = (hashtable *)malloc(sizeof(hashtable));
  h->size = size;
  h->lists = (node **)calloc(size, sizeof(node *));
  return h;
}

// Adds an item to the hash table based on its hash value
void insertItem(hashtable *h, item *itm) {
  int index = hashfunc(itm->name, h->size); // Find out where to put the item
  node *newNode = (node *)malloc(sizeof(node)); // Create a new node
  newNode->iPtr = itm;                          // Set item pointer
  newNode->next = h->lists[index]; // New node points to the current first node
  h->lists[index] = newNode;       // New node is the first in the list
}

// Searches for an item by name in the hash table, updating complexity based on search depth
item *findItem(hashtable *h, char *name, int *complexity) {
  int index = hashfunc(name, h->size);
  node *current = h->lists[index];
  int position = 1;
  while (current) {
    if (strcmp(current->iPtr->name, name) == 0) {
      *complexity +=
          position; // Complexity increases by how many times it took to find
      return current->iPtr;
    }
    current = current->next;
    position++;
  }
  *complexity += position; // Add complexity if item not found
  return NULL;
}

// Cleans up all the memory used by the hash table to avoid memory leaks
void freeHashTable(hashtable *h) {
  for (int i = 0; i < h->size; i++) {
    node *current = h->lists[i];
    while (current) {
      node *temp = current;
      current = current->next;
      free(temp->iPtr); // Free the item
      free(temp);       // Free the node
    }
  }
  free(h->lists); // Free the array of pointers
}

int main() {
  int n, totalCash = 100000,
         totalComplexity = 0; // Start with some initial cash
  scanf("%d\n", &n);          // Read the number of operations

  hashtable *h = createHashTable(TABLESIZE); // Create the hash table
  char line[1024]; // Buffer to hold each line of input

  for (int i = 0; i < n; i++) {
    fgets(line, sizeof(line), stdin); // Read each command
    char command[20], itemName[MAXLEN + 1];
    int quantity, price;

    sscanf(line, "%s %s %d %d", command, itemName, &quantity,
           &price); // Parse the command

    int localComplexity = 0;
    item *itm;

    // Determine what to do based on the command type
    if (strcmp(command, "buy") == 0) {
      itm = findItem(h, itemName, &localComplexity);
      if (!itm) {
        itm = (item *)malloc(sizeof(item));
        strcpy(itm->name, itemName);
        itm->quantity = quantity;
        itm->saleprice = -1; // Start with undefined sale price
        insertItem(h, itm);
      } else {
        itm->quantity += quantity;
      }
      totalCash -= price; // Reduce cash by the price paid
      printf("\n%s %d %d", itemName, itm->quantity, totalCash);
    } else if (strcmp(command, "sell") == 0) {
      itm = findItem(h, itemName, &localComplexity);
      if (itm->quantity < quantity) {
        quantity = itm->quantity; // Sell only what's available
      }
      itm->quantity -= quantity;
      totalCash +=
          quantity * itm->saleprice; // Increase cash by the sale revenue
      printf("\n%s %d %d", itemName, itm->quantity, totalCash);
    } else if (strcmp(command, "change_price") == 0) {
      sscanf(line, "%s %s %d", command, itemName, &price);
      itm = findItem(h, itemName, &localComplexity);
      itm->saleprice = price; // Update the sale price
    }
    totalComplexity += localComplexity; // Update the total complexity
  }

  printf("\n%d\n%d", totalCash,
         totalComplexity); // Output final cash and complexity
  freeHashTable(h);        // Clean up the hash table
  return 0;
}