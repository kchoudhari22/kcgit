// COP3502 - Programming Assignment 6
// Katelyn Choudhari
// ka609383@ucf.edu

//Given the locations and number of people in the groups, find the least number of people that are
//required to be in some sector defined by a center and an angle. Additionally, determine the largest
//angle that can be used such that no one is in the projection.

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//Define PI for conversion between radians and degrees
#define PI 3.14159265358979323846

//Define a structure to hold the angle (in radians) and number of people for each group.
typedef struct {
  double angle;
  int people;
} Group;

//Comparison function for sorting groups by their angle.
int compare(const void *a, const void *b) {
  Group *groupA = (Group *)a;
  Group *groupB = (Group *)b;
  if (groupA->angle < groupB->angle)
    return -1;
  else if (groupA->angle > groupB->angle)
    return 1;
  return 0;
}

int main() {
  //Number of groups, angle of projection.
  int number, angle;
  scanf("%d %d", &number, &angle);
  //Convert angle from degrees to radians
  double A_rad = angle * PI / 180.0;

  //Allocate memory for an array of Group structures, twice the size of N to account for wrap-around.
  Group *groups = (Group *)malloc(sizeof(Group) * number * 2);
  if (!groups) {
    printf("Failed.\n");
    return 1;
  }

  //Populate the groups array with angle and people count for each group
  for (int i = 0; i < number; i++) {
    int x, y, s;
    scanf("%d %d %d", &x, &y, &s);
    //Calculate the angle of the group from the origin
    double angle = atan2(y, x);
    if (angle < 0)
    //Normalize the angle to be within [0, 2PI]
    angle += 2 * PI;
    //Store group information
    groups[i] = (Group){angle, s};
    //Duplicate group information for wrap-around
    groups[i + number] = (Group){angle + 2 * PI, s};
  }

  //Sort the groups by angle
  qsort(groups, number * 2, sizeof(Group), compare);

  //Find the minimum number of people within the specified angle range
  int result = INT_MAX;
  for (int i = 0; i < number; i++) {
    //Check for both edges of the group's angle
    for (int k = 0; k <= 1; k++) {
      double startAngle = groups[i].angle + k * A_rad - (A_rad / 2);
      //Count people within the angle range
      int currentPeople = 0;
      for (int j = 0; j < 2 * number; j++) {
        if (groups[j].angle >= startAngle &&
            groups[j].angle <= startAngle + A_rad) {
          currentPeople += groups[j].people;
        }
      }
      //Update result if a smaller count is found
      if (currentPeople < result) {
        result = currentPeople;
      }
    }
  }

  //Calculate the maximum projection angle without including any group
  double maxAngle = 0.0;
  //Find the largest angle angularDistance
  for (int i = 0; i < number; i++) {
    //Calculate the angularDistance between consecutive groups.
    double angularDistance = groups[i + 1].angle - groups[i].angle;
    //Special case for the angularDistance between the last and first group
    if (i == number - 1) {
      angularDistance = 2 * PI - groups[i].angle + groups[0].angle;
    }
    //Update maxAngle if a larger angularDistance is found
    if (angularDistance > maxAngle) {
      maxAngle = angularDistance;
    }
  }

  //Print the minimum number of people and the maximum projection angle without including any group
  printf("%d\n", result);
  //Convert the angle back to degrees
  printf("%.4f\n", maxAngle * (180.0 / PI));

  //Free the dynamically allocated memory
  free(groups);
  return 0;
}