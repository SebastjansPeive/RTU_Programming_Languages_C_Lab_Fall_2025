#include <stdio.h>

/*
    Task:
    Write a function `long long factorial(int n)` that computes n!
    using a loop (not recursion).

    In main():
      - Ask user for an integer n
      - If n is negative, print an error and exit
      - Otherwise, call factorial and print the result
*/

long long factorial(int n) {
  long long fact = 1;
  while (n != 1) {
    fact *= n;
    n--;
  }
  return fact;
}

int main(void) {
  int n;

  printf("Enter a non-negative integer n: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Error: variable n must be positive. Current n value: %d\n", n);
  } else {
    printf("Factorial of %d: %lld\n", n, factorial(n));
  }

  return 0;
}
