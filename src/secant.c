#include <math.h>
#include <stdio.h>

#define f(x) (cos(x) - x * exp(x))
#define PRECISION 10e-6

double secant_method(double x0, double x1) {
  double x2;
  int    count = 1;

  do {
    if (f(x0) == f(x1)) {
      return 0;
    }

    x2 = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0));
    x0 = x1;
    x1 = x2;

    if (count > 500) {
      break;
    }

    count++;

    printf("Estimated root is %lf with function value %lf\n", x2, f(x2));
  } while (fabs(f(x2)) > PRECISION);

  return x2;
}

int main() {
  double x0, x1;
  printf("Enter the intial values: ");
  scanf("%lf %lf", &x0, &x1);

  double x2 = secant_method(x0, x1);
  printf("Solution is %lf\n", x2);

  return 0;
}
