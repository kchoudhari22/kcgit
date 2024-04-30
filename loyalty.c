//COP3502 - Programming Assignment 5
//04-14-2024
//Katelyn Choudhari
//ka609383@ucf.edu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 19 //Maximum length for customer names

//Struct holding each customer's name and loyalty points
typedef struct customer {
  char name[MAXLEN + 1];
  int points;
} customer;

//Struct for BST nodes, containing a customer pointer, the size of the
//subtree rooted at this node and pointers to left and right child nodes
typedef struct treenode {
  customer *cPtr;
  int size;
  struct treenode *left;
  struct treenode *right;
} treenode;

treenode *createNode(char *name, int points);
void updateSize(treenode *node);
treenode *findMaxNode(treenode *node);
treenode *deleteNode(treenode *root, char *name);
int searchNode(treenode *root, char *name, int *points, int depth);
int countSmaller(treenode *root, char *name);
void addCustomerToArray(treenode *node, customer **arr, int *index);
treenode *subtractPoints(treenode *node, char *name, int points);
treenode *adjustPoints(treenode *node, char *name, int points, int add);
int compareCustomers(const void *a, const void *b);
int compareByName(const void *a, const void *b);
void processCommands();
void merge(customer **arr, int l, int m, int r);
void mergeSort(customer **arr, int l, int r);
void freeTree(treenode *node);

//Allocates memory for a new tree node/customer and initializing them with provided values
treenode *createNode(char *name, int points) {
  treenode *newNode = (treenode *)malloc(sizeof(treenode));
  customer *newCustomer = (customer *)malloc(sizeof(customer));
  strcpy(newCustomer->name, name);
  newCustomer->points = points;
  newNode->cPtr = newCustomer;
  newNode->size = 1;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

//Recursively updates the size of each node
void updateSize(treenode *node) {
  if (node == NULL)
    return;
  node->size = 1;
  if (node->left != NULL)
    node->size += node->left->size;
  if (node->right != NULL)
    node->size += node->right->size;
}

//Finds the node with the maximum value in the tree
treenode *findMaxNode(treenode *node) {
  treenode *current = node;
  while (current && current->right != NULL)
    current = current->right;
  return current;
}

//Deletes a node based on the customer name
treenode *deleteNode(treenode *root, char *name) {
  if (root == NULL)
    return root;

  int cmp = strcmp(name, root->cPtr->name);
  if (cmp < 0) {
    root->left = deleteNode(root->left, name);
  } else if (cmp > 0) {
    root->right = deleteNode(root->right, name);
  } else {
    //Node with only one child or no child
    if (root->left == NULL || root->right == NULL) {
      treenode *temp = root->left ? root->left : root->right;
      if (temp == NULL) { //No child case
        temp = root;
        root = NULL;
      } else {
        *root = *temp;
      }
      free(temp);
    } else {
      //Node with two children
      treenode *temp = findMaxNode(root->left);

      //Swap values
      customer *tempCust = temp->cPtr;
      temp->cPtr = root->cPtr;
      root->cPtr = tempCust;

      //Delete the inorder predecessor
      root->left = deleteNode(root->left, temp->cPtr->name);
    }
  }
  if (root != NULL)
    updateSize(root);
  return root;
}

//Searches for a customer in the tree by name, returning their points and the spot at which they're found
int searchNode(treenode *root, char *name, int *points, int depth) {
  if (root == NULL)
    return -1;

  int cmp = strcmp(name, root->cPtr->name);
  if (cmp < 0)
    return searchNode(root->left, name, points, depth + 1);
  if (cmp > 0)
    return searchNode(root->right, name, points, depth + 1);

  *points = root->cPtr->points;
  return depth;
}

//Counts the number of customers with names alphabetically before a given name
int countSmaller(treenode *root, char *name) {
  if (root == NULL)
    return 0;

  int cmp = strcmp(name, root->cPtr->name);
  if (cmp <= 0)
    return countSmaller(root->left, name);

  int leftSize = (root->left != NULL) ? root->left->size : 0;
  return 1 + leftSize + countSmaller(root->right, name);
}

//In-order traversal of the tree to add all customers to an array for sorting
void addCustomerToArray(treenode *node, customer **arr, int *index) {
  if (node == NULL)
    return;
  addCustomerToArray(node->left, arr, index);
  arr[(*index)++] = node->cPtr;
  addCustomerToArray(node->right, arr, index);
}

//Decreases the loyalty points of a specified customer, ensuring points do not go below zero
treenode *subtractPoints(treenode *node, char *name, int points) {
  if (node == NULL) {
    printf("%s not found\n", name);
    return NULL;
  }

  int cmp = strcmp(name, node->cPtr->name);
  if (cmp < 0) {
    node->left = subtractPoints(node->left, name, points);
  } else if (cmp > 0) {
    node->right = subtractPoints(node->right, name, points);
  } else {
    node->cPtr->points =
        (node->cPtr->points > points) ? (node->cPtr->points - points) : 0;
    printf("%s %d\n", node->cPtr->name, node->cPtr->points);
  }
  return node;
}

//Adds or subtracts points from a customer's total
//If the customer doesn't exist when adding points they are added to the tree
treenode *adjustPoints(treenode *node, char *name, int points, int add) {
  if (node == NULL) {
    if (add) {
      node = createNode(name, points);
      printf("%s %d\n", name, points);
    } else {
      printf("%s not found\n", name);
    }
    return node;
  }

  int cmp = strcmp(name, node->cPtr->name);
  if (cmp < 0) {
    node->left = adjustPoints(node->left, name, points, add);
  } else if (cmp > 0) {
    node->right = adjustPoints(node->right, name, points, add);
  } else {
    if (add) {
      node->cPtr->points += points;
    } else {
      if (points > node->cPtr->points) { //Ensure points don't go below 0
        node->cPtr->points = 0;
      } else {
        node->cPtr->points -= points;
      }
    }
    printf("%s %d\n", node->cPtr->name, node->cPtr->points);
  }
  updateSize(node);
  return node;
}

//Comparison function for sorting customers first by descending points and then alphabetically by name
int compareCustomers(const void *a, const void *b) {
  customer *custA = *(customer **)a;
  customer *custB = *(customer **)b;
  if (custA->points == custB->points)
    return strcmp(custA->name, custB->name);
  return custB->points - custA->points; //Descending order of points
}

//Compares two customers by name alphabetically
int compareByName(const void *a, const void *b) {
  const customer *custA = *(const customer **)a;
  const customer *custB = *(const customer **)b;
  return strcmp(custA->name, custB->name);
}

//Reads and processes commands
//Handles adding, subtracting, deleting customers, searching for customers and counting customers
//After processing, it prints customers sorted by points and name
void processCommands(treenode **root) {
  int n, index = 0;
  scanf("%d", &n);

  customer *customersArray[n];
  char command[10], name[MAXLEN + 1];
  int points;

  for (int i = 0; i < n; i++) {
    scanf("%s", command);
    if (strcmp(command, "add") == 0) {
      scanf("%s %d", name, &points);
      *root = adjustPoints(*root, name, points, 1);
    } else if (strcmp(command, "sub") == 0) {
      scanf("%s %d", name, &points);
      *root = subtractPoints(*root, name, points);
    } else if (strcmp(command, "del") == 0) {
      scanf("%s", name);
      *root = deleteNode(*root, name);
      printf("%s deleted\n", name);
    } else if (strcmp(command, "search") == 0) {
      scanf("%s", name);
      int foundPoints = 0;
      int depth = searchNode(*root, name, &foundPoints, 0);
      if (depth != -1) {
        printf("%s %d %d\n", name, foundPoints, depth);
      } else {
        printf("%s not found\n", name);
      }
    } else if (strcmp(command, "count_smaller") == 0) {
      scanf("%s", name);
      printf("%d\n", countSmaller(*root, name));
    }
  }

  addCustomerToArray(*root, customersArray, &index);
  mergeSort(customersArray, 0, index - 1);

  for (int i = 0; i < index; i++) {
    printf("%s %d\n", customersArray[i]->name, customersArray[i]->points);
  }
}

//Merges two subarrays of arr[].
//First subarray is arr[l..m]
//Second subarray is arr[m+1..r]
void merge(customer **arr, int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  //Create temp arrays
  customer *L[n1], *R[n2];

  //Copy data to temp arrays L[] and R[]
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  //Merge the temp arrays back into arr[l..r]
  i = 0; //Initial index of first subarray
  j = 0; //Initial index of second subarray
  k = l; //Initial index of merged subarray
  while (i < n1 && j < n2) {
    if (L[i]->points > R[j]->points ||
        (L[i]->points == R[j]->points && strcmp(L[i]->name, R[j]->name) < 0)) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  //Copy the remaining elements of L[], if there are any
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  //Copy the remaining elements of R[], if there are any
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

//l is for left index and r is right index of the
//sub-array of arr to be sorted
void mergeSort(customer **arr, int l, int r) {
  if (l < r) {
    //Same as (l+r)/2, but avoids overflow for large l and h
    int m = l + (r - l) / 2;

    //Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

//Free all allocated memory
void freeTree(treenode *node) {
  if (node == NULL)
    return;
  freeTree(node->left);
  freeTree(node->right);
  free(node->cPtr); //Free the customer
  free(node);       //Free the node
}

int main() {
  treenode *root = NULL;
  processCommands(&root);
  freeTree(root);
  return 0;
}