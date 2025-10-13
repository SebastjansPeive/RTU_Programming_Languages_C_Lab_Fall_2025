// week5_task2_struct_save_load.c
// Task 2: Save and load structured records from a file
// Week 5 – Files & Modular Programming

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
  char name[MAX_NAME_LEN];
  int age;
  float gpa;
} Student;

// Function prototypes
void save_student(Student s, const char *filename);
Student load_student(const char *filename);

int main(void) {
  Student s1;
  strcpy(s1.name, "Alice");
  s1.age = 21;
  s1.gpa = 3.75f;

  const char *filename = "student.txt";

  save_student(s1, filename);
  Student sNew = load_student(filename);
  printf("New student's name: %s, age: %d, gpa: %.2f\n", sNew.name, sNew.age,
         sNew.gpa);

  return 0;
}

// Open file for writing, check errors, write fields, then close file
void save_student(Student s, const char *filename) {
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }
  fprintf(fp, "%s\n%d\n%f", s.name, s.age, s.gpa);
  fclose(fp);
}

// Open file for reading, check errors, read fields, then close file
Student load_student(const char *filename) {
  Student s;
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return s;
  }
  fscanf(fp, "%s\n%d\n%f", &s.name, &s.age, &s.gpa);
  fclose(fp);
  return s;
}
