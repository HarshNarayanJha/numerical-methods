#include <math.h>
#include <stdio.h>

/// This is the simpson 1/3rd integration rule

double f(double x) {
  return exp(x);
}

#define N 30

double simpson_one_third(int a, int b) {
  int n = (N % 2 == 0) ? N + 1 : N;

  double h = (double)(b - a) / (double)n;

  double result = 0;
  for (int i = 1; i < n - 1; i += 2) {
    result += 4 * f(a + h * i);
  }

  for (int i = 2; i < n - 2; i += 2) {
    result += 2 * f(a + h * i);
  }

  result += f(a);
  result += f(b);

  result *= h / 3.0;

  return result;
}

int main() {
  int a;
  int b;

  printf("Enter range for integration (a b): ");
  scanf("%d %d", &a, &b);

  double res_simp1 = simpson_one_third(a, b);

  printf("Integration results are:\n");
  printf("Simpson One-Third: %lf\n", res_simp1);
}
