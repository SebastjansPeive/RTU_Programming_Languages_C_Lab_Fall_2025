/*
 * week4_1_dynamic_array.c
 * Author: Sebastjans Peive
 * Student ID: 241ADC003
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Students should allocate memory for an integer array, fill it with data,
 *   compute something (e.g., average), and then free the memory.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  int *arr = NULL;

  printf("Enter number of elements: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid size.\n");
    return 1;
  }

  arr = malloc(n * sizeof(int));
  printf("Enter %d integers: ", n);
  if (arr == NULL) {
    printf("Error: memory allocation failed.");
  } else {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
      sum += arr[i];
    }
    double avg = sum / n;
    printf("Sum of all elements in array: %d\n", sum);
    printf("Average of all elements in array: %.2f\n", avg);
    free(arr);
  }

  return 0;
}
