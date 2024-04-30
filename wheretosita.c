//COP3502 - Programming Assignment 3
//Katelyn Choudhari
//ka609383@ucf.edu

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PEOPLE 10
#define NAME_LEN 20
#define MAX_PAIRS 45   // Maximum number of pairs for 10 people
#define INPUT_LEN 1000 // Assuming a maximum input length

int n, p; // n is the number of people, p is the number of pairs who can't sit
          // together
char names[MAX_PEOPLE][NAME_LEN];
bool has_popcorn[MAX_PEOPLE];
int total_valid_arrangements = 0;

struct Pair {
  char name1[NAME_LEN];
  char name2[NAME_LEN];
} restricted_pairs[MAX_PAIRS];

void swap(int i, int j) {
  char temp_name[NAME_LEN];
  bool temp_popcorn;

  strcpy(temp_name, names[i]);
  temp_popcorn = has_popcorn[i];

  strcpy(names[i], names[j]);
  has_popcorn[i] = has_popcorn[j];

  strcpy(names[j], temp_name);
  has_popcorn[j] = temp_popcorn;
}

bool isRestricted(char *name1, char *name2) {
  for (int i = 0; i < p; i++) {
    if ((strcmp(name1, restricted_pairs[i].name1) == 0 &&
         strcmp(name2, restricted_pairs[i].name2) == 0) ||
        (strcmp(name2, restricted_pairs[i].name1) == 0 &&
         strcmp(name1, restricted_pairs[i].name2) == 0)) {
      return true;
    }
  }
  return false;
}

bool isValidArrangement() {
  for (int i = 0; i < n - 1; i++) {
    if (isRestricted(names[i], names[i + 1]) ||
        (!has_popcorn[i] && !has_popcorn[i + 1] &&
         (i == 0 || !has_popcorn[i - 1])))
      return false;
  }
  if (!has_popcorn[n - 1] && n > 1 && !has_popcorn[n - 2])
    return false;
  return true;
}

void permute(int l, int r) {
  if (l == r) {
    if (isValidArrangement())
      total_valid_arrangements++;
    return;
  }
  for (int i = l; i <= r; i++) {
    swap(l, i);
    permute(l + 1, r);
    swap(l, i); // backtrack
  }
}

int main() {
  char input[INPUT_LEN];
  printf("Enter the number of people and the number of pairs that can't sit "
         "next to each other, the names of the persons and 0/1 for whether "
         "they have popcorn or not, separated by a space, and then the pairs "
         "who cannot sit next to one another: \n");
  fgets(input, INPUT_LEN, stdin); // Read the first line for n and p
  sscanf(input, "%d %d", &n, &p);

  for (int i = 0; i < n; i++) {
    int temp;
    fgets(input, INPUT_LEN, stdin); // Read each person's details
    sscanf(input, "%s %d", names[i], &temp);
    has_popcorn[i] = temp;
  }

  for (int i = 0; i < p; i++) {
    fgets(input, INPUT_LEN, stdin); // Read each restricted pair
    sscanf(input, "%s %s", restricted_pairs[i].name1,
           restricted_pairs[i].name2);
  }

  permute(0, n - 1);
  printf("Total valid arrangements: %d\n", total_valid_arrangements);
  return 0;
}