/*
 * week4_3_struct_database.c
 * Author: Sebastjans Peive
 * Student ID: 241ADC003
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  int n;
  struct Student *students = NULL;

  printf("Enter number of students: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid number.\n");
    return 1;
  }

  students = malloc(n * sizeof(struct Student));
  if (students == NULL) {
    printf("Error: memory allocation failed.");
  } else {
    double avg = 0;
    double topG = 0;
    int topI = 0;
    for (int i = 0; i < n; i++) {
      printf("Enter name of the student: ");
      scanf("%s", &students[i].name);
      students[i].id = i + 1;
      printf("Enter grade of the student: ");
      scanf("%f", &students[i].grade);
      avg += students[i].grade;
      if (students[i].grade > topG) {
        topG = students[i].grade;
        topI = i;
      }
    }
    for (int i = 0; i < n; i++) {
      printf("Student id: %1d\nStudent name: %2s\nStudent grade: %3.1f\n\n",
             students[i].id, students[i].name, students[i].grade);
    }
    avg /= n;
    printf("Average grade of students: %.2f\n\n", avg);
    printf(
        "Top student info:\nStudent id: %1d\nStudent name: %2s\nStudent grade: "
        "%3.1f\n\n",
        students[topI].id, students[topI].name, students[topI].grade);
    free(students);
  }

  return 0;
}
