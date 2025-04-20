#include <stdio.h>

/// This is Euler's method for approximating ordinary differential equations.

// dy/dx = x + 2y
// y(0) = 0
double yp(double x, double y) {
  return x + 2 * y;
}

int main() {
  double x0, y0, h, xn;

  printf("This is Euler's method\n");
  printf("Initial condition (x0 y0): ");
  scanf("%lf %lf", &x0, &y0);

  printf("Step size (h): ");
  scanf("%lf", &h);

  printf("Evaluate f at x =  ");
  scanf("%lf", &xn);

  double x = x0, y = y0;

  while (x != xn) {
    double yn = y + h * yp(x, y);
    printf("x = %lf, y = %lf\n", x, y);
    x += h;
    y = yn;
  }

  printf("Final value of y: %lf at x = %lf\n", y, x);

  return 0;
}
