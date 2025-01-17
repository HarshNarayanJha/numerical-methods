#include <math.h>
#include <stdio.h>

#define f(x) pow(x, 5) - 5 * x + 3
#define PRECISION 10e-6

double bisection_method(double x0, double x1) {
  double x2, f0, f1, f2;

  f0 = f(x0);
  f1 = f(x1);

  if (f0 * f1 > 0) {
    printf("NOTE: There is probably no root/more than one root in this range, don't trust the "
           "answers!\n\n");
  }

  do {
    x2 = (x0 + x1) / 2;
    f2 = f(x2);

    if (f0 * f2 < 0) {
      x1 = x2;
      f1 = f(x1);
    } else {
      x0 = x2;
      f0 = f(x0);
    }
  } while (fabs(x1 - x0) > PRECISION);

  return x2;
}

int main() {
  double x0, x1;
  printf("Enter the values for x0 and x1: ");
  scanf("%lf %lf", &x0, &x1);

  double x2 = bisection_method(x0, x1);

  printf("Root between %lf and %lf for f(x): %lf\n", x0, x1, x2);
}
