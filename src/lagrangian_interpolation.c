#include <stdio.h>

#define MAX_POINTS 100

int main() {
  int n;

  double x[MAX_POINTS], y[MAX_POINTS];

  printf("This is Lagrangian Interpolation!\n");
  printf("How many data points? ");
  scanf("%d", &n);

  if (n <= 1 || n > MAX_POINTS) {
    printf("Invalid number of points (must be between 2 and %d)\n", MAX_POINTS);
    return 1;
  }

  for (int i = 0; i < n; i++) {
    printf("Enter x%d and y%d: ", i, i);
    scanf("%lf %lf", &x[i], &y[i]);
  }

  double xn;
  printf("At what point to evaluate f(x)? ");
  scanf("%lf", &xn);

  double res = 0;

  for (int i = 0; i < n; i++) {
    double term = y[i];

    for (int j = 0; j < n; j++) {
      if (i != j) {
        // Check for division by zero
        if (x[i] == x[j]) {
          printf("Error: Duplicate x values not allowed\n");
          return 1;
        }
        term *= (xn - x[j]) / (x[i] - x[j]);
      }
    }

    res += term;
  }

  printf("The interpolated value at x = %.2lf is %.2lf\n", xn, res);
  return 0;
}
