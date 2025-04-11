#include <math.h>
#include <stdio.h>

/// This is the trapezoidal integration rule

double f(double x) {
  return exp(x);
}

#define N 30

int main() {
  int a;
  int b;

  printf("Enter range for integration (a b): ");
  scanf("%d %d", &a, &b);

  double h = (double)(b - a) / (double)N;

  double result = 0;

  for (int i = a + h; i < b - h; i += h) {
    result += 2 * f(i);
  }

  result += f(a);
  result += f(b);

  result *= h / 2;

  printf("Integration result is: %lf\n", result);
}
