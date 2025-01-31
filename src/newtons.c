#include <math.h>
#include <stdio.h>

#define f(x) (cos(x) - x * exp(x))
#define fp(x) (-sin(x) - x * exp(x) - exp(x))
#define PRECISION 10e-6

double newtons_method(double x) {
  if (fp(x) == 0) {
    return 0;
  }

  double h = f(x) / fp(x);

  do {
    if (fp(x) == 0) {
      return 0;
    }

    h = f(x) / fp(x);

    x = x - h;

    printf("Estimated root is %lf with function value %lf\n", x, f(x));
  } while (fabs(h) > PRECISION);

  return x;
}

int main() {
  double x;
  printf("Enter the value for x: ");
  scanf("%lf", &x);

  double x2 = newtons_method(x);
  printf("Solution is %lf", x2);

  return 0;
}
