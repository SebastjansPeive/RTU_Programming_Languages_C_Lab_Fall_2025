/*
 * week4_2_struct_student.c
 * Author: Sebastjans Peive
 * Student ID: 241ADC003
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Students should define a 'Student' struct with fields like name, id, and
 * grade. Then create a few instances and print them.
 */

#include <stdio.h>
#include <string.h>

struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  struct Student student1;
  strcpy(student1.name, "Joe");
  student1.id = 1;
  student1.grade = 8.2;

  struct Student student2;
  strcpy(student2.name, "Bob");
  student2.id = 2;
  student2.grade = 7.7;

  printf("Student id: %1d\nStudent name: %2s\nStudent grade: %3.1f\n\n",
         student1.id, student1.name, student1.grade);
  printf("Student id: %1d\nStudent name: %2s\nStudent grade: %3.1f\n",
         student2.id, student2.name, student2.grade);

  return 0;
}
