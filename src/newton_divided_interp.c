#include <stdio.h>

#define MAX_POINTS 100

int main() {
  int n;

  double x[MAX_POINTS], y[MAX_POINTS], p[MAX_POINTS];

  printf("This is Newton's Divided Difference Interpolation!\n");
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

  double res = y[0], f1 = 1, f2 = 0;
  int j = 1;

  do {
    for (int i = 0; i < n - 1; i++) {
      p[i] = (y[i + 1] - y[i]) / (x[i + j] - x[i]);
      y[i] = p[i];
    }

    f1 = 1;
    for (int i = 0; i < n; i++) {
      f1 *= (xn - x[i]);
    }
    f2 += f1 * y[0];

    n--;
    j++;

  } while (n != 1);

  res += f2;

  printf("The interpolated value at x = %.2lf is %.2lf\n", xn, res);
  return 0;
}
