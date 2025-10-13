// week5_task1_file_io.c
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp;
  char filename[100];
  printf("Enter name of the file: ");
  scanf("%s.txt", &filename);
  char line[256];
  fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }
  fprintf(fp, "Line 1\n");
  fprintf(fp, "New text line\n");
  fclose(fp);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }
  int num = 0;
  while (fgets(line, sizeof(line), fp) != NULL) {
    printf("Read: %s", line);
    num++;
  }
  fclose(fp);
  printf("Number of lines: %d\n", num);

  return 0;
}
