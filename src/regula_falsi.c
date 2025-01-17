#include <math.h>
#include <stdio.h>

#define f(x) cos(x) - x *exp(x)
#define PRECISION 10e-6

double regula_falsi_method(double x0, double x1) {
  double x2, f0, f1, f2;

  f0 = f(x0);
  f1 = f(x1);

  if (f0 * f1 > 0) {
    printf("NOTE: There is probably no root/more than one root in this range, don't trust the "
           "answers!\n\n");
  }

  do {
    x2 = (f1 * x0 - f0 * x1) / (f1 - f0);
    f2 = f(x2);

    if (f0 * f2 < 0) {
      x1 = x2;
      f1 = f(x1);
    } else {
      x0 = x2;
      f0 = f(x0);
    }
    printf("Estimated root is %lf with function value %lf\n", x2, f2);
  } while (fabs(f2) > PRECISION);

  return x2;
}

int main() {
  double x0, x1;
  printf("Enter the values for x0 and x1: ");
  scanf("%lf %lf", &x0, &x1);

  double x2 = regula_falsi_method(x0, x1);

  printf("Root between %lf and %lf for f(x): %lf\n", x0, x1, x2);

  return 0;
}
