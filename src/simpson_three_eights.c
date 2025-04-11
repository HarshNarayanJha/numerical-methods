#include <math.h>
#include <stdio.h>

/// This is the simpson's 3/8th integration rule

double f(double x) {
  return exp(x);
}

#define N 30
double simpson_three_eight(int a, int b) {
  int n = (N % 2 == 0) ? N + 1 : N;

  double h = (double)(b - a) / (double)n;

  double result = 0;
  for (int i = 1; i < n - 1; i++) {
    if (i % 3 == 0)
      result += 2 * f(a + h * i);
    else
      result += 3 * f(a + h * i);
  }

  result += f(a);
  result += f(b);

  result *= 3 * h / 8;

  return result;
}

int main() {
  int a;
  int b;

  printf("Enter range for integration (a b): ");
  scanf("%d %d", &a, &b);

  double res_simp3 = simpson_three_eight(a, b);

  printf("Integration results are:\n");
  printf("Simpson Three-Eight: %lf\n", res_simp3);
}
